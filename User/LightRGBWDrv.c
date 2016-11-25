#include "LightRGBWDrv.h"
#include "stm8s.h"
#include "main.h"


void TIM1_Counter_Init()
{
  CLK_PeripheralClockConfig(CLK_PERIPHERAL_TIMER1, ENABLE);

  GPIO_Init(GPIOC,GPIO_PIN_6 , GPIO_MODE_OUT_PP_LOW_FAST);
  GPIO_Init(GPIOC,GPIO_PIN_7 , GPIO_MODE_OUT_PP_LOW_FAST);
  GPIO_Init(GPIOC,GPIO_PIN_3 , GPIO_MODE_OUT_PP_LOW_FAST);
  GPIO_Init(GPIOC,GPIO_PIN_4 , GPIO_MODE_OUT_PP_LOW_FAST);
  TIM1_DeInit();
  
  TIM1_TimeBaseInit(64,TIM1_COUNTERMODE_UP, 254,0);//10ms
  
  TIM1_OC1Init(TIM1_OCMODE_PWM1, TIM1_OUTPUTSTATE_ENABLE, TIM1_OUTPUTNSTATE_DISABLE, 200, TIM1_OCPOLARITY_HIGH, TIM1_OCNPOLARITY_HIGH, TIM1_OCIDLESTATE_SET, TIM1_OCNIDLESTATE_RESET);
  TIM1_OC1PreloadConfig(ENABLE);
  TIM1_OC2Init(TIM1_OCMODE_PWM1, TIM1_OUTPUTSTATE_ENABLE, TIM1_OUTPUTNSTATE_DISABLE, 200, TIM1_OCPOLARITY_HIGH, TIM1_OCNPOLARITY_HIGH, TIM1_OCIDLESTATE_SET, TIM1_OCNIDLESTATE_RESET);
  TIM1_OC2PreloadConfig(ENABLE);
  TIM1_OC3Init(TIM1_OCMODE_PWM1, TIM1_OUTPUTSTATE_ENABLE, TIM1_OUTPUTNSTATE_DISABLE, 200, TIM1_OCPOLARITY_HIGH, TIM1_OCNPOLARITY_HIGH, TIM1_OCIDLESTATE_SET, TIM1_OCNIDLESTATE_RESET);
  TIM1_OC3PreloadConfig(ENABLE);
  TIM1_OC4Init(TIM1_OCMODE_PWM1, TIM1_OUTPUTSTATE_ENABLE, 200, TIM1_OCPOLARITY_HIGH, TIM1_OCIDLESTATE_SET);
  TIM1_OC4PreloadConfig(ENABLE);
  TIM1_Cmd(ENABLE);
  TIM1_CtrlPWMOutputs(ENABLE);

}

void TIM1RGBWCtrl(uint8_t RValue, uint8_t GValue, uint8_t BValue, uint8_t WValue)
{

  TIM1_SetCompare1(RValue);
  TIM1_SetCompare2(GValue);
  TIM1_SetCompare3(BValue);
  TIM1_SetCompare4(WValue);
  
}
void TIM1RGBCtrl(uint8_t RValue, uint8_t GValue, uint8_t BValue)
{

  TIM1_SetCompare1(RValue);
  TIM1_SetCompare2(GValue);
  TIM1_SetCompare3(BValue);
 
  
}

void LightRGBWBRCtrl(uint8_t RValue, uint8_t GValue, uint8_t BValue, uint8_t WValue, uint8_t BRPercent)
{
  if(BRPercent>100)
    BRPercent=100;
  
  RValue = RValue*BRPercent/100;
  GValue = GValue*BRPercent/100;
  BValue = BValue*BRPercent/100;
  WValue = WValue*BRPercent/100;
  
  TIM1_SetCompare1(RValue);
  TIM1_SetCompare2(GValue);
  TIM1_SetCompare3(BValue);
  TIM1_SetCompare4(WValue);
  
}

void LightRGBBRCtrl(uint8_t RValue, uint8_t GValue, uint8_t BValue, uint8_t BRPercent)
{
  if(BRPercent>100)
    BRPercent=100;
  
  RValue = RValue*BRPercent/100;
  GValue = GValue*BRPercent/100;
  BValue = BValue*BRPercent/100;
  
  
  TIM1_SetCompare1(RValue);
  TIM1_SetCompare2(GValue);
  TIM1_SetCompare3(BValue);
  
  
}
