/**
  ******************************************************************************
  * File Name          : ADC.c
  * Description        : This file provides code for the configuration
  *                      of the ADC instances.
  ******************************************************************************
  ** This notice applies to any and all portions of this file
  * that are not between comment pairs USER CODE BEGIN and
  * USER CODE END. Other portions of this file, whether 
  * inserted by the user or by software development tools
  * are owned by their respective copyright owners.
  *
  * COPYRIGHT(c) 2019 STMicroelectronics
  *
  * Redistribution and use in source and binary forms, with or without modification,
  * are permitted provided that the following conditions are met:
  *   1. Redistributions of source code must retain the above copyright notice,
  *      this list of conditions and the following disclaimer.
  *   2. Redistributions in binary form must reproduce the above copyright notice,
  *      this list of conditions and the following disclaimer in the documentation
  *      and/or other materials provided with the distribution.
  *   3. Neither the name of STMicroelectronics nor the names of its contributors
  *      may be used to endorse or promote products derived from this software
  *      without specific prior written permission.
  *
  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
  * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
  * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
  * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
  * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
  * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
  * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
  *
  ******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/
#include "adc.h"
#include "gpio.h"

/* USER CODE BEGIN 0 */

ADC_HandleTypeDef hadc1;

#include "global.h"

/* USER CODE END 0 */

ADC_HandleTypeDef hadc1;
ADC_HandleTypeDef hadc2;

/* ADC1 init function */
void MX_ADC1_Init(void)
{
  ADC_ChannelConfTypeDef sConfig;

    /**Common config 
    */
  hadc1.Instance = ADC1;
  hadc1.Init.ScanConvMode = ADC_SCAN_DISABLE;
  hadc1.Init.ContinuousConvMode = DISABLE;
  hadc1.Init.DiscontinuousConvMode = DISABLE;
  hadc1.Init.ExternalTrigConv = ADC_SOFTWARE_START;
  hadc1.Init.DataAlign = ADC_DATAALIGN_RIGHT;
  hadc1.Init.NbrOfConversion = 1;
  if (HAL_ADC_Init(&hadc1) != HAL_OK)
  {
    _Error_Handler(__FILE__, __LINE__);
  }

    /**Configure Regular Channel 
    */
  sConfig.Channel = ADC_CHANNEL_10;
  sConfig.Rank = ADC_REGULAR_RANK_1;
  sConfig.SamplingTime = ADC_SAMPLETIME_55CYCLES_5;
  if (HAL_ADC_ConfigChannel(&hadc1, &sConfig) != HAL_OK)
  {
    _Error_Handler(__FILE__, __LINE__);
  }

}
/* ADC2 init function */
void MX_ADC2_Init(void)
{
  ADC_ChannelConfTypeDef sConfig;

    /**Common config 
    */
  hadc2.Instance = ADC2;
  hadc2.Init.ScanConvMode = ADC_SCAN_DISABLE;
  hadc2.Init.ContinuousConvMode = DISABLE;
  hadc2.Init.DiscontinuousConvMode = DISABLE;
  hadc2.Init.ExternalTrigConv = ADC_SOFTWARE_START;
  hadc2.Init.DataAlign = ADC_DATAALIGN_RIGHT;
  hadc2.Init.NbrOfConversion = 1;
  if (HAL_ADC_Init(&hadc2) != HAL_OK)
  {
    _Error_Handler(__FILE__, __LINE__);
  }

    /**Configure Regular Channel 
    */
  sConfig.Channel = ADC_CHANNEL_4;
  sConfig.Rank = ADC_REGULAR_RANK_1;
  sConfig.SamplingTime = ADC_SAMPLETIME_1CYCLE_5;
  if (HAL_ADC_ConfigChannel(&hadc2, &sConfig) != HAL_OK)
  {
    _Error_Handler(__FILE__, __LINE__);
  }

}

