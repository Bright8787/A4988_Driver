/*
 * stm32f446xx_Timer_driver.c
 *
 *  Created on: Aug 3, 2025
 *      Author: bright
 */
#include "stm32f446xx_Timer_driver.h"


void static TIM_SetCompareModeChannel(TIM_Handle_t *pTIMHandle);
void TIM_Init(TIM_Handle_t *pTIMHandle){

	TIM_PeriClockControl(pTIMHandle->pTIMx,ENABLE);
	// Set Prescaler - HSI SysCLK is 16 MHZ
	pTIMHandle->pTIMx->PSC = pTIMHandle->TIMx_PinConfig.TIM_Prescaler - 1;
	// Set ARR corresponded to the given period
	// ARR = Given Periode * (SysCLK/Prescaler)
	pTIMHandle->pTIMx->ARR = (pTIMHandle->TIMx_PinConfig.TIM_ARR) - 1 ;
	// Enable Capture/Compare Mode
	pTIMHandle->pTIMx->CCER  |= (1 << 4 * (pTIMHandle->TIMx_PinConfig.TIM_Channel-1));
	// Set Dir default is countup
	pTIMHandle->pTIMx->CR1  &= ~(1 << TIM_CR1_DIR_POS);
	if(pTIMHandle->TIMx_PinConfig.TIM_CountDir== TIMx_CR1_DIR_UPWARDS){
		pTIMHandle->pTIMx->CR1  |= (1 << TIM_CR1_DIR_POS);
	}

	if(pTIMHandle->TIMx_PinConfig.TIM_Mode == TIMx_MODE_COMPARE){
		//Set Compare mode
		TIM_SetCompareModeChannel(pTIMHandle);
	}else{
		//Set Capture mode
	}


}

