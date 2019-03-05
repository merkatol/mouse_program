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
#include "usart.h"
#include "gpio.h"
#include "led.h"
#include "motion.h"
#include "mode.h"
#include "global.h"

int8_t MODE_SELECT(void)
{
	int mode = 0;
	int mode_max = 4;
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
			/*else
			{
				mode = 0;
			}*/
		}
		if(HAL_GPIO_ReadPin(SW2_GPIO_Port,SW2_Pin) == GPIO_PIN_SET)
		{
			if(mode >= 0)
			{
				mode --;
			}
			/*else
			{
				mode = mode_max;
			}*/
		}
		if(HAL_GPIO_ReadPin(SW3_GPIO_Port,SW3_Pin) == GPIO_PIN_SET) break;

		HAL_Delay(300);
	}

	HAL_Delay(300);
	return mode;
}

void MODE_RUN(int8_t mode)
{
	switch(mode)
	{
	//ëOêi
	case 0:
		HAL_Delay(1000);
		MOTION_ENABLE();
		MOTION_STRAIGHT( 6400 , 6400 );
		HAL_Delay(1000);
		MOTION_PRES_RESET();
		HAL_Delay(1000);
		MOTION_DISABLE();
		break;
	//å„ëﬁ
	case 1:
		HAL_Delay(1000);
		MOTION_ENABLE();
		MOTION_STRAIGHT( -6400 , -6400 );
		HAL_Delay(1000);
		MOTION_PRES_RESET();
		HAL_Delay(1000);
		MOTION_DISABLE();
		break;
	//90ìxâEâÒì]
	case 2:
		HAL_Delay(1000);
		MOTION_ENABLE();
		for(int i = 0 ; i < 4 ; i ++)
		{
			MOTION_TURN_RIGHT();
			HAL_Delay(1000);
		}
		MOTION_DISABLE();
	//90ìxç∂âÒì]
	case 3:
		HAL_Delay(1000);
		MOTION_ENABLE();
		for(int i = 0 ; i < 4 ; i ++)
		{
			MOTION_TURN_LEFT();
			HAL_Delay(1000);
		}
		MOTION_DISABLE();
	//180ìxâÒì]
	case 4:
		HAL_Delay(1000);
		MOTION_ENABLE();
		for(int i = 0 ; i < 2 ; i ++)
		{
			MOTION_U_TURN();
			HAL_Delay(1000);
		}
		MOTION_DISABLE();
	default:
		break;
	}
}