void HAL_ADC_MspInit(ADC_HandleTypeDef* adcHandle)
{

  GPIO_InitTypeDef GPIO_InitStruct;
  if(adcHandle->Instance==ADC1)
  {
  /* USER CODE BEGIN ADC1_MspInit 0 */

  /* USER CODE END ADC1_MspInit 0 */
    /* ADC1 clock enable */
    __HAL_RCC_ADC1_CLK_ENABLE();
  
    /**ADC1 GPIO Configuration    
    PC0     ------> ADC1_IN10
    PC1     ------> ADC1_IN11
    PC2     ------> ADC1_IN12
    PC3     ------> ADC1_IN13 
    */
    GPIO_InitStruct.Pin = ADC1_Pin|ADC2_Pin|ADC3_Pin|ADC4_Pin;
    GPIO_InitStruct.Mode = GPIO_MODE_ANALOG;
    HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

  /* USER CODE BEGIN ADC1_MspInit 1 */

  /* USER CODE END ADC1_MspInit 1 */
  }
  else if(adcHandle->Instance==ADC2)
  {
  /* USER CODE BEGIN ADC2_MspInit 0 */

  /* USER CODE END ADC2_MspInit 0 */
    /* ADC2 clock enable */
    __HAL_RCC_ADC2_CLK_ENABLE();
  
    /**ADC2 GPIO Configuration    
    PA4     ------> ADC2_IN4 
    */
    GPIO_InitStruct.Pin = BATTERY_Pin;
    GPIO_InitStruct.Mode = GPIO_MODE_ANALOG;
    HAL_GPIO_Init(BATTERY_GPIO_Port, &GPIO_InitStruct);

  /* USER CODE BEGIN ADC2_MspInit 1 */

  /* USER CODE END ADC2_MspInit 1 */
  }
}

void HAL_ADC_MspDeInit(ADC_HandleTypeDef* adcHandle)
{

  if(adcHandle->Instance==ADC1)
  {
  /* USER CODE BEGIN ADC1_MspDeInit 0 */

  /* USER CODE END ADC1_MspDeInit 0 */
    /* Peripheral clock disable */
    __HAL_RCC_ADC1_CLK_DISABLE();
  
    /**ADC1 GPIO Configuration    
    PC0     ------> ADC1_IN10
    PC1     ------> ADC1_IN11
    PC2     ------> ADC1_IN12
    PC3     ------> ADC1_IN13 
    */
    HAL_GPIO_DeInit(GPIOC, ADC1_Pin|ADC2_Pin|ADC3_Pin|ADC4_Pin);

  /* USER CODE BEGIN ADC1_MspDeInit 1 */

  /* USER CODE END ADC1_MspDeInit 1 */
  }
  else if(adcHandle->Instance==ADC2)
  {
  /* USER CODE BEGIN ADC2_MspDeInit 0 */

  /* USER CODE END ADC2_MspDeInit 0 */
    /* Peripheral clock disable */
    __HAL_RCC_ADC2_CLK_DISABLE();
  
    /**ADC2 GPIO Configuration    
    PA4     ------> ADC2_IN4 
    */
    HAL_GPIO_DeInit(BATTERY_GPIO_Port, BATTERY_Pin);

  /* USER CODE BEGIN ADC2_MspDeInit 1 */

  /* USER CODE END ADC2_MspDeInit 1 */
  }
} 

/* USER CODE BEGIN 1 */

uint16_t ADC_FL(void)
{
	uint16_t fl_value = 0;
	ADC_ChannelConfTypeDef sConfig;

	HAL_GPIO_WritePin(SENSOR4_GPIO_Port,SENSOR4_Pin,GPIO_PIN_SET);
	sConfig.Rank = ADC_REGULAR_RANK_1;
	sConfig.SamplingTime = ADC_SAMPLETIME_55CYCLES_5;
	sConfig.Channel = ADC_CHANNEL_13;
	HAL_ADC_ConfigChannel(&hadc1, &sConfig);
	HAL_ADC_Start(&hadc1);
	while( HAL_ADC_PollForConversion(&hadc1,100) != HAL_OK );
	fl_value = HAL_ADC_GetValue(&hadc1);
	HAL_ADC_Stop(&hadc1);
	HAL_GPIO_WritePin(SENSOR4_GPIO_Port,SENSOR4_Pin,GPIO_PIN_RESET);

	return fl_value;
}

