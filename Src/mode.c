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

		HAL_Delay(500);
	}

	HAL_Delay(500);
	return mode;
}

void MODE_RUN(int8_t mode)
{
	switch(mode)
	{
	//前進
	case 0:
		HAL_Delay(1000);
		MOTION_ENABLE();
		MOTION_STRAIGHT( 6400 , 6400 );
		MOTION_DISABLE();
		HAL_Delay(1000);
		HAL_GPIO_WritePin(MOTER_EN_GPIO_Port,MOTER_EN_Pin,GPIO_PIN_RESET);
		break;
	//90度右回転
	case 1:
		HAL_Delay(1000);
		MOTION_ENABLE();
		MOTION_TURN_RIGHT();
		MOTION_DISABLE();
		HAL_Delay(1000);
		HAL_GPIO_WritePin(MOTER_EN_GPIO_Port,MOTER_EN_Pin,GPIO_PIN_RESET);
		break;
	//90度左回転
	case 2:
		HAL_Delay(1000);
		MOTION_ENABLE();
		MOTION_TURN_LEFT();
		MOTION_DISABLE();
		HAL_Delay(1000);
		HAL_GPIO_WritePin(MOTER_EN_GPIO_Port,MOTER_EN_Pin,GPIO_PIN_RESET);
		break;
	//180度回転
	case 3:
		HAL_Delay(1000);
		MOTION_ENABLE();
		MOTION_TURN_LEFT();
		MOTION_DISABLE();
		HAL_Delay(1000);
		HAL_GPIO_WritePin(MOTER_EN_GPIO_Port,MOTER_EN_Pin,GPIO_PIN_RESET);
		break;
	//AD変換
	case 4:
		printf(" fl_%d , sl_%d , sr_%d , fr_%d     \r",sen_fl.value,sen_sl.value,sen_sr.value,sen_fr.value);
		break;
	default:
		break;
	}
}
