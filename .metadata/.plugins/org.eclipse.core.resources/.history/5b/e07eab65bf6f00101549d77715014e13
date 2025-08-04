/*
 * stm32f446xx.h
 *
 *  Created on: Mar 16, 2025
 *      Author: bright
 */
#ifndef INC_STM32F446XX_H_
#define INC_STM32F446XX_H_

#include<stdint.h>

/*ARM Cortex Mx Peripherals Addresses*/
/*NVIC ISER */
#define NVIC_ISER0 (volatile uint32_t*)(0xE000E100)
#define NVIC_ISER1 (volatile uint32_t*)(0xE000E104)
#define NVIC_ISER2 (volatile uint32_t*)(0xE000E108)
#define NVIC_ISER3 (volatile uint32_t*)(0xE000E10C)

/* NVIC ICER */
#define NVIC_ICER0 (volatile uint32_t*)(0xE000E180)
#define NVIC_ICER1 (volatile uint32_t*)(0xE000E184)
#define NVIC_ICER2 (volatile uint32_t*)(0xE000E188)
#define NVIC_ICER3 (volatile uint32_t*)(0xE000E18C)

/*NVIC_IPR*/
#define NVIC_IPR_BASEADDR (volatile uint32_t*)(0xE000E400)
#define NO_PR_BITS_IMPLEMENTED 4
/*MACROS*/
#define FLASH_BASEADDR 0x08000000U
#define SRAM1_BASEADDR 0x20000000U
#define SRAM2_BASEADDR 0x20001C00U
#define ROM 0x1FFF0000U
#define SRAM SRAM1_BASEADDR
#define ENABLE 1
#define DISABLE 0
#define SET ENABLE
#define RESET DISABLE
#define GPIO_PIN_SET ENABLE
#define GPIO_PIN_RESET  DISABLE

/*Peripherals*/
#define PERIPH_BASEADDR 0x40000000U
#define APB1PERIPH_BASEADDR PERIPH_BASEADDR
#define APB2PERIPH_BASEADDR 0x40010000U
#define AHB1PERIPH_BASEADDR 0x40020000U
#define AHB2PERIPH_BASEADDR 0x50000000U
/*Connection on AHB1*/
#define GPIOA_ADDR AHB1PERIPH_BASEADDR
#define GPIOB_ADDR (AHB1PERIPH_BASEADDR + 0x0400U)
#define GPIOC_ADDR (AHB1PERIPH_BASEADDR + 0x0800U)
#define GPIOD_ADDR (AHB1PERIPH_BASEADDR + 0x0C00U)
#define GPIOE_ADDR (AHB1PERIPH_BASEADDR + 0x1000U)
#define GPIOF_ADDR (AHB1PERIPH_BASEADDR + 0x1400U)
#define GPIOG_ADDR (AHB1PERIPH_BASEADDR + 0x1800U)
#define GPIOH_ADDR (AHB1PERIPH_BASEADDR + 0x1C00U)
#define RCC_BASEADDR 0x40023800U
/*Connection on APB1*/
#define I2C1_ADDR (APB1PERIPH_BASEADDR + 0x5400U)
#define I2C2_ADDR (APB1PERIPH_BASEADDR + 0x5800U)
#define I2C3_ADDR (APB1PERIPH_BASEADDR + 0x5C00U)
#define SPI2_ADDR (APB1PERIPH_BASEADDR + 0x3800U)
#define SPI3_ADDR (APB1PERIPH_BASEADDR + 0x3C00U)
/*Connection on APB2*/
#define EXTI_ADDR (APB2PERIPH_BASEADDR + 0x3C00U)
#define SYSCFG_ADDR (APB2PERIPH_BASEADDR + 0x3800U)

#define SPI1_ADDR (APB2PERIPH_BASEADDR + 0x3000U)
#define SPI4_ADDR (APB2PERIPH_BASEADDR + 0x3400U)


/*IRQ Interrupt request*/
#define IRQ_NO_EXTI0 6
#define IRQ_NO_EXTI1 7
#define IRQ_NO_EXTI2 8
#define IRQ_NO_EXTI3 9
#define IRQ_NO_EXTI4	10
#define IRQ_NO_EXTI9_5   23
#define IRQ_NO_EXTI15_10 40
#define IRQ_NO_I2C1_EV 31
#define IRQ_NO_I2C1_ER 32
#define IRQ_NO_I2C2_EV 33
#define IRQ_NO_I2C2_ER 34
#define IRQ_NO_I2C3_EV 72
#define IRQ_NO_I2C3_ER 73
#define IRQ_NO_SPI1 35
#define IRQ_NO_SPI2 36
#define IRQ_NO_SPI3 51
#define IRQ_NO_SPI4 84

