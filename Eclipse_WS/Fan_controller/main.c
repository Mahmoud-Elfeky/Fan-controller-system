/*
*	Name:			main.c
 *	Author:			Mahmoud EL-FEKY
 *	Description:	Full Fan Controller System based on sensed temperature
 *  Created on: 	May 26, 2022
 */

#include "adc.h"			/*To use ADC driver*/
#include "lcd.h"			/*To use LCD driver*/
#include "dc_motor.h"		/*To use DC_MOTOR driver*/
#include "lm35_sensor.h"	/*To use lm35_sensor driver*/

void main(){
	uint8 temp_value=0;
	/*prepare structure variable to work with internal Vref and division Fcpu by 8 */
	ADC_ConfigType conf1g1={INTERNAL,FCPU_8};

	/*Start ABC initialization function with dynamic configurations based on above structure values*/
	ADC_init(&conf1g1);
	/*Start LCD initialization function with Static configurations*/
	LCD_init();
	/*Start DcMotor initialization function with Static configurations*/
	DcMotor_Init();

	/* Display this string "FAN IS :" at the first row,
	 * "Temp =   C" only once on LCD at the second row */
	LCD_displayString("FAN IS :");
	LCD_moveCursor(1,0);
	LCD_displayString("TEMP =    C");

	/*start super loop*/
	while(1){
		/*get temperature value from the sensor and store it on temp_value*/
		temp_value=LM35_getTemperature();
		/*move LCD cursor to row the second row and col 8 to write temp_value on LCD */
		LCD_moveCursor(1,7);

		/*render temp_value on LCD */
		if(temp_value>=100)
			LCD_intgerToString(temp_value);
		else{
			LCD_intgerToString(temp_value);
			LCD_displayCharacter(' ');
		}

		if(temp_value<30){
			DcMotor_Rotate(STOP,0);
			/*move LCD cursor to row the first row and col 8 to write state of motor on LCD */
			LCD_moveCursor(0,7);
			/*render state of motor on LCD */
			LCD_displayString("OFF");
			continue;
		}
		else if(temp_value>=30)
			/* move axis of dc_motor clock wise with quarter of total speed*/
			DcMotor_Rotate(CW,25);
		else if(temp_value>=60)
			/* move axis of dc_motor clock wise with half of total speed*/
			DcMotor_Rotate(CW,50);
		else if(temp_value>=90)
			/* move axis of dc_motor clock wise with three quarters of total speed*/
			DcMotor_Rotate(CW,75);
		else if(temp_value>=120)
			/* move axis of dc_motor clock wise with full total speed*/
			DcMotor_Rotate(CW,100);
		/*move LCD cursor to row the first row and col 8 to write state of motor on LCD */
		LCD_moveCursor(0,7);
		/*render state of motor on LCD */
		LCD_displayString("ON ");
	}
}

