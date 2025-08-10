/*
 * StepperMotor_A4988.c
 *
 *  Created on: Aug 2, 2025
 *      Author: bright
 */

#include "StepperMotor_A4988.h"
#include "stddef.h"
#include "string.h"


#define MAX_TIMERS 4
static void A4988_GPIO_Config(A4988_config_t *A4988_config);
static void A4988_TIM_Config(A4988_config_t *A4988_config);
static void A4988_TIM_Init(A4988_config_t *A4988_config);

TIM_Handle_t TIM_handles[MAX_TIMERS];


void A4988_init(A4988_config_t *A4988_config){

	// Set address of each timer in TIM_handles array
	A4988_TIM_Init();
	A4988_GPIO_config(A4988_config);
	A4988_TIM_config(A4988_config);

}

static void A4988_GPIO_Config(A4988_config_t *A4988_config){


	GPIO_Handle_t step,dir;
	memset(&dir,0,sizeof(dir));
	memset(&step,0,sizeof(step));


	//Set up Step Port
	step.pGPIOx = A4988_config->step_port;
	step.GPIO_PinConfig.GPIO_PinNumber = A4988_config->step_pin;
	step.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_OUTPUT;
	step.GPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_FAST;
	step.GPIO_PinConfig.GPIO_PinOPType = GPIO_OUTPUT_TYPE_PP ; // PP for normal usage
	step.GPIO_PinConfig.GPIO_PinAltFunMode = A4988_config->step_alt_mode; // No Alternate Funciton is used
	GPIO_Init(&step);


	//Set up dir Port
	dir.pGPIOx = A4988_config->dir_port;
	dir.GPIO_PinConfig.GPIO_PinNumber = A4988_config->dir_pin;
	dir.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_OUTPUT;
	dir.GPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_FAST;
	dir.GPIO_PinConfig.GPIO_PinOPType = GPIO_OUTPUT_TYPE_PP ; // PP for normal usage
	dir.GPIO_PinConfig.GPIO_PinAltFunMode = A4988_config->dir_alt_mode; // No Alternate Funciton is used
	GPIO_Init(&dir);

}

static void A4988_TIM_Config(A4988_config_t *A4988_config){

	TIM_Handle_t PWMx;
	memset(&PWMx,0,sizeof(PWMx));

	PWMx.pTIMx = A4988_config->step_timer;
	PWMx.TIMx_PinConfig.TIM_Prescaler = 4;
	PWMx.TIMx_PinConfig.TIM_CountDir = UPWARDS;
	PWMx.TIMx_PinConfig.TIM_Channel = A4988_config->step_channel;;
	PWMx.TIMx_PinConfig.TIM_Mode = TIMx_MODE_COMPARE;
	PWMx.TIMx_PinConfig.TIM_CMP_Mode = TIMx_COMPARE_MODE_PWM1;
	PWMx.TIMx_PinConfig.TIM_ARR = 1000; // 1 Period = 1/4MHz = 0.25 microSecs -> 1000 * 0.25 microSecs = 250 microSecs
	PWMx.TIMx_PinConfig.TIM_CCR = PWMx.TIMx_PinConfig.TIM_ARR/2; // Duty Cycle 50%

	TIM_Init(&PWMx);
	TIM_InterruptEnable(&PWMx,ENABLE);
	TIM_IRQInterruptConfig(A4988_config->step_IRQ_number,ENABLE);

}

static void A4988_TIM_Init(){

    memset(&TIM_handles[0], 0, sizeof(TIM_Handle_t));
    TIM_handles[0].pTIMx = TIM2;

    memset(&TIM_handles[1], 0, sizeof(TIM_Handle_t));
    TIM_handles[1].pTIMx = TIM3;

    memset(&TIM_handles[2], 0, sizeof(TIM_Handle_t));
    TIM_handles[2].pTIMx = TIM4;

    memset(&TIM_handles[3], 0, sizeof(TIM_Handle_t));
    TIM_handles[3].pTIMx = TIM5;

}
void A4988_move_Step(uint32_t steps, uint32_t dir, TIM_Handle_t pTIMHandle){
	// Enable Counter and ISR
	pTIMHandle.pTIMx->CR1  |= (1 << TIM_CR1_CEN_POS);
	TIM_InterruptEnable(&pTIMHandle,ENABLE);

	// Disable Counter
	pTIMHandle.pTIMx->CR1  &= ~(1 << TIM_CR1_CEN_POS);
	TIM_InterruptEnable(&pTIMHandle,DISABLE);

}

void TIM2_IRQHandler(void){
	TIMx_EV_IRQHandling(&TIM_handles[0]);

}

void TIM3_IRQHandler(void){
	TIMx_EV_IRQHandling(&TIM_handles[1]);

}

void TIM4_IRQHandler(void){
	TIMx_EV_IRQHandling(&TIM_handles[2]);

}

void TIM5_IRQHandler(void){

	TIMx_EV_IRQHandling(&TIM_handles[3]);
}