/*SPI Register Bit Position*/
#define SPI_CR1_CPHA 0
#define SPI_CR1_CPOL 1
#define SPI_CR1_MSTR 2
#define SPI_CR1_SPE 6
#define SPI_CR1_SSM 9
#define SPI_CR1_SSI 8
#define SPI_CR1_BR 3
#define SPI_CR1_RXONLY 10
#define SPI_CR1_DFF 11
#define SPI_CR1_BIDIMODE 15

#define SPI_CR2_SSOE 2
#define SPI_CR2_ERRIE 5
#define SPI_CR2_RXNEIE 6
#define SPI_CR2_TXEIE 7

#define SPI_SR_RXNE 0
#define SPI_SR_TXE 1
#define SPI_SR_CHSIDE 2
#define SPI_SR_UDR 3
#define SPI_SR_CRCERR 4
#define SPI_SR_MODF 5
#define SPI_SR_OVR 6
#define SPI_SR_BSY 7
#define SPI_SR_FRE 8


/*I2C Register Bit Position*/
#define I2C_CR1_PE 0
#define I2C_CR1_START 8
#define I2C_CR1_STOP 9
#define I2C_CR1_ACK 10

#define I2C_CR2_ITERR_EN 8
#define I2C_CR2_ITEVT_EN 9
#define I2C_CR2_ITBUF_EN 10
#define I2C_CR2_DMA_EN 11

#define I2C_SR1_SB 0
#define I2C_SR1_ADDR 1
#define I2C_SR1_BTF 2
#define I2C_SR1_ADD10 3
#define I2C_SR1_STOPF 4
#define I2C_SR1_RXNE 6
#define I2C_SR1_TXE 7
#define I2C_SR1_BERR 8
#define I2C_SR1_ARLO 9
#define I2C_SR1_AF 10
#define I2C_SR1_OVR 11
#define I2C_SR1_PECERR 12
#define I2C_SR1_TIMEOUT 14
#define I2C_SR1_SMBALERT 16

#define I2C_SR2_MSL 0
#define I2C_SR2_BUSY 1
#define I2C_SR2_TRA 2

#define I2C_STOP_ENABLE 1
#define I2C_STOP_DISABLE 0

#define I2C_ACK_ENABLE 1
#define I2C_ACK_DISABLE 0

#define FLAG_RESET 0
#define FLAG_SET 1

/*GPIO Object*/
typedef struct {
	volatile uint32_t MODER; /*Mode*/
	volatile uint32_t OTYPER; /*Output type*/
	volatile uint32_t OSPEEDR; /*Output speed*/
	volatile uint32_t PUPDR; /*pull-up or pull-down*/
	volatile uint32_t IDR; /*Input data*/
	volatile uint32_t ODR; /*Output data*/
	volatile uint32_t BSRR; /*bit set/reset*/
	volatile uint32_t LCKR; /*configuration lock*/
	volatile uint32_t AFR[2]; /*Alternate function low [0] high[1]*/

}GPIO_RegDef_t;

/*SPI Object*/
typedef struct {
	volatile uint32_t SPI_CR1; /*Control 1*/
	volatile uint32_t SPI_CR2; /*Control 2*/
	volatile uint32_t SPI_SR; /*Status*/
	volatile uint32_t SPI_DR; /*Data*/
	volatile uint32_t SPI_CRCPR; /*Polynomial*/
	volatile uint32_t SPI_RXCRCR; /*RX CRC*/
	volatile uint32_t SPI_TXCRCR; /*TX CRC */
	volatile uint32_t SPI_I2SCFGR; /*configuration */
	volatile uint32_t SPI_I2SPR; /*Pre scaler*/
}SPI_RegDef_t;

/*EXTI OBJ*/
typedef struct{

	volatile uint32_t IMR;
	volatile uint32_t EMR;
	volatile uint32_t RTSR;
	volatile uint32_t FTSR;
	volatile uint32_t SWIER;
	volatile uint32_t PR;

}EXTI_RegDef_t;
/*RCC Object*/
typedef struct {
	volatile uint32_t CR;
	volatile uint32_t PLLCFGR;
	volatile uint32_t CFGR;
	volatile uint32_t CIR;
	volatile uint32_t AHB1RSTR;
	volatile uint32_t AHB2RSTR;
	volatile uint32_t AHB3RSTR;
	volatile uint32_t RESERVED0;
	volatile uint32_t APB1RSTR;
	volatile uint32_t APB2RSTR;
	 uint32_t RESERVED1[2];
	volatile uint32_t AHB1ENR;
	volatile uint32_t AHB2ENR;
	volatile uint32_t AHB3ENR;
	volatile uint32_t RESERVED2;
	volatile uint32_t APB1ENR;
	volatile uint32_t APB2ENR;
	 uint32_t RESERVED3[2];
	volatile uint32_t AHB1LPENR;
	volatile uint32_t AHB2LPENR;
	volatile uint32_t AHB3LPENR;
	uint32_t RESERVED4;
	volatile uint32_t APB1LPENR;
	volatile uint32_t APB2LPENR;
	 uint32_t RESERVED5[2];
	volatile uint32_t BDCR;
	volatile uint32_t CSR;
	 uint32_t RESERVED6[2];
	volatile uint32_t SSCGR;
	volatile uint32_t PLLI2SCFGR;
	volatile uint32_t PLLISAIVFGR;
	volatile uint32_t DCKCFGR;
	volatile uint32_t CKGATENR;
	volatile uint32_t DCKCFGR2;
}RCC_RegDef_t;

typedef struct{
	volatile uint32_t MEMRMP;
	volatile uint32_t PMC;
	volatile uint32_t EXTICR[4];
	volatile uint32_t RESERVED1[2];
	volatile uint32_t CMPCR;
	volatile uint32_t RESERVED2[2];
	volatile uint32_t CFGR;


}SYSCFG_RegDef_t;

typedef struct{
	volatile uint32_t CR1;
	volatile uint32_t CR2;
	volatile uint32_t OAR1;
	volatile uint32_t OAR2;
	volatile uint32_t DR;
	volatile uint32_t SR1;
	volatile uint32_t SR2;
	volatile uint32_t CCR;
	volatile uint32_t TRISE;
	volatile uint32_t FLTR;

}I2C_RegDef_t;
/*Peripheral definition*/
#define pGPIOA ((GPIO_RegDef_t*)GPIOA_ADDR)
#define pGPIOB ((GPIO_RegDef_t*)GPIOB_ADDR)
#define pGPIOC ((GPIO_RegDef_t*)GPIOC_ADDR)
#define pGPIOD ((GPIO_RegDef_t*)GPIOD_ADDR)
#define pGPIOE ((GPIO_RegDef_t*)GPIOE_ADDR)
#define pGPIOF ((GPIO_RegDef_t*)GPIOF_ADDR)
#define pGPIOG ((GPIO_RegDef_t*)GPIOG_ADDR)
#define pGPIOH ((GPIO_RegDef_t*)GPIOH_ADDR)
#define RCC    ((RCC_RegDef_t*)RCC_BASEADDR)
#define SYSCFG ((SYSCFG_RegDef_t*)SYSCFG_ADDR)
#define EXTI   ((EXTI_RegDef_t*)EXTI_ADDR)


#define pI2C1 ((I2C_RegDef_t*)I2C1_ADDR)
#define pI2C2 ((I2C_RegDef_t*)I2C2_ADDR)
#define pI2C3 ((I2C_RegDef_t*)I2C3_ADDR)

/*Clock Enable Macros for GPIOX peripherals*/
#define GPIOA_PCLK_EN() (RCC->AHB1ENR |= (1 << 0))
#define GPIOB_PCLK_EN() (RCC->AHB1ENR |= (1 << 1))
#define GPIOC_PCLK_EN() (RCC->AHB1ENR |= (1 << 2))
#define GPIOD_PCLK_EN() (RCC->AHB1ENR |= (1 << 3))
#define GPIOE_PCLK_EN() (RCC->AHB1ENR |= (1 << 4))
#define GPIOF_PCLK_EN() (RCC->AHB1ENR |= (1 << 5))
#define GPIOG_PCLK_EN() (RCC->AHB1ENR |= (1 << 6))
#define GPIOH_PCLK_EN() (RCC->AHB1ENR |= (1 << 7))



/*GPIO PORT TO INDEX FOR EXTI*/
#define GPIO_BASEADDR_TO_CODE(x) ((x == pGPIOA) ? 0 :\
								  (x == pGPIOB) ? 1 :\
								  (x == pGPIOC) ? 2 :\
								  (x == pGPIOD) ? 3 :\
								  (x == pGPIOE) ? 4 :\
								  (x == pGPIOF) ? 5 :\
								  (x == pGPIOG) ? 6 :\
								  (x == pGPIOH) ? 7 : 0)

