/*
 * mode.c
 *
 *  Created on: 2019/02/23
 *      Author: tkthn
 */

#include "main.h"
#include "stm32f1xx_hal.h"
#include "adc.h"
#include "tim.h"
#include "gpio.h"
#include "motion.h"
#include "led.h"
#include "mode.h"

int8_t MODE_SELECT(void)
{
	int mode = 0;
	int mode_max = 1;
	LED_CONTROL(mode);
	HAL_Delay(1000);

	while(1)
	{
		LED_CONTROL(mode);

		while( (HAL_GPIO_ReadPin(BOOTO_SW1_GPIO_Port,BOOTO_SW1_Pin) == GPIO_PIN_RESET) && (HAL_GPIO_ReadPin(SW2_GPIO_Port,SW2_Pin) == GPIO_PIN_RESET) && (HAL_GPIO_ReadPin(SW3_GPIO_Port,SW3_Pin) == GPIO_PIN_RESET) );

		if(HAL_GPIO_ReadPin(BOOTO_SW1_GPIO_Port,BOOTO_SW1_Pin) == GPIO_PIN_SET)
		{
			if(mode <= mode_max)
			{
				mode ++;
			}
			else
			{
				mode = 0;
			}
		}
		if(HAL_GPIO_ReadPin(SW2_GPIO_Port,SW2_Pin) == GPIO_PIN_SET)
		{
			if(mode >= 0)
			{
				mode --;
			}
			else
			{
				mode = mode_max;
			}
		}
		if(HAL_GPIO_ReadPin(SW3_GPIO_Port,SW3_Pin) == GPIO_PIN_SET) break;

		HAL_Delay(200);
	}

	return mode;
}

void MODE_RUN(int8_t mode)
{
	switch(mode)
	{
	case 0:
		MOTION_ENABLE();
		break;
	case 1:
		MOTION_STRAIGHT( 6400 , 6400 );
		break;
	default:
		break;
	}
}
