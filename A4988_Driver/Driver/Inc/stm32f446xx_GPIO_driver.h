/*
 * stm32f446x_gpio_driver.h
 *
 *  Created on: Mar 17, 2025
 *      Author: bright
 */

#ifndef INC_STM32F446XX_GPIO_DRIVER_H_
#define INC_STM32F446XX_GPIO_DRIVER_H_

#include "../../Driver/Inc/stm32f446xx.h"


typedef struct{
	uint8_t GPIO_PinNumber;
	uint8_t GPIO_PinMode; /*< possible values from @GPIO_PIN_MODE>*/
	uint8_t GPIO_PinSpeed;
	uint8_t GPIO_PinPuPdControl;
	uint8_t GPIO_PinOPType;
	uint8_t GPIO_PinAltFunMode;

}GPIO_PinConfig_t;

typedef struct{
	GPIO_RegDef_t *pGPIOx; /*Pointer to gold the base address of the GPIO peripheral*/
	GPIO_PinConfig_t GPIO_PinConfig;
}GPIO_Handle_t;


/*@GPIO_PIN_NO*/
#define GPIO_PIN_NO_0 0
#define GPIO_PIN_NO_1 1
#define GPIO_PIN_NO_2 2
#define GPIO_PIN_NO_3 3
#define GPIO_PIN_NO_4 4
#define GPIO_PIN_NO_5 5
#define GPIO_PIN_NO_6 6
#define GPIO_PIN_NO_7 7
#define GPIO_PIN_NO_8 8
#define GPIO_PIN_NO_9 9
#define GPIO_PIN_NO_10 10
#define GPIO_PIN_NO_11 11
#define GPIO_PIN_NO_12 12
#define GPIO_PIN_NO_13 13
#define GPIO_PIN_NO_14 14
#define GPIO_PIN_NO_15 15
/*@GPIO_PIN_MODE*/
#define GPIO_MODE_INPUT 0
#define GPIO_MODE_OUTPUT 1
#define GPIO_MODE_ALTF 2
#define GPIO_MODE_ANALOG 3
#define GPIO_MODE_IT_FT 4 /*Input Falling Edge Trigger*/
#define GPIO_MODE_IT_RT 5 /*Input Rising Edge Trigger*/
#define GPIO_MODE_IT_RFT 6 /*Input Falling Rising Edge Trigger*/

/*GPIO SPEED*/
#define GPIO_SPEED_LOW 0
#define GPIO_SPEED_MEDIUM 1
#define GPIO_SPEED_FAST 2
#define GPIO_SPEED_HIGH 3

/*GPIO OUTPUT TYPE*/
#define GPIO_OUTPUT_TYPE_PP 0
#define GPIO_OUTPUT_TYPE_OD 1

/*GPIO pin pull up AND pull down configurations macros*/
#define GPIO_PUPD_NO_PUPD 0
#define GPIO_PUPD_PU 1
#define GPIO_PUPD_PD 2

/*API supported by this driver*/
void GPIO_Init(GPIO_Handle_t *pGPIOHandle);
void GPIO_DeInit(GPIO_RegDef_t *pGPIOx);

/*Enable Clock of the given GPIO*/
void GPIO_PeriClockControl(GPIO_RegDef_t *pGPIOx, uint8_t ENorDI);
/*Read/Write/Toggle*/
uint8_t GPIO_ReadFromInputPin(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber);
uint16_t GPIO_ReadFromInputPort(GPIO_RegDef_t *pGPIOx);
void GPIO_WriteToOutputPin(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber, uint8_t Value);
void GPIO_WriteToOutputPort(GPIO_RegDef_t *pGPIOx, uint16_t Value);
void GPIO_ToggleOutputPin(GPIO_RegDef_t *pGPIOx,uint8_t PinNumber);
/*Interrupt Configuration and Handler
 *GPIO Pin communicate through EXTI line to NVIC
 * */
void GPIO_IRQInterruptConfig(uint8_t IRQNumber , uint8_t ENorDI); /*Configure IRQ number of GPIO*/
void GPIO_IRQPriorityConfig(uint8_t IRQNumber , uint8_t IRQPriority); /*Configure IRQ number of GPIO*/
void GPIO_IRQHandling(uint8_t PinNumber);/*Handle Interrupt*/

#endif /* INC_STM32F446XX_GPIO_DRIVER_H_ */
