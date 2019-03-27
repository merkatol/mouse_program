/*
 * control.h
 *
 *  Created on: 2019/03/27
 *      Author: tkthn
 */

#ifndef CONTROL_H_
#define CONTROL_H_

float CONTROL_PID(float target,float measured,float *sum,float *old,float kp,float ki,float kd);
void CONTROL_P_CACL(void);

#endif /* CONTROL_H_ */
