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
#include "stdint.h"
#endif /* GLOBAL_H_ */


 /***********define***************/

 #define TRUE 1
 #define FALSE 0

 #define ON 1
 #define OFF 0


 /*************struct**************/

 typedef struct
 {
	 uint8_t wall;
 }sensor_t;

 extern sensor_t sen_l;
 extern sensor_t sen_fl;
 extern sensor_t sen_fr;
 extern sensor_t sen_r;
 extern sensor_t sen_front;
