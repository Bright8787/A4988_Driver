/*
 * StepperMotor_A4988.c
 *
 *  Created on: Aug 2, 2025
 *      Author: bright
 */

#include "StepperMotor_A4988.h"



static void A4988_GPIO_config(A4988_config_t *A4988_config);

void A4988_init(A4988_config_t *A4988_config){
	A4988_GPIO_config(A4988_config);
}


static void A4988_GPIO_config(A4988_config_t *A4988_config){

	GPIO_handle_t step,dir;
	memset(&dir,0,sizeof(dir));
	memset(&step,0,sizeof(step));

	//Set up Step Port
	step.pGPIOx = A4988_config->step_port;
	step.GPIO_PinConfig.GPIO_PinNumber = A4988_config->step_pin;
	step.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_OUTPUT;
	step.GPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_FAST;
	step.GPIO_PinConfig.GPIO_PinOPType = GPIO_OUTPUT_TYPE_PP ; // PP for normal usage
	step.GPIO_PinConfig.GPIO_PinAltFunMode = 0; // No Alternate Funciton is used
	GPIO_Init(&step);
	//Set up dir Port
	dir.pGPIOx = A4988_config->dir_port;
	dir.GPIO_PinConfig.GPIO_PinNumber = A4988_config->dir_pin;
	dir.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_OUTPUT;
	dir.GPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_FAST;
	dir.GPIO_PinConfig.GPIO_PinOPType = GPIO_OUTPUT_TYPE_PP ; // PP for normal usage
	dir.GPIO_PinConfig.GPIO_PinAltFunMode = 0; // No Alternate Funciton is used
	GPIO_Init(&dir);


}







