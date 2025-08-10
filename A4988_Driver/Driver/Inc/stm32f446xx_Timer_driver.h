/*
 * stm32f446xx_Timer_driver.h
 *
 *  Created on: Aug 3, 2025
 *      Author: bright
 */

#ifndef DRIVER_INC_STM32F446XX_TIMER_DRIVER_H_
#define DRIVER_INC_STM32F446XX_TIMER_DRIVER_H_


#include "../../Driver/Inc/stm32f446xx.h"

#define HIGH 1
#define LOW 0


#define TIMx_CR1_DIR_UPWARDS 1
#define TIMx_CR1_DIR_DOWNWARDS 0


#define TIMx_CH1 1
#define TIMx_CH2 2
#define TIMx_CH3 3
#define TIMx_CH4 4

#define TIMx_MODE_COMPARE 0
#define TIMx_MODE_CAPTURE 1

#define TIMx_COMPARE_MODE_FROZEN 0
#define TIMx_COMPARE_MODE_SETACTIVE 1
#define TIMx_COMPARE_MODE_SETINACTIVE 2
#define TIMx_COMPARE_MODE_TOGGLE 3
#define TIMx_COMPARE_MODE_FORCEACTIVE 4
#define TIMx_COMPARE_MODE_FORCEINACTIVE 5
#define TIMx_COMPARE_MODE_PWM1 6
#define TIMx_COMPARE_MODE_PWM2 7


#define TIMx_EV_UIF 0
#define TIMx_EV_CC1IF 1
#define TIMx_EV_CC2IF 2
#define TIMx_EV_CC3IF 3
#define TIMx_EV_CC4IF 4
#define TIMx_EV_TIF 5
#define TIMx_ER_CC1OF 6
#define TIMx_ER_CC2OF 7
#define TIMx_ER_CC3OF 8
#define TIMx_ER_CC4OF 9

typedef struct{
	uint32_t TIM_Prescaler;
	uint32_t TIM_ARR; // Autor reload register
	uint32_t TIM_CCR; // Compare register
	uint8_t TIM_CountDir; // Upwards or Downwards
	uint8_t TIM_Channel;
	uint8_t TIM_Mode; // Capture Mode or Compare Mode
	uint8_t TIM_CMP_Mode; // Mode in Compare Mode

}TIM_PinConfig_t;

typedef struct{
	TIM_RegDef_t *pTIMx; /*Pointer to hold the base address of the TIM peripheral*/
	TIM_PinConfig_t TIMx_PinConfig;
}TIM_Handle_t;

/*TIMx API Supported */
void TIM_Init(TIM_Handle_t *pTIMHandle);
void TIM_PeriClockControl(TIM_RegDef_t *pTIMx, uint8_t ENorDI);
void TIM_IRQInterruptConfig(uint8_t IRQNumber, uint8_t ENorDI);
void TIM_InterruptEnable(TIM_Handle_t *pTIMHandle,uint8_t ENorDI);
/*Event Handling*/
void TIMx_EV_IRQHandling(TIM_Handle_t *pTIMHandle);

void TIM_ApplicationEventCallback(TIM_Handle_t *pTIMHandle, uint8_t AppEv);

#endif /* DRIVER_INC_STM32F446XX_TIMER_DRIVER_H_ */
