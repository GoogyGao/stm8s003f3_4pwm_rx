#ifndef _MAIN_H_
#define _MAIN_H_


#define LED_GPIO_PIN3           GPIO_PIN_3
#define GPIOx GPIOC
#define CODE_ZERN(GPIO_PINx)   {GPIOx->ODR = (uint8_t)GPIO_PINx;\
                                GPIOx->ODR = (uint8_t)GPIO_PINx;\
                                GPIOx->ODR = (uint8_t)GPIO_PINx;\
                                GPIOx->ODR = (uint8_t)0;\
                                GPIOx->ODR = (uint8_t)0;}  

#define CODE_ZERN1(GPIO_PINx)   {GPIOx->ODR = (uint8_t)GPIO_PINx;\
                                GPIOx->ODR = (uint8_t)GPIO_PINx;\
                                GPIOx->ODR = (uint8_t)GPIO_PINx;\
                                GPIOx->ODR = (uint8_t)0;\
                                GPIOx->ODR = (uint8_t)0;}  

#define CODE_ONE(GPIO_PINx)    {GPIOx->ODR = (uint8_t)GPIO_PINx;\
                                GPIOx->ODR = (uint8_t)GPIO_PINx;\
                                GPIOx->ODR = (uint8_t)GPIO_PINx;\
                                GPIOx->ODR = (uint8_t)GPIO_PINx;\
                                GPIOx->ODR = (uint8_t)GPIO_PINx;\
                                GPIOx->ODR = (uint8_t)GPIO_PINx;\
                                GPIOx->ODR = (uint8_t)0;}

#define CODE_ONE1(GPIO_PINx)    {GPIOx->ODR = (uint8_t)GPIO_PINx;\
                                GPIOx->ODR = (uint8_t)GPIO_PINx;\
                                GPIOx->ODR = (uint8_t)GPIO_PINx;\
                                GPIOx->ODR = (uint8_t)GPIO_PINx;\
                                GPIOx->ODR = (uint8_t)GPIO_PINx;\
                                GPIOx->ODR = (uint8_t)GPIO_PINx;\
                                GPIOx->ODR = (uint8_t)0;\
                                GPIOx->ODR = (uint8_t)0;\
                                }

#define SWITCHREAD              





void Delay(uint32_t cnt);


#endif