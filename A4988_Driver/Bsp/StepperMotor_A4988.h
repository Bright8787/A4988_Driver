/*
 * StepperMotor_A4988.h
 *
 *  Created on: Aug 2, 2025
 *      Author: bright
 */

#ifndef BSP_STEPPERMOTOR_A4988_H_
#define BSP_STEPPERMOTOR_A4988_H_


#include "../Driver/Inc/stm32f446xx.h"

#define HIGH 1
#define LOW 0

// MicroStepping mode
#define FULLSTEP 0
#define HALFSTEP 1
#define QUARTERSTEP 2
#define EIGTHSTEP 3
#define SIXTEENTHSTEP 7


/*Stepper object*/
typedef struct A4988_config_t{
	GPIO_RegDef_t* step_port;
	uint8_t step_pin;
	GPIO_RegDef_t* dir_port;
	uint8_t dir_pin;
    uint8_t resolution;
};


//void A4988_init(A4988_config_t *A4988_config);
void A4988_move_Step(uint32_t steps,uint32_t dir);
void A4988_move_Degree(uint32_t degree,uint32_t dir);
#endif /* BSP_STEPPERMOTOR_A4988_H_ */
