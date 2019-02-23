/*
 * motion.h
 *
 *  Created on: 2018/12/07
 *      Author: tkthn
 */

#ifndef MOTION_H_
#define MOTION_H_

void MOTION_ENABLE(void);
void MOTION_DISABLE(void);
void MOTION_TORQUE_ON(void);
void MOTION_TORQUE_OFF(void);
void MOTION_STRAIGHT(int left,int right);

#endif /* MOTION_H_ */
