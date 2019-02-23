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
#include "gpio.h"
#include "led.h"

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
	if( ( pattern & 0b0100 ) == 0b01000 )
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
