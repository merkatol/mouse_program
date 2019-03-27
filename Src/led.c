/*
 * led.c
 *
 *  Created on: 2018/12/07
 *      Author: tkthn
 */

#include "main.h"
#include "stm32f1xx_hal.h"
#include "adc.h"
#include "tim.h"
#include "usart.h"
#include "gpio.h"
#include "led.h"
#include "motion.h"
#include "mode.h"
#include "global.h"

void LED_ALL_ON(void)
{
	HAL_GPIO_WritePin( LED1_GPIO_Port , LED1_Pin , GPIO_PIN_SET );
	HAL_GPIO_WritePin( LED2_GPIO_Port , LED2_Pin , GPIO_PIN_SET );
	HAL_GPIO_WritePin( LED3_GPIO_Port , LED3_Pin , GPIO_PIN_SET );
	HAL_GPIO_WritePin( LED4_GPIO_Port , LED4_Pin , GPIO_PIN_SET );
}

void LED_ALL_OFF(void)
{
	HAL_GPIO_WritePin( LED1_GPIO_Port , LED1_Pin , GPIO_PIN_RESET );
	HAL_GPIO_WritePin( LED2_GPIO_Port , LED2_Pin , GPIO_PIN_RESET );
	HAL_GPIO_WritePin( LED3_GPIO_Port , LED3_Pin , GPIO_PIN_RESET );
	HAL_GPIO_WritePin( LED4_GPIO_Port , LED4_Pin , GPIO_PIN_RESET );
}

void LED_CONTROL(unsigned char pattern)
{
	if( pattern == 0 )
		LED_ALL_OFF();
	if( ( pattern & 0b0001 ) == 0b0001 )
		HAL_GPIO_WritePin( LED1_GPIO_Port , LED1_Pin , GPIO_PIN_SET );
	else
		HAL_GPIO_WritePin( LED1_GPIO_Port , LED1_Pin , GPIO_PIN_RESET );
	if( ( pattern & 0b0010 ) == 0b0010 )
		HAL_GPIO_WritePin( LED2_GPIO_Port , LED2_Pin , GPIO_PIN_SET );
	else
		HAL_GPIO_WritePin( LED2_GPIO_Port , LED2_Pin , GPIO_PIN_RESET );
	if( ( pattern & 0b0100 ) == 0b0100 )
		HAL_GPIO_WritePin( LED3_GPIO_Port , LED3_Pin , GPIO_PIN_SET );
	else
		HAL_GPIO_WritePin( LED3_GPIO_Port , LED3_Pin , GPIO_PIN_RESET );
	if( ( pattern & 0b1000 ) == 0b1000 )
		HAL_GPIO_WritePin( LED4_GPIO_Port , LED4_Pin , GPIO_PIN_SET );
	else
		HAL_GPIO_WritePin( LED4_GPIO_Port , LED4_Pin , GPIO_PIN_RESET );
}

void LED_FLICK(void)
{
	HAL_GPIO_WritePin( LED1_GPIO_Port , LED1_Pin , GPIO_PIN_SET );
	HAL_Delay( 100 );
	HAL_GPIO_WritePin( LED1_GPIO_Port , LED1_Pin , GPIO_PIN_RESET );
	HAL_GPIO_WritePin( LED2_GPIO_Port , LED2_Pin , GPIO_PIN_SET );
	HAL_Delay( 100 );
	HAL_GPIO_WritePin( LED2_GPIO_Port , LED2_Pin , GPIO_PIN_RESET );
	HAL_GPIO_WritePin( LED3_GPIO_Port , LED3_Pin , GPIO_PIN_SET );
	HAL_Delay( 100 );
	HAL_GPIO_WritePin( LED3_GPIO_Port , LED3_Pin , GPIO_PIN_RESET );
	HAL_GPIO_WritePin( LED4_GPIO_Port , LED4_Pin , GPIO_PIN_SET );
	HAL_Delay( 100 );
	HAL_GPIO_WritePin( LED4_GPIO_Port , LED4_Pin , GPIO_PIN_RESET );
}

void LED_SENSOR_ON(void)
{
	HAL_GPIO_WritePin(SENSOR1_GPIO_Port,SENSOR1_Pin,GPIO_PIN_SET);
	HAL_GPIO_WritePin(SENSOR2_GPIO_Port,SENSOR2_Pin,GPIO_PIN_SET);
	HAL_GPIO_WritePin(SENSOR3_GPIO_Port,SENSOR3_Pin,GPIO_PIN_SET);
	HAL_GPIO_WritePin(SENSOR4_GPIO_Port,SENSOR4_Pin,GPIO_PIN_SET);
}

void LED_SENSOR_OFF(void)
{
	HAL_GPIO_WritePin(SENSOR1_GPIO_Port,SENSOR1_Pin,GPIO_PIN_RESET);
	HAL_GPIO_WritePin(SENSOR2_GPIO_Port,SENSOR2_Pin,GPIO_PIN_RESET);
	HAL_GPIO_WritePin(SENSOR3_GPIO_Port,SENSOR3_Pin,GPIO_PIN_RESET);
	HAL_GPIO_WritePin(SENSOR4_GPIO_Port,SENSOR4_Pin,GPIO_PIN_RESET);
}

void LED_SENSOR_CONTROLL(unsigned char pattern)
{
	if( pattern == 0 )
		LED_SENSOR_OFF();
	if( ( pattern & 0b0001 ) == 0b0001 )
		HAL_GPIO_WritePin(SENSOR1_GPIO_Port,SENSOR1_Pin,GPIO_PIN_SET);
	else
		HAL_GPIO_WritePin(SENSOR1_GPIO_Port,SENSOR1_Pin,GPIO_PIN_RESET);
	if( ( pattern & 0b0010 ) == 0b0010 )
		HAL_GPIO_WritePin(SENSOR2_GPIO_Port,SENSOR2_Pin,GPIO_PIN_SET);
	else
		HAL_GPIO_WritePin(SENSOR2_GPIO_Port,SENSOR2_Pin,GPIO_PIN_RESET);
	if( ( pattern & 0b0100 ) == 0b0100 )
		HAL_GPIO_WritePin(SENSOR3_GPIO_Port,SENSOR3_Pin,GPIO_PIN_SET);
	else
		HAL_GPIO_WritePin(SENSOR3_GPIO_Port,SENSOR3_Pin,GPIO_PIN_RESET);
	if( ( pattern & 0b1000 ) == 0b1000 )
		HAL_GPIO_WritePin(SENSOR4_GPIO_Port,SENSOR4_Pin,GPIO_PIN_SET);
	else
		HAL_GPIO_WritePin(SENSOR4_GPIO_Port,SENSOR4_Pin,GPIO_PIN_RESET);
}
