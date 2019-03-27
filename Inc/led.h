/*
 * led.h
 *
 *  Created on: 2018/12/07
 *      Author: tkthn
 */

#ifndef LED_H_
#define LED_H_

void LED_ALL_ON(void);
void LED_ALL_OFF(void);
void LED_CONTROL(unsigned char pattern);
void LED_FLICK(void);
void LED_SENSOR_ON(void);
void LED_SENSOR_OFF(void);
void LED_SENSOR_CONTROLL(unsigned char pattern);

#endif /* LED_H_ */
