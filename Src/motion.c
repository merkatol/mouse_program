/*
 * motion.c
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

TIM_OC_InitTypeDef sConfigOC;

void MOTION_ENABLE(void)
{
	  sConfigOC.OCMode = TIM_OCMODE_PWM1;
	  sConfigOC.Pulse = 1;
	  sConfigOC.OCPolarity = TIM_OCPOLARITY_HIGH;
	  sConfigOC.OCFastMode = TIM_OCFAST_DISABLE;
	  if (HAL_TIM_PWM_ConfigChannel(&htim2, &sConfigOC, TIM_CHANNEL_3) != HAL_OK)
	  {
	    _Error_Handler(__FILE__, __LINE__);
	  }

	  sConfigOC.OCMode = TIM_OCMODE_PWM1;
	  sConfigOC.Pulse = 1;
	  sConfigOC.OCPolarity = TIM_OCPOLARITY_HIGH;
	  sConfigOC.OCFastMode = TIM_OCFAST_DISABLE;
	  if (HAL_TIM_PWM_ConfigChannel(&htim3, &sConfigOC, TIM_CHANNEL_4) != HAL_OK)
	  {
	    _Error_Handler(__FILE__, __LINE__);
	  }

	  if( HAL_TIM_PWM_Start(&htim2,TIM_CHANNEL_3) != HAL_OK)
	  {
	    _Error_Handler(__FILE__, __LINE__);
	  }
	  if( HAL_TIM_PWM_Start(&htim3,TIM_CHANNEL_4) != HAL_OK)
	  {
	    _Error_Handler(__FILE__, __LINE__);
	  }

	  HAL_GPIO_WritePin(MOTER_EN_GPIO_Port,MOTER_EN_Pin,GPIO_PIN_SET);
}

void MOTION_DISABLE(void)
{
	  sConfigOC.OCMode = TIM_OCMODE_PWM1;
	  sConfigOC.Pulse = 0;
	  sConfigOC.OCPolarity = TIM_OCPOLARITY_HIGH;
	  sConfigOC.OCFastMode = TIM_OCFAST_DISABLE;
	  if (HAL_TIM_PWM_ConfigChannel(&htim2, &sConfigOC, TIM_CHANNEL_3) != HAL_OK)
	  {
	    _Error_Handler(__FILE__, __LINE__);
	  }

	  sConfigOC.OCMode = TIM_OCMODE_PWM1;
	  sConfigOC.Pulse = 0;
	  sConfigOC.OCPolarity = TIM_OCPOLARITY_HIGH;
	  sConfigOC.OCFastMode = TIM_OCFAST_DISABLE;
	  if (HAL_TIM_PWM_ConfigChannel(&htim3, &sConfigOC, TIM_CHANNEL_4) != HAL_OK)
	  {
	    _Error_Handler(__FILE__, __LINE__);
	  }

	  if( HAL_TIM_PWM_Stop(&htim2,TIM_CHANNEL_3) != HAL_OK)
	  {
	    _Error_Handler(__FILE__, __LINE__);
	  }
	  if( HAL_TIM_PWM_Stop(&htim3,TIM_CHANNEL_4) != HAL_OK)
	  {
	    _Error_Handler(__FILE__, __LINE__);
	  }

	  htim2.Init.Prescaler = 0;
	  if (HAL_TIM_PWM_Init(&htim2) != HAL_OK)
	  {
		    _Error_Handler(__FILE__, __LINE__);
	  }

	  htim3.Init.Prescaler = 0;
	  if (HAL_TIM_PWM_Init(&htim3) != HAL_OK)
	  {
		  _Error_Handler(__FILE__, __LINE__);
	  }

	  HAL_GPIO_WritePin(L_CW_CCW_GPIO_Port,L_CW_CCW_Pin,GPIO_PIN_RESET);
	  HAL_GPIO_WritePin(R_CW_CCW_GPIO_Port,R_CW_CCW_Pin,GPIO_PIN_RESET);
}

void MOTION_STRAIGHT(int left,int right)
{
	prescaler.left = left;
	prescaler.right = right;

	if(left > 0)
	{
		HAL_GPIO_WritePin(L_CW_CCW_GPIO_Port,L_CW_CCW_Pin,GPIO_PIN_SET);
	}
	else
	{
		HAL_GPIO_WritePin(L_CW_CCW_GPIO_Port,L_CW_CCW_Pin,GPIO_PIN_RESET);
		left = -1*left;
	}
	if(right > 0)
	{
		HAL_GPIO_WritePin(R_CW_CCW_GPIO_Port,R_CW_CCW_Pin,GPIO_PIN_RESET);
	}
	else
	{
		HAL_GPIO_WritePin(R_CW_CCW_GPIO_Port,R_CW_CCW_Pin,GPIO_PIN_SET);
		right = -1*right;
	}

	htim2.Init.Prescaler = prescaler.left;
	if (HAL_TIM_PWM_Init(&htim2) != HAL_OK)
	{
		_Error_Handler(__FILE__, __LINE__);
	}

	htim3.Init.Prescaler = prescaler.right;
	if (HAL_TIM_PWM_Init(&htim3) != HAL_OK)
	{
		_Error_Handler(__FILE__, __LINE__);
	}

	moter.step_l = moter.step_r = 0;
	while( moter.step_l + moter.step_r < 112 );
}

void MOTION_TURN_RIGHT(void)
{
	HAL_GPIO_WritePin(L_CW_CCW_GPIO_Port,L_CW_CCW_Pin,GPIO_PIN_SET);
	HAL_GPIO_WritePin(R_CW_CCW_GPIO_Port,R_CW_CCW_Pin,GPIO_PIN_SET);

	htim2.Init.Prescaler = 8000;
	if (HAL_TIM_PWM_Init(&htim2) != HAL_OK)
	{
		_Error_Handler(__FILE__, __LINE__);
	}

	htim3.Init.Prescaler = 8000;
	if (HAL_TIM_PWM_Init(&htim3) != HAL_OK)
	{
		_Error_Handler(__FILE__, __LINE__);
	}

	moter.step_l = moter.step_r = 0;
	while( moter.step_l + moter.step_r < 112 );
}

void MOTION_TURN_LEFT(void)
{
	HAL_GPIO_WritePin(L_CW_CCW_GPIO_Port,L_CW_CCW_Pin,GPIO_PIN_RESET);
	HAL_GPIO_WritePin(R_CW_CCW_GPIO_Port,R_CW_CCW_Pin,GPIO_PIN_RESET);

	htim2.Init.Prescaler = 8000;
	if (HAL_TIM_PWM_Init(&htim2) != HAL_OK)
	{
		_Error_Handler(__FILE__, __LINE__);
	}

	htim3.Init.Prescaler = 8000;
	if (HAL_TIM_PWM_Init(&htim3) != HAL_OK)
	{
		_Error_Handler(__FILE__, __LINE__);
	}

	moter.step_l = moter.step_r = 0;
	while( moter.step_l + moter.step_r < 112 );
}

void MOTION_U_TURN(void)
{
	HAL_GPIO_WritePin(L_CW_CCW_GPIO_Port,L_CW_CCW_Pin,GPIO_PIN_SET);
	HAL_GPIO_WritePin(R_CW_CCW_GPIO_Port,R_CW_CCW_Pin,GPIO_PIN_SET);

	htim2.Init.Prescaler = 8000;
	if (HAL_TIM_PWM_Init(&htim2) != HAL_OK)
	{
		_Error_Handler(__FILE__, __LINE__);
	}

	htim3.Init.Prescaler = 8000;
	if (HAL_TIM_PWM_Init(&htim3) != HAL_OK)
	{
		_Error_Handler(__FILE__, __LINE__);
	}

	moter.step_l = moter.step_r = 0;
	while( moter.step_l + moter.step_r < 112 );
}
