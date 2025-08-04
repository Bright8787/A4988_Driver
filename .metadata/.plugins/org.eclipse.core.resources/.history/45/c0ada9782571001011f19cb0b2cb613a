/*
 * stm32f446xx_Timer_driver.c
 *
 *  Created on: Aug 3, 2025
 *      Author: bright
 */
#include "stm32f446xx_Timer_driver.h"

void TIM_Init(Timer_Handle_t *pTIMHandle){

	TIM_PeriClockControl(pTIMHandle->pTIMx,ENABLE);

	// Set Prescaler - HSI SysCLK is 16 MHZ
	pTIMHandle->pTIMx->PSC = pTIMHandle->TIMx_PinConfig.TIM_Prescaler;
	// Set the count direction
	pTIMHandle->pTIMx->PSC = pTIMHandle->TIMx_PinConfig.TIM_CountDirection;
	// Set ARR corresponded to the given period
	// ARR = Given Periode * (SysCLK/Prescaler)
	pTIMHandle->pTIMx->ARR = (pTIMHandle->TIMx_PinConfig.TIM_Period * (HSI_CLK/pTIMHandle->TIMx_PinConfig.TIM_Prescaler)) - 1 ;


}

/*Enable Clock of the given Timer*/
void TIM_PeriClockControl(Timer_RegDef_t *pTIMx, uint8_t ENorDI){

	if(ENorDI == ENABLE){

		if(pTIMx == pTIM2){
			TIM2_PCLK_EN()();
		}
		else if(pTIMx == pTIM3){
			TIM3_PCLK_EN()();
		}
		else if(pTIMx == pTIM4){
			TIM4_PCLK_EN()();
		}
		else if(pTIMx == pTIM5){
			TIM5_PCLK_EN()();
		}

	}
	else{
		if(pTIMx == pTIM2){
			TIM2_PCLK_DI();
		}
		else if(pTIMx == pTIM3){
			TIM3_PCLK_DI();
		}
		else if(pTIMx == pTIM4){
			TIM4_PCLK_DI();
		}
		else if(pTIMx == pTIM5){
			TIM5_PCLK_DI();
		}

	}
}

/*Enable Clock of the given Timer*/
void TIM_SetChannel(Timer_Handle_t *pTIMHandle){


		if(pTIMHandle->TIMx_PinConfig.TIM_Channel == TIMx_CH1){
			// CCR1 = Set DutyCycle. Given the DutyCycle in Percent: (TIM_DutyCycle/100) * ARR
			pTIMHandle->pTIMx->CCR1 = (pTIMHandle->TIMx_PinConfig.TIM_DutyCycle/100) * pTIMHandle->pTIMx->ARR;
			pTIMHandle->pTIMx->CCMR1 &= ~(6 << TIM_CCMR1_OC1M_POS);
			pTIMHandle->pTIMx->CCMR1 |= ( pTIMHandle->TIMx_PinConfig.TIM_Mode << TIM_CCMR1_OC1M_POS);
			pTIMHandle->pTIMx->CCMR1 |= ( 1 << TIM_CCMR1_OC1PE_POS);
		}
		else if(pTIMHandle->TIMx_PinConfig.TIM_Channel == TIMx_CH2){
			// CCR2 = Set DutyCycle. Given the DutyCycle in Percent: (TIM_DutyCycle/100) * ARR
			pTIMHandle->pTIMx->CCR2 = (pTIMHandle->TIMx_PinConfig.TIM_DutyCycle/100) * pTIMHandle->pTIMx->ARR;
			pTIMHandle->pTIMx->CCMR1 &= ~(6 << TIM_CCMR1_OC2M_POS);
			pTIMHandle->pTIMx->CCMR1 |= ( pTIMHandle->TIMx_PinConfig.TIM_Mode << TIM_CCMR1_OC2M_POS);
			pTIMHandle->pTIMx->CCMR1 |= ( 1 << TIM_CCMR1_OC2PE_POS);
		}
		else if(pTIMHandle->TIMx_PinConfig.TIM_Channel == TIMx_CH3){
			// CCR3 = Set DutyCycle. Given the DutyCycle in Percent: (TIM_DutyCycle/100) * ARR
			pTIMHandle->pTIMx->CCR3 = (pTIMHandle->TIMx_PinConfig.TIM_DutyCycle/100) * pTIMHandle->pTIMx->ARR;
			pTIMHandle->pTIMx->CCMR2 &= ~(6 << TIM_CCMR2_OC3M_POS);
			pTIMHandle->pTIMx->CCMR2 |= ( pTIMHandle->TIMx_PinConfig.TIM_Mode << TIM_CCMR2_OC3M_POS);
			pTIMHandle->pTIMx->CCMR2 |= ( 1 << TIM_CCMR2_OC3PE_POS);
		}
		else if(pTIMHandle->TIMx_PinConfig.TIM_Channel== TIMx_CH4){
			// CCR4 = Set DutyCycle. Given the DutyCycle in Percent: (TIM_DutyCycle/100) * ARR
			pTIMHandle->pTIMx->CCR4 = (pTIMHandle->TIMx_PinConfig.TIM_DutyCycle/100) * pTIMHandle->pTIMx->ARR;
			pTIMHandle->pTIMx->CCMR2 &= ~(6 << TIM_CCMR2_OC4M_POS);
			pTIMHandle->pTIMx->CCMR2 |= (pTIMHandle->TIMx_PinConfig.TIM_Mode << TIM_CCMR2_OC4M_POS);
			pTIMHandle->pTIMx->CCMR2 |= ( 1 << TIM_CCMR2_OC3PE_POS);
		}


}
