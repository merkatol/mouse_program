/*
 * global.h
 *
 *  Created on: 2019/03/06
 *      Author: tkthn
 */

#ifndef GLOBAL_H_
#define GLOBAL_H_
#ifdef __cplusplus
 extern "C" {
#endif
#include <stdint.h>
#include <stdbool.h>


#define ABS(IN) ((IN) < 0 ? - (IN) : (IN))

#define true 1
#define false 0

#define on 1
#define off 0


typedef struct
{
	volatile int step_l;
	volatile int step_r;
}t_moter;
extern t_moter moter;

typedef struct
{
	uint16_t fl_th;
	uint16_t sl_th;
	uint16_t sr_th;
	uint16_t fr_th;
	uint16_t fl_center;
	uint16_t fr_center;
	uint16_t diff_th;
	uint16_t sl_ori_th;
	uint16_t sr_ori_th;
}t_sensordef;
extern t_sensordef sen_def;

typedef struct
{
	uint16_t value;
	uint16_t p_value;
	uint16_t diff_value;
	float error;
	unsigned char is_wall;
	unsigned char is_turn;
}t_sensor;
extern t_sensor sen_fl;
extern t_sensor sen_sl;
extern t_sensor sen_sr;
extern t_sensor sen_fr;
extern t_sensor sen_front;

typedef struct
{
	float final;
	float error;
	unsigned char enable;
}t_control;
extern t_control control;

typedef struct
{
	int16_t left;
	int16_t right;
}t_prescaler;
extern t_prescaler prescaler;

#ifdef __cplusplus
}
#endif
#endif /* GLOBAL_H_ */
