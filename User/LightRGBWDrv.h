#ifndef _LIGHTRGBWDRV_H_
#define _LIGHTRGBWDRV_H_

#include "stm8s.h"


void TIM1_Counter_Init();
void TIM1RGBWCtrl(uint8_t RValue, uint8_t GValue, uint8_t BValue, uint8_t WValue);
void TIM1RGBCtrl(uint8_t RValue, uint8_t GValue, uint8_t BValue);
void LightRGBWBRCtrl(uint8_t RValue, uint8_t GValue, uint8_t BValue, uint8_t WValue, uint8_t BRPercent);
void LightRGBBRCtrl(uint8_t RValue, uint8_t GValue, uint8_t BValue, uint8_t BRPercent);




#endif