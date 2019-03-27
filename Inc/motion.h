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
void MOTION_STRAIGHT(int left,int right);
void MOTION_TURN_RIGHT(void);
void MOTION_TURN_LEFT(void);
void MOTION_U_TURN(void);

#endif /* MOTION_H_ */