uint16_t ADC_SL(void)
{
	uint16_t sl_value = 0;
	ADC_ChannelConfTypeDef sConfig;

	HAL_GPIO_WritePin(SENSOR3_GPIO_Port,SENSOR3_Pin,GPIO_PIN_SET);
	sConfig.Rank = ADC_REGULAR_RANK_1;
	sConfig.SamplingTime = ADC_SAMPLETIME_55CYCLES_5;
	sConfig.Channel = ADC_CHANNEL_12;
	HAL_ADC_ConfigChannel(&hadc1, &sConfig);
	HAL_ADC_Start(&hadc1);
	while( HAL_ADC_PollForConversion(&hadc1,100) != HAL_OK );
	sl_value = HAL_ADC_GetValue(&hadc1);
	HAL_ADC_Stop(&hadc1);
	HAL_GPIO_WritePin(SENSOR3_GPIO_Port,SENSOR3_Pin,GPIO_PIN_RESET);

	return sl_value;
}

uint16_t ADC_SR(void)
{
	uint16_t sr_value = 0;
	ADC_ChannelConfTypeDef sConfig;

	HAL_GPIO_WritePin(SENSOR2_GPIO_Port,SENSOR2_Pin,GPIO_PIN_SET);
	sConfig.Rank = ADC_REGULAR_RANK_1;
	sConfig.SamplingTime = ADC_SAMPLETIME_55CYCLES_5;
	sConfig.Channel = ADC_CHANNEL_11;
	HAL_ADC_ConfigChannel(&hadc1, &sConfig);
	HAL_ADC_Start(&hadc1);
	while( HAL_ADC_PollForConversion(&hadc1,100) != HAL_OK );
	sr_value = HAL_ADC_GetValue(&hadc1);
	HAL_ADC_Stop(&hadc1);
	HAL_GPIO_WritePin(SENSOR2_GPIO_Port,SENSOR2_Pin,GPIO_PIN_RESET);

	return sr_value;
}

uint16_t ADC_FR(void)
{
	uint16_t fr_value = 0;
	ADC_ChannelConfTypeDef sConfig;

	HAL_GPIO_WritePin(SENSOR1_GPIO_Port,SENSOR1_Pin,GPIO_PIN_SET);
	sConfig.Rank = ADC_REGULAR_RANK_1;
	sConfig.SamplingTime = ADC_SAMPLETIME_55CYCLES_5;
	sConfig.Channel = ADC_CHANNEL_10;
	HAL_ADC_ConfigChannel(&hadc1, &sConfig);
	HAL_ADC_Start(&hadc1);
	while( HAL_ADC_PollForConversion(&hadc1,100) != HAL_OK );
	fr_value = HAL_ADC_GetValue(&hadc1);
	HAL_ADC_Stop(&hadc1);
	HAL_GPIO_WritePin(SENSOR1_GPIO_Port,SENSOR1_Pin,GPIO_PIN_RESET);

	return fr_value;
}
void ADC_UPDATE(void)
{
	sen_fl.p_value = sen_fl.value;
	sen_fl.value = ADC_FL();
	sen_fl.diff_value = ABS(sen_fl.value - sen_fl.p_value);

	sen_fr.p_value = sen_fr.value;
	sen_fr.value = ADC_FR();
	sen_fr.diff_value = ABS(sen_fr.value - sen_fr.p_value);

	if(sen_fl.value + sen_fr.value >= sen_def.fl_th + sen_def.fr_th) sen_front.is_wall = true;
	else sen_front.is_wall = false;
	if(sen_fl.value + sen_fr.value >= sen_def.fl_center + sen_def.fl_center) sen_front.is_turn = true;
	else sen_fl.is_turn = false;


	sen_sl.p_value = sen_sl.value;
	sen_sl.value = ADC_SL();
	sen_sl.diff_value = sen_sl.value - sen_sl.p_value;
	if(sen_sl.value >= sen_def.sl_th) sen_sl.is_wall = true;
	else sen_sl.is_wall = false;

	sen_sr.p_value = sen_sr.value;
	sen_sr.value = ADC_SR();
	sen_sr.diff_value = sen_sr.value - sen_sr.p_value;
	if(sen_sr.value >= sen_def.sr_th) sen_sr.is_wall = true;
	else sen_sr.is_wall = false;
}

/* USER CODE END 1 */

/**
  * @}
  */

/**
  * @}
  */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
