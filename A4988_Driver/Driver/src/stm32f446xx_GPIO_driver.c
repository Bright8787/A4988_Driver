/*
 * stm32f446x_gpio_driver.c
 *
 *  Created on: Mar 17, 2025
 *      Author: bright
 */
#include "stm32f446xx_GPIO_driver.h"

void GPIO_Init(GPIO_Handle_t *pGPIOHandle){

	GPIO_PeriClockControl(pGPIOHandle->pGPIOx, ENABLE);

	/*Non-Interrupt Mode*/
	if(pGPIOHandle->GPIO_PinConfig.GPIO_PinMode <= GPIO_MODE_ANALOG){
		pGPIOHandle->pGPIOx->MODER &= ~(0x3 << ( 2*pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber));
		pGPIOHandle->pGPIOx->MODER |= (pGPIOHandle->GPIO_PinConfig.GPIO_PinMode << (2*pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber));

	}
	/*Interrupt Mode*/
	else{

		uint8_t index = pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber / 4;

		uint8_t Port = GPIO_BASEADDR_TO_CODE(pGPIOHandle->pGPIOx);

		if(pGPIOHandle->GPIO_PinConfig.GPIO_PinMode == GPIO_MODE_IT_FT){
			EXTI->FTSR |= (1 << pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber);
			EXTI->RTSR &= ~(1 << pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber);
		}
		else if (pGPIOHandle->GPIO_PinConfig.GPIO_PinMode == GPIO_MODE_IT_RT){
			EXTI->RTSR |= (1 << pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber);
			EXTI->FTSR &= ~(1 << pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber);
		}
		else{
			EXTI->RTSR |= (1 << pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber);
			EXTI->FTSR |= (1 << pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber);

		}
		//2. Configure the GPIO port selection in SYSCFG_EXTICR
		SYSCFG_PCLK_EN();
		SYSCFG->EXTICR[index] |= (Port << ((pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber % 4) * 4));
		//3. enable the EXTI interrupt delivery using IMR
		EXTI->IMR |= 1 << pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber;


	}

	pGPIOHandle->pGPIOx->OSPEEDR &= ~(0x3 << pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber);
			pGPIOHandle->pGPIOx->OSPEEDR |= (pGPIOHandle->GPIO_PinConfig.GPIO_PinSpeed <<
					   (2*pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber));


	pGPIOHandle->pGPIOx->PUPDR &= ~(0x3 << pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber);
			pGPIOHandle->pGPIOx->PUPDR |= (pGPIOHandle->GPIO_PinConfig.GPIO_PinPuPdControl<<
					   (2*pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber));

	pGPIOHandle->pGPIOx->OTYPER &= ~(0x1 << pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber);
			pGPIOHandle->pGPIOx->OTYPER |= (pGPIOHandle->GPIO_PinConfig.GPIO_PinOPType <<
					   (pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber));

	/*Alternate Function Mode*/
	if(pGPIOHandle->GPIO_PinConfig.GPIO_PinMode == GPIO_MODE_ALTF){
		if(pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber > 7 && pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber > 16 ){
			pGPIOHandle->pGPIOx->AFR[1] &= ~(0xF <<  4*(pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber % 8));
			pGPIOHandle->pGPIOx->AFR[1] |= (pGPIOHandle->GPIO_PinConfig.GPIO_PinAltFunMode <<  4*(pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber % 8));
		}
		else {
			pGPIOHandle->pGPIOx->AFR[0] &= ~(0xF <<  4*(pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber % 8));
			pGPIOHandle->pGPIOx->AFR[0] |= (pGPIOHandle->GPIO_PinConfig.GPIO_PinAltFunMode <<  4*(pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber % 8));

		}
	}


}
void GPIO_DeInit(GPIO_RegDef_t *pGPIOx){

		if(pGPIOx == pGPIOA){
			GPIOA_REG_RESET();
		}
		else if(pGPIOx == pGPIOB){
			GPIOB_REG_RESET();

		}
		else if(pGPIOx == pGPIOC){
			GPIOC_REG_RESET();

		}
		else if(pGPIOx == pGPIOD){
			GPIOD_REG_RESET();

		}
		else if(pGPIOx == pGPIOE){
			GPIOE_REG_RESET();

		}
		else if(pGPIOx == pGPIOF){
			GPIOF_REG_RESET();

		}
		else if(pGPIOx == pGPIOG){

			GPIOG_REG_RESET();
		}
		else if(pGPIOx == pGPIOH){

			GPIOH_REG_RESET();
		}


}

