/*
 * control.c
 *
 *  Created on: 2019/03/27
 *      Author: tkthn
 */

#include "main.h"
#include "stm32f1xx_hal.h"
#include "tim.h"
#include "control.h"
#include "global.h"

#define dt 0.001
#define KP 0.005f //0.00447f


float CONTROL_PID(float target, float measured, float *sum, float *old, float kp, float ki, float kd)

{
    float error;
    float p, i, d;

    error = target - measured;
    p = kp * error;
    *sum += error * dt;
    i = *sum * ki;
    d = kd * (error - *old);
    *old = error;

    return (p + i + d);
}

void CONTROL_P_CACL(void)
{
	if(control.enable == true)
	{
		if( ABS(sen_sl.diff_value) >= sen_def.diff_th ) sen_def.sl_th = sen_def.sl_ori_th + 10;
		else sen_def.sl_th = sen_def.sl_ori_th;
		if( ABS(sen_sr.diff_value) >= sen_def.diff_th ) sen_def.sr_th = sen_def.sr_ori_th + 10;
		else sen_def.sr_th = sen_def.sr_ori_th;

		if( (sen_sl.value >= sen_def.sl_th) && (sen_sr.value >= sen_def.sr_th) )
		{
			control.error = sen_sl.diff_value - sen_sr.diff_value;
		}
		else if( (sen_sl.value <= sen_def.sl_th) && (sen_sr.value <= sen_def.sr_th) )
		{
			control.error = 0;
		}
		else if( sen_sr.value >= sen_def.sr_th )
		{
			control.error = -2 * sen_sr.diff_value;
		}
		else
		{
			control.error = 2 * sen_sl.diff_value;
		}

		control.final = KP * control.error;

		htim2.Init.Prescaler = prescaler.left - control.final;
		if (HAL_TIM_PWM_Init(&htim2) != HAL_OK)
		{
			_Error_Handler(__FILE__, __LINE__);
		}
		htim3.Init.Prescaler = prescaler.right + control.final;
		if (HAL_TIM_PWM_Init(&htim3) != HAL_OK)
		{
			_Error_Handler(__FILE__, __LINE__);
		}
	}
}