/*Enable Clock of the given Timer*/
void TIM_PeriClockControl(TIM_RegDef_t *pTIMx, uint8_t ENorDI){

	if(ENorDI == ENABLE){

		if(pTIMx == pTIM2){
			TIM2_PCLK_EN();
		}
		else if(pTIMx == pTIM3){
			TIM3_PCLK_EN();
		}
		else if(pTIMx == pTIM4){
			TIM4_PCLK_EN();
		}
		else if(pTIMx == pTIM5){
			TIM5_PCLK_EN();
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
void TIM_SetCompareModeChannel(TIM_Handle_t *pTIMHandle){

		if(pTIMHandle->TIMx_PinConfig.TIM_Channel == TIMx_CH1){
			// CCR1 = Set DutyCycle. Given the DutyCycle in Percent: (TIM_DutyCycle/100) * ARR
			pTIMHandle->pTIMx->CCR1 = pTIMHandle->TIMx_PinConfig.TIM_CCR;
			//Clear TIM_CCMR1_OC1M_POS
			pTIMHandle->pTIMx->CCMR1 &= ~(6 << TIM_CCMR1_OC1M_POS);
			pTIMHandle->pTIMx->CCMR1 |= ( pTIMHandle->TIMx_PinConfig.TIM_CMP_Mode << TIM_CCMR1_OC1M_POS);
			//Pre-load Buffer Enable
			pTIMHandle->pTIMx->CCMR1 |= ( 1 << TIM_CCMR1_OC1PE_POS);

		}
		else if(pTIMHandle->TIMx_PinConfig.TIM_Channel == TIMx_CH2){
			// CCR2 = Set DutyCycle. Given the DutyCycle in Percent: (TIM_DutyCycle/100) * ARR
			pTIMHandle->pTIMx->CCR2 = pTIMHandle->TIMx_PinConfig.TIM_CCR;
			//Clear TIM_CCMR1_OC2M_POS
			pTIMHandle->pTIMx->CCMR1 &= ~(6 << TIM_CCMR1_OC2M_POS);
			//Set TIM_CCMR1_OC2M_POS MODE
			pTIMHandle->pTIMx->CCMR1 |= ( pTIMHandle->TIMx_PinConfig.TIM_CMP_Mode << TIM_CCMR1_OC2M_POS);
			pTIMHandle->pTIMx->CCMR1 |= ( 1 << TIM_CCMR1_OC2PE_POS);

		}
		else if(pTIMHandle->TIMx_PinConfig.TIM_Channel == TIMx_CH3){
			// CCR3 = Set DutyCycle. Given the DutyCycle in Percent: (TIM_DutyCycle/100) * ARR
			pTIMHandle->pTIMx->CCR3 = pTIMHandle->TIMx_PinConfig.TIM_CCR;
			//Clear TIM_CCMR2_OC3M_POS
			pTIMHandle->pTIMx->CCMR2 &= ~(6 << TIM_CCMR2_OC3M_POS);
			//Set TIM_CCMR2_OC3M_POS MODE
			pTIMHandle->pTIMx->CCMR2 |= ( pTIMHandle->TIMx_PinConfig.TIM_CMP_Mode << TIM_CCMR2_OC3M_POS);
			pTIMHandle->pTIMx->CCMR2 |= ( 1 << TIM_CCMR2_OC3PE_POS);

		}
		else if(pTIMHandle->TIMx_PinConfig.TIM_Channel == TIMx_CH4){
			// CCR4 = Set DutyCycle. Given the DutyCycle in Percent: (TIM_DutyCycle/100) * ARR
			pTIMHandle->pTIMx->CCR4 = pTIMHandle->TIMx_PinConfig.TIM_CCR;
			//Clear TIM_CCMR2_OC4M_POS
			pTIMHandle->pTIMx->CCMR2 &= ~(6 << TIM_CCMR2_OC4M_POS);
			//Set TIM_CCMR2_OC4M_POS MODE
			pTIMHandle->pTIMx->CCMR2 |= (pTIMHandle->TIMx_PinConfig.TIM_CMP_Mode << TIM_CCMR2_OC4M_POS);
			pTIMHandle->pTIMx->CCMR2 |= ( 1 << TIM_CCMR2_OC4PE_POS);

		}
		//Auto reload pre-load Enable
		pTIMHandle->pTIMx->CR1  |= (1 << TIM_CR1_ARPE_POS);
		//Enable Counter
//		 pTIMHandle->pTIMx->CR1  |= (1 << TIM_CR1_CEN_POS);


}
/******************************IRQ Enable*******************************/
void TIM_InterruptEnable(TIM_Handle_t *pTIMHandle,uint8_t ENorDI){
	//Enable Interrupt Mode

	if(ENorDI == ENABLE){

		pTIMHandle->pTIMx->DIER  |= (1 << TIM_DIER_UIE_POS);
	}
	else{
		pTIMHandle->pTIMx->DIER  &= ~(1 << TIM_DIER_UIE_POS);
	}

}

/******************************IRQ Configuration*******************************/
void TIM_IRQInterruptConfig(uint8_t IRQNumber, uint8_t ENorDI){
	/*Configure IRQ number of TIM
	 *ISER Interrupt Set-enable Register
	 * */

	if(ENorDI == ENABLE){
		if(IRQNumber <= 31){
			*NVIC_ISER0 |= (1 << IRQNumber);
		}
		else if(IRQNumber > 31 && IRQNumber <64){
			*NVIC_ISER1 |= (1 << (IRQNumber % 32));
		}
		else if(IRQNumber >= 64 && IRQNumber <96){
			*NVIC_ISER2 |= (1 << (IRQNumber%64));
		}
	}
	else {
		/*Interrupt Clear-enable Register*/
		if(IRQNumber <= 31){
					*NVIC_ICER0 |= (1 << IRQNumber);
		}
		else if(IRQNumber > 31 && IRQNumber <64){
					*NVIC_ICER1 |= (1 << (IRQNumber % 32));
		}
		else if(IRQNumber >= 64 && IRQNumber <96){
					*NVIC_ICER2 |= (1 << (IRQNumber % 64));
		}
	}

}

/******************************Event Handling*******************************/
void TIMx_EV_IRQHandling(TIM_Handle_t *pTIMHandle){

	// ARR Overflow
	if(pTIMHandle->pTIMx->SR & ( 1 << TIM_SR_UIF_POS)){
		pTIMHandle->pTIMx->SR &= ~(1 << TIM_SR_UIF_POS);  // Clear update UIF flag
		TIM_ApplicationEventCallback(pTIMHandle,TIMx_EV_UIF);
	}

//	// Compare mode
//
//	// Channel 1 Compare triggered
//	if(pTIMHandle->pTIMx->SR & ( 1 << TIM_SR_CC1IF_POS )){
//		pTIMHandle->pTIMx->SR &= ~(1 << TIM_SR_CC1IF_POS);  // Clear update CC1IF flag
//		TIM_ApplicationEventCallback(pTIMHandle,TIMx_EV_CC1IF);
//	}
//	// Channel 2 Compare triggered
//	if(pTIMHandle->pTIMx->SR & ( 1 << TIM_SR_CC2IF_POS )){
//		pTIMHandle->pTIMx->SR &= ~(1 << TIM_SR_CC2IF_POS);  // Clear update CC2IF flag
//		TIM_ApplicationEventCallback(pTIMHandle,TIMx_EV_CC2IF);
//	}
//	// Channel 3 Compare triggered
//	if(pTIMHandle->pTIMx->SR & ( 1 << TIM_SR_CC3IF_POS )){
//		pTIMHandle->pTIMx->SR &= ~(1 << TIM_SR_CC3IF_POS);  // Clear update CC3IF flag
//		TIM_ApplicationEventCallback(pTIMHandle,TIMx_EV_CC3IF);
//	}
//	// Channel 4 Compare triggered
//	if(pTIMHandle->pTIMx->SR & ( 1 << TIM_SR_CC4IF_POS )){
//		pTIMHandle->pTIMx->SR &= ~(1 << TIM_SR_CC4IF_POS);  // Clear update CC14F flag
//		TIM_ApplicationEventCallback(pTIMHandle,TIMx_EV_CC4IF);
//	}
//	// External Interrupt, triggered when the timer is in slave mode from external source
//	if(pTIMHandle->pTIMx->SR & ( 1 << TIM_SR_TIF_POS )){
//		pTIMHandle->pTIMx->SR &= ~(1 << TIM_SR_TIF_POS);  // Clear update TIF flag
//		TIM_ApplicationEventCallback(pTIMHandle,TIMx_EV_TIF);
//	}
//
//	// Capture mode
//
//	// Channel 1 over-capture triggered
//	if(pTIMHandle->pTIMx->SR & ( 1 << TIM_SR_CC1OF_POS )){
//		pTIMHandle->pTIMx->SR &= ~(1 << TIM_SR_CC1OF_POS);  // Clear update CC1IF flag
//		TIM_ApplicationEventCallback(pTIMHandle,TIMx_ER_CC1OF);
//	}
//	// Channel 2 over-capture triggered
//	if(pTIMHandle->pTIMx->SR & ( 1 << TIM_SR_CC2OF_POS )){
//		pTIMHandle->pTIMx->SR &= ~(1 << TIM_SR_CC2OF_POS);  // Clear update CC2IF flag
//		TIM_ApplicationEventCallback(pTIMHandle,TIMx_ER_CC2OF);
//	}
//	// Channel 3 over-capture triggered
//	if(pTIMHandle->pTIMx->SR & ( 1 << TIM_SR_CC3OF_POS )){
//		pTIMHandle->pTIMx->SR &= ~(1 << TIM_SR_CC3OF_POS);  // Clear update CC3IF flag
//		TIM_ApplicationEventCallback(pTIMHandle,TIMx_ER_CC3OF);
//	}
//	// Channel 4 over-capture triggered
//	if(pTIMHandle->pTIMx->SR & ( 1 << TIM_SR_CC4OF_POS )){
//		pTIMHandle->pTIMx->SR &= ~(1 << TIM_SR_CC4OF_POS);  // Clear update CC14F flag
//		TIM_ApplicationEventCallback(pTIMHandle,TIMx_ER_CC4OF);
//	}

}











