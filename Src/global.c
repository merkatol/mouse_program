/*
 * global.c
 *
 *  Created on: 2019/03/06
 *      Author: tkthn
 */

#include "global.h"


t_moter moter = {0,0};

//t_sensordef sen_def = {fl_th,sl_th,sr_th,fr_th,fl_center,fr_center,diff_th,sl_ori_th,sr_ori_th};
t_sensordef sen_def = {0,10,15,0 ,0,0 ,10,10,15};

t_sensor sen_fl = {0,0,0,0,0};
t_sensor sen_sl = {0,0,0,0,0};
t_sensor sen_sr = {0,0,0,0,0};
t_sensor sen_fr = {0,0,0,0,0};
t_sensor sen_front = {0,0,0,0,0};

t_control control = {0,0,0};

t_prescaler prescaler = {0,0};
