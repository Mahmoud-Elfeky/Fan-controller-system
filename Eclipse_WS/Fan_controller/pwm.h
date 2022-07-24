/******************************************************************************
 *
 * Module: PWM
 *
 * File Name: pwm.c
 *
 * Description: Source file for the ATmega16 PWM driver with timer0
 *
 * Created on: May 26, 2022
 *
 * Author: Mohamed Tarek
 *
 * Edited by: Mahmoud Elfeky
 *
 *******************************************************************************/

#ifndef PWM_H_
#define PWM_H_

#include"std_types.h"


/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/

/*
 * Description: The function responsible for trigger the Timer0 with the PWM Mode.
 * The generated PWM signal frequency will be 500Hz to control the DC Motor speed.
 * Inputs:
	 * duty_cycle: decimal value for the required motor speed,
	 * it should be from 0:100, For example, if the input is 50, The motor should rotate with 50% of its maximum speed.
 * return: None
 */
void PWM_Timer0_Start(uint8 duty_cycle);

#endif /* PWM_H_ */
