#ifndef _USER_FLASH_H_
#define _USER_FLASH_H_
#include "stm8s.h"
void user_flash_init(void);
void user_Write_Flash(uint32_t addr,uint8_t data);
uint8_t user_Read_Flash(uint32_t addr);
void user_Erase_Flash(uint32_t addr);

#endif