/*Enable Macros for SPIX peripherals*/
#define SPI1_PCLK_EN() (RCC->APB2ENR |= (1 << 12))
#define SPI2_PCLK_EN() (RCC->APB1ENR |= (1 << 14))
#define SPI3_PCLK_EN() (RCC->APB1ENR |= (1 << 15))
#define SPI4_PCLK_EN() (RCC->APB2ENR |= (1 << 13))
/*Enable Macros for I2CX peripherals*/
#define I2C1_PCLK_EN() (RCC->APB1ENR |= (1 << 21))
#define I2C2_PCLK_EN() (RCC->APB1ENR |= (1 << 22))
#define I2C3_PCLK_EN() (RCC->APB1ENR |= (1 << 23))

/*Clock Enable Macros for SYSCFG peripherals*/
#define SYSCFG_PCLK_EN() (RCC->APB2ENR |= (1 << 14))
/*Clock Disable Macros for GPIO peripherals*/
#define GPIOA_PCLK_DI() (RCC->AHB1ENR &= ~(1 << 0))
#define GPIOB_PCLK_DI() (RCC->AHB1ENR &= ~(1 << 1))
#define GPIOC_PCLK_DI() (RCC->AHB1ENR &= ~(1 << 2))
#define GPIOD_PCLK_DI() (RCC->AHB1ENR &= ~(1 << 3))
#define GPIOE_PCLK_DI() (RCC->AHB1ENR &= ~(1 << 4))
#define GPIOF_PCLK_DI() (RCC->AHB1ENR &= ~(1 << 5))
#define GPIOG_PCLK_DI() (RCC->AHB1ENR &= ~(1 << 6))
#define GPIOH_PCLK_DI() (RCC->AHB1ENR &= ~(1 << 7))
/*Clock Disable Macros for SPI peripherals*/
#define SPI1_PCLK_DI() (RCC->APB2ENR &= ~(1 << 12))
#define SPI2_PCLK_DI() (RCC->APB1ENR &= ~(1 << 14))
#define SPI3_PCLK_DI() (RCC->APB1ENR &= ~(1 << 15))
#define SPI4_PCLK_DI() (RCC->APB2ENR &= ~(1 << 13))
/*Clock Disable for I2Cx peripherals*/
#define I2C1_PCLK_DI() (RCC->APB1ENR &= ~(1 << 21))
#define I2C2_PCLK_DI() (RCC->APB1ENR &= ~(1 << 22))
#define I2C3_PCLK_DI() (RCC->APB1ENR &= ~(1 << 23))

/*Reset Macros GPIO peripherals*/
#define GPIOA_REG_RESET() do{(RCC->AHB1RSTR  |= (1 << 0)); (RCC->AHB1RSTR  &= ~(1 << 0));}while(0)
#define GPIOB_REG_RESET() do{(RCC->AHB1RSTR  |= (1 << 1)); (RCC->AHB1RSTR  &= ~(1 << 1));}while(0)
#define GPIOC_REG_RESET() do{(RCC->AHB1RSTR  |= (1 << 2)); (RCC->AHB1RSTR  &= ~(1 << 2));}while(0)
#define GPIOD_REG_RESET() do{(RCC->AHB1RSTR  |= (1 << 3)); (RCC->AHB1RSTR  &= ~(1 << 3));}while(0)
#define GPIOE_REG_RESET() do{(RCC->AHB1RSTR  |= (1 << 4)); (RCC->AHB1RSTR  &= ~(1 << 4));}while(0)
#define GPIOF_REG_RESET() do{(RCC->AHB1RSTR  |= (1 << 5)); (RCC->AHB1RSTR  &= ~(1 << 5));}while(0)
#define GPIOG_REG_RESET() do{(RCC->AHB1RSTR  |= (1 << 6)); (RCC->AHB1RSTR  &= ~(1 << 6));}while(0)
#define GPIOH_REG_RESET() do{(RCC->AHB1RSTR  |= (1 << 7)); (RCC->AHB1RSTR  &= ~(1 << 7));}while(0)

#include "../../Driver/Inc/stm32f446xx_GPIO_driver.h"
#include "../../Driver/Inc/stm32f446xx_I2C_driver.h"
#endif /* INC_STM32F446XX_H_ */
