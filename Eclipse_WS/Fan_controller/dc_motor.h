/******************************************************************************
 *
 * Module: DC_MOTOR
 *
 * File Name: dc_motor.h
 *
 * Description: Header file for the ATmega16 DC_MOTOR driver
 *
 * Created on: May 26, 2022
 *
 * Author: Mahmoud Elfeky
 *
 *******************************************************************************/

#ifndef DC_MOTOR_H_
#define DC_MOTOR_H_

#include"std_types.h"

/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/
#define DC_MOTOR_PORT_ID         PORTD_ID
#define DC_MOTOR_PIN1_ID         PIN6_ID
#define DC_MOTOR_PIN2_ID         PIN7_ID

/*
 * This data type for determination of the state of motor
 */
typedef enum{
	STOP,CW,ACW
}DcMotor_State;

/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/

/*
	 * The Function responsible for setup the direction for the two motor pins through the GPIO driver.
	 * Inputs: None
	 * return: None
	 */
void DcMotor_Init(void);

/*
	 * The function responsible for rotate the DC Motor CW/ or A-CW or stop the motor based on the state input state value.
	 *
	 * Inputs:
	 * state: The required DC Motor state, it can be CW or A-CW or stop. DcMotor_State data type is enum
	 *
	 * speed: decimal value for the required motor speed,
	 * it should be from 0:100, For example, if the input is 50, The motor should rotate with 50% of its maximum speed.
	 *
	 * return: None
	 */
void DcMotor_Rotate(DcMotor_State state,uint8 speed);


#endif /* DC_MOTOR_H_ */
