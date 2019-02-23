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
#include "gpio.h"
#include "led.h"
#include "motion.h"

TIM_HandleTypeDef htim2;
TIM_HandleTypeDef htim8;
TIM_OC_InitTypeDef sConfigOC;

void MOTION_STRAIGHT(void)
{
	  htim2.Init.Prescaler = 8000;
	  sConfigOC.OCMode = TIM_OCMODE_PWM1;
	  sConfigOC.Pulse = 1;
	  sConfigOC.OCPolarity = TIM_OCPOLARITY_HIGH;
	  sConfigOC.OCFastMode = TIM_OCFAST_DISABLE;
	  if (HAL_TIM_PWM_ConfigChannel(&htim2, &sConfigOC, TIM_CHANNEL_3) != HAL_OK)
	  {
	    _Error_Handler(__FILE__, __LINE__);
	  }

	  htim5.Init.Prescaler = 8000;
	  sConfigOC.OCMode = TIM_OCMODE_PWM1;
	  sConfigOC.Pulse = 1;
	  sConfigOC.OCPolarity = TIM_OCPOLARITY_HIGH;
	  sConfigOC.OCFastMode = TIM_OCFAST_DISABLE;
	  if (HAL_TIM_PWM_ConfigChannel(&htim5, &sConfigOC, TIM_CHANNEL_4) != HAL_OK)
	  {
	    _Error_Handler(__FILE__, __LINE__);
	  }

    HAL_GPIO_WritePin( MOTER_EN_GPIO_Port , MOTER_EN_Pin , GPIO_PIN_SET );
    HAL_GPIO_WritePin( R_CW_CCW_GPIO_Port , R_CW_CCW_Pin , GPIO_PIN_SET );
    HAL_GPIO_WritePin( L_CW_CCW_GPIO_Port , L_CW_CCW_Pin , GPIO_PIN_SET );
}
