/******************************************************************************
 *
 * Module: DC_MOTOR
 *
 * File Name: dc_motor.c
 *
 * Description: Source file for the ATmega16 DC_MOTOR driver
 *
 * Created on: May 26, 2022
 *
 * Author: Mahmoud Elfeky
 *
 *******************************************************************************/

#include"common_macros.h" 	/*To use bit-masking ready made macros*/
#include"dc_motor.h" 		/*To use DC_MOTOR driver*/
#include"gpio.h"			/*To use GPIO driver to deal with MCAL layer*/
#include"pwm.h"				/*To use PWM driver for timer0*/

/*******************************************************************************
 *                      Functions Definitions                                  *
 *******************************************************************************/

void DcMotor_Init(void){

	GPIO_setupPinDirection(DC_MOTOR_PORT_ID, DC_MOTOR_PIN1_ID , PIN_OUTPUT);
	GPIO_setupPinDirection(DC_MOTOR_PORT_ID, DC_MOTOR_PIN2_ID , PIN_OUTPUT);

	/* the DC-Motor is stopped at the beginning through the GPIO driver.*/
	GPIO_writePin(DC_MOTOR_PORT_ID, DC_MOTOR_PIN1_ID,LOGIC_LOW);
	GPIO_writePin(DC_MOTOR_PORT_ID, DC_MOTOR_PIN2_ID,LOGIC_LOW);
}

void DcMotor_Rotate(DcMotor_State state,uint8 speed){

	switch (state) {
	/*
	 * here send we the required duty cycle to the PWM driver based on the required speed value.
	 */
	PWM_Timer0_Start(speed);

	case STOP :
		/*stop moving of dc_motor axes*/
		GPIO_writePin(DC_MOTOR_PORT_ID, DC_MOTOR_PIN1_ID,LOGIC_LOW);
		GPIO_writePin(DC_MOTOR_PORT_ID, DC_MOTOR_PIN2_ID,LOGIC_LOW);
		break;
	case CW :
		/* move axis of dc_motor clock wise*/
		GPIO_writePin(DC_MOTOR_PORT_ID, DC_MOTOR_PIN1_ID,LOGIC_HIGH);
		GPIO_writePin(DC_MOTOR_PORT_ID, DC_MOTOR_PIN2_ID,LOGIC_LOW);
		break;
	case ACW :
		/* move axis of dc_motor anti-clock wise*/
		GPIO_writePin(DC_MOTOR_PORT_ID, DC_MOTOR_PIN1_ID,LOGIC_LOW);
		GPIO_writePin(DC_MOTOR_PORT_ID, DC_MOTOR_PIN2_ID,LOGIC_HIGH);
		break;
	}
}

