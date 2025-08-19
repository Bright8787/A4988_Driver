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
#define ARR_VAL 4000

static void A4988_GPIO_Config(A4988_config_t *A4988_config);
static void A4988_TIM_Config(A4988_config_t *A4988_config);
static void A4988_TIM_Init();

static float clk_period = 1.25e-6f;
static uint32_t arr = 1;
static uint32_t counter = 1;
static uint8_t status = 1;
static uint32_t ccr = 1;

// Still have to tune parameter
volatile uint32_t steps_done = 0, steps_target = 0;
volatile float f, a, j;			  // Hz, Hz/s, Hz/s^2 (i.e., steps/s, steps/s^2, steps/s^3)
volatile float f0 = 50;			  // start frequency this should make aar to 16000 -> 20 ms
volatile float f_max = 200.0f;	  // target cruise  5 ms
volatile float a_max = 1000.0f;	  // max accel
volatile float j_max = 100000.0f; // max jerk
volatile float T;				  // current period (microsecs)
volatile uint8_t phase = 0;		  // 7 Phase

TIM_Handle_t TIM_handles[MAX_TIMERS];

void A4988_init(A4988_config_t *A4988_config)
{

	// Set address of each timer in TIM_handles array
	A4988_TIM_Init();
	A4988_GPIO_Config(A4988_config);
	A4988_TIM_Config(A4988_config);
	GPIO_WriteToOutputPin(A4988_config->dir_port, A4988_config->dir_pin, HIGH);

	GPIO_WriteToOutputPin(A4988_config->dir_port, A4988_config->dir_pin, HIGH);
}

static void A4988_GPIO_Config(A4988_config_t *A4988_config)
{

	GPIO_Handle_t step, dir;
	memset(&dir, 0, sizeof(dir));
	memset(&step, 0, sizeof(step));

	// Set up Step Port
	step.pGPIOx = A4988_config->step_port;
	step.GPIO_PinConfig.GPIO_PinNumber = A4988_config->step_pin;
	step.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_ALTF;
	step.GPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_FAST;
	step.GPIO_PinConfig.GPIO_PinPuPdControl = GPIO_PUPD_NO_PUPD;
	step.GPIO_PinConfig.GPIO_PinOPType = GPIO_OUTPUT_TYPE_PP;			  // PP for normal usage
	step.GPIO_PinConfig.GPIO_PinAltFunMode = A4988_config->step_alt_mode; // No Alternate Funciton is used
	GPIO_Init(&step);

	// Set up dir Port
	dir.pGPIOx = A4988_config->dir_port;
	dir.GPIO_PinConfig.GPIO_PinNumber = A4988_config->dir_pin;
	dir.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_OUTPUT;
	dir.GPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_FAST;
	dir.GPIO_PinConfig.GPIO_PinPuPdControl = GPIO_PUPD_NO_PUPD;
	dir.GPIO_PinConfig.GPIO_PinOPType = GPIO_OUTPUT_TYPE_PP;			// PP for normal usage
	dir.GPIO_PinConfig.GPIO_PinAltFunMode = A4988_config->dir_alt_mode; // No Alternate Funciton is used
	GPIO_Init(&dir);
}

static void A4988_TIM_Config(A4988_config_t *A4988_config)
{

	TIM_Handle_t PWMx;
	memset(&PWMx, 0, sizeof(PWMx));

	PWMx.pTIMx = A4988_config->step_timer_port;
	PWMx.TIMx_PinConfig.TIM_Prescaler = 8;
	PWMx.TIMx_PinConfig.TIM_CountDir = UPWARDS;
	PWMx.TIMx_PinConfig.TIM_Channel = A4988_config->step_channel;
	;
	PWMx.TIMx_PinConfig.TIM_Mode = TIMx_MODE_COMPARE;
	PWMx.TIMx_PinConfig.TIM_CMP_Mode = TIMx_COMPARE_MODE_PWM1;
	PWMx.TIMx_PinConfig.TIM_ARR = 10000; // 1 Period = 1/4MHz = 0.25 microSecs -> 1000 * 0.25 microSecs = 250 microSecs
	PWMx.TIMx_PinConfig.TIM_CCR = 5000;	 // Duty Cycle 50%

	TIM_Init(&PWMx);
	TIM_InterruptEnable(&PWMx, ENABLE);
	TIM_IRQInterruptConfig(A4988_config->step_IRQ_number, ENABLE);
}

static void A4988_TIM_Init()
{

	memset(&TIM_handles[0], 0, sizeof(TIM_Handle_t));
	TIM_handles[0].pTIMx = pTIM2;

	memset(&TIM_handles[1], 0, sizeof(TIM_Handle_t));
	TIM_handles[1].pTIMx = pTIM3;

	memset(&TIM_handles[2], 0, sizeof(TIM_Handle_t));
	TIM_handles[2].pTIMx = pTIM4;

	memset(&TIM_handles[3], 0, sizeof(TIM_Handle_t));
	TIM_handles[3].pTIMx = pTIM5;
}

static inline void set_phase(uint8_t p)
{
	phase = p;
	// like state machine 7 phases
	switch (p)
	{
	case 0:
		j = +j_max;
		break; // jerk up
	case 1:
		j = 0.0f;
		break; // accel hold
	case 2:
		j = -j_max;
		break; // jerk down to a=0
	case 3:
		j = 0.0f;
		a = 0.0f; // cruise
		f = f_max;
		T = 1.0f / f;
		break;
	case 4:
		j = -j_max;
		break; // jerk down (start decel)
	case 5:
		j = 0.0f;
		break; // accel hold negative
	case 6:
		j = +j_max;
		break; // jerk up back to a=0
	}
}

void A4988_move_Step(uint32_t steps, uint32_t dir, TIM_Handle_t pTIMHandle)
{
	// Enable Counter and ISR

	counter = 0;
	step = steps;
	arr = 1000;
	ccr = 500;
	pTIMHandle.pTIMx->CR1 |= (1 << TIM_CR1_CEN_POS);
	while (counter < steps)
		;
	// Disable Counter
	pTIMHandle.pTIMx->CR1 &= ~(1 << TIM_CR1_CEN_POS);
}

void TIM2_IRQHandler(void)
{
	TIMx_EV_IRQHandling(&TIM_handles[0]);
}

void TIM3_IRQHandler(void)
{
	TIMx_EV_IRQHandling(&TIM_handles[1]);
}

void TIM4_IRQHandler(void)
{
	TIMx_EV_IRQHandling(&TIM_handles[2]);
}

void TIM5_IRQHandler(void)
{

	TIMx_EV_IRQHandling(&TIM_handles[3]);
}

void TIM_ApplicationEventCallback(TIM_Handle_t *pTIMHandle, uint8_t AppEv)
{
	if (AppEv == TIMx_EV_UIF)
	{
		//		Update the frequency of toggling
		//		Update CCR register to change pulse width (duty cycle) or timing
		counter++;
		//		if(status == 1){
		//			arr -= 10;
		//			// Has to come up with formula to increase or decrease arr
		//		}
		//		else{
		//			arr += 10;
		//		}
		//
		//		if (counter >= step){ // High frequency pulse
		//		    	status *= -1;
		//		}

		// Simple phase logic (acceleration side)
		if (phase == 0 && a >= a_max)
		{
			a = a_max;
			set_phase(1);
		}
		if (phase == 1 && f >= f_max)
		{
			set_phase(2);
		} // reached cruise speed goals
		if (phase == 2 && a <= 0.0f)
		{
			a = 0.0f;
			set_phase(3);
		} // ready to cruise

		// Brake check: when to start decel (use padded trapezoid distance)
		float stop_dist = (f * f) / (2.0f * a_max) * 1.15f; // steps  s =  V^2/2a 1.15 is just safety factor
		if (remaining <= (uint32_t)stop_dist)
		{
			if (phase < 4)
				set_phase(4); // enter deceleration phase
		}

		// Decel side transitions (mirror)
		if (phase == 4 && a <= -a_max)
		{
			a = -a_max;
			set_phase(5);
		}
		if (phase == 5 && f <= f0)
		{
			set_phase(6);
		} // target end speed ~ f0 (or 0)
		if (phase == 6 && a >= 0.0f)
		{
			a = 0.0f; /* final phase */
		}

		// --- Jerk-limited integration per step ---
		// T seconds have just elapsed between steps (approximately).
		// Integrate jerk → accel, accel → frequency:

		a += j * T; // Area of square

		// clamp accel to bounds (prevents numeric drift)
		if (a > a_max)
			a = a_max;
		if (a < -a_max)
			a = -a_max;

		f += a * T;
		if (f < 1.0f)
			f = 1.0f; // avoid div-by-zero/too slow

		// Period for next step
		T = 1.0f / f; // second

		arr = (uint32_t)(T / clk_period + 0.5f) - 1u; // tick = 1 µs  f/clk_period -1
		pTIMHandle->pTIMx->ARR = arr;
		pTIMHandle->pTIMx->CCR1 = arr / 2;
	}
}

//		Update the frequency of toggling
//		Update CCR register to change pulse width (duty cycle) or timing
//		counter++;
//		if(status == 1){
//			arr -= 0.05*ARR_VAL/2;
//			// Has to come up with formula to increase or decrease arr
//		}
//		else{
//			arr += 100;
//		}
//
//		if (counter >= step/2){ // High frequency pulse
//		    	status = 0;
//		}
//
//		pTIMHandle->pTIMx->ARR = arr;
//		// Make sure duty cycle is still 50 percent
//		pTIMHandle->pTIMx->CCR1 = arr/2;