/*Enable Clock of the given GPIO*/
void GPIO_PeriClockControl(GPIO_RegDef_t *pGPIOx, uint8_t ENorDI){
//	assert(pGPIOx == NULL);
	if(ENorDI == ENABLE){

		if(pGPIOx == pGPIOA){
			GPIOA_PCLK_EN();
		}
		else if(pGPIOx == pGPIOB){
			GPIOB_PCLK_EN();

		}
		else if(pGPIOx == pGPIOC){
			GPIOC_PCLK_EN();

		}
		else if(pGPIOx == pGPIOD){
			GPIOD_PCLK_EN();

		}
		else if(pGPIOx == pGPIOE){
			GPIOE_PCLK_EN();

		}
		else if(pGPIOx == pGPIOF){
			GPIOF_PCLK_EN();

		}
		else if(pGPIOx == pGPIOG){

			GPIOG_PCLK_EN();
		}
		else if(pGPIOx == pGPIOH){

			GPIOH_PCLK_EN();
		}
	}
	else{
		if(pGPIOx == pGPIOA){
					GPIOA_PCLK_DI();
				}
				else if(pGPIOx == pGPIOB){
					GPIOB_PCLK_DI();

				}
				else if(pGPIOx == pGPIOC){
					GPIOC_PCLK_DI();

				}
				else if(pGPIOx == pGPIOD){
					GPIOD_PCLK_DI();

				}
				else if(pGPIOx == pGPIOE){
					GPIOE_PCLK_DI();

				}
				else if(pGPIOx == pGPIOF){
					GPIOF_PCLK_DI();

				}
				else if(pGPIOx == pGPIOG){

					GPIOG_PCLK_DI();
				}
				else if(pGPIOx == pGPIOH){

					GPIOH_PCLK_DI();
				}
	}
}

uint8_t GPIO_ReadFromInputPin(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber){

	uint8_t data;
	data = (uint8_t)((pGPIOx->IDR >> PinNumber) & 0x00000001);
	return data;
}
uint16_t GPIO_ReadFromInputPort(GPIO_RegDef_t *pGPIOx){
	uint16_t read_data;
	read_data = (uint16_t)(pGPIOx->IDR);
	return read_data;
}
void GPIO_WriteToOutputPin(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber, uint8_t Value){

	if(Value == GPIO_PIN_SET){

		pGPIOx->ODR |= (1 << PinNumber);
	}
	else{
		pGPIOx->ODR &= ~(1 << PinNumber);
	}
}
void GPIO_WriteToOutputPort(GPIO_RegDef_t *pGPIOx, uint16_t Value){

	pGPIOx->ODR = Value;
}
void GPIO_ToggleOutputPin(GPIO_RegDef_t *pGPIOx,uint8_t PinNumber){
	pGPIOx->ODR ^= (1 << PinNumber);
}
void GPIO_IRQPriorityConfig(uint8_t IRQNumber, uint8_t IRQPriority){
	uint8_t iprx = IRQNumber/4;
	uint8_t iprx_section = IRQNumber % 4;
	/*Interrupt Priority Register*/
	*(NVIC_IPR_BASEADDR + (iprx*4)) |=   (IRQPriority << (8*iprx_section + (8 - NO_PR_BITS_IMPLEMENTED) ) );
}
void GPIO_IRQInterruptConfig(uint8_t IRQNumber, uint8_t ENorDI){
	/*Configure IRQ number of GPIO
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
void GPIO_IRQHandling(uint8_t PinNumber){
	/*Handle Interrupt*/
	/*Clear the EXTI PR Register(Buffer) corresponding to the pin number*/
	if(EXTI->PR & (1<< PinNumber))
	{
		EXTI->PR |= (1<< PinNumber);
	}
}
