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
#include <avr/io.h>		/*To use registers of PWM driver for timer0*/
#include"pwm.h"			/*To use PWM driver for timer0*/

/*******************************************************************************
 *                      Functions Definitions                                  *
 *******************************************************************************/


void PWM_Timer0_Start(uint8 duty_cycle){

	/*Set Timer Initial value*/
	TCNT0 = 0;
	/* Set Compare Value based on the required input duty cycle*/
	OCR0  = ((uint16) (255 * duty_cycle)) /100 ;
	/*set PB3/OC0 as output pin --> pin where the PWM signal is generated from MC.*/
	DDRB  = DDRB | (1<<PB3);
		/* Configure timer control register
		*  1. Fast PWM mode FOC0=0
		*  2. Fast PWM Mode WGM01=1 & WGM00=1
		*  3. Clear OC0 when match occurs (non inverted mode) COM00=0 & COM01=1
		*  4. clock = F_CPU/8 CS00=0 CS01=1 CS02=0
		*/
	TCCR0 = (1<<WGM00) | (1<<WGM01) | (1<<COM01) | (1<<CS01);

}

