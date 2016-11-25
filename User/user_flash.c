#include "user_flash.h"
#include "stm8s_flash.h"
void user_flash_init(void){
	/* Define FLASH programming time */
    FLASH_SetProgrammingTime(FLASH_PROGRAMTIME_STANDARD);
}
uint8_t user_Read_Flash(uint32_t addr){
    FLASH_DeInit();                             //还原默认寄存器值
    FLASH_Unlock(FLASH_MEMTYPE_DATA);           //EEPROM解锁。 
    uint8_t readData = FLASH_ReadByte(addr);    //读出来查看是否正确。
    FLASH_Lock(FLASH_MEMTYPE_DATA);             //上锁 
    FLASH_DeInit();                             //回复寄存器值 
    FLASH_Unlock(FLASH_MEMTYPE_DATA);           //解锁 
    return readData;
}
void user_Write_Flash(uint32_t addr,uint8_t data){
    FLASH_DeInit();                             //还原默认寄存器值
    FLASH_Unlock(FLASH_MEMTYPE_DATA);           //EEPROM解锁。 
    uint8_t writeData = data;
    FLASH_ProgramByte(addr, writeData);
    FLASH_Lock(FLASH_MEMTYPE_DATA);             //上锁 
    FLASH_DeInit();                             //回复寄存器值 
    FLASH_Unlock(FLASH_MEMTYPE_DATA);           //解锁 
}
void user_Erase_Flash(uint32_t addr){
    FLASH_DeInit();                             //还原默认寄存器值
    FLASH_Unlock(FLASH_MEMTYPE_DATA);           //EEPROM解锁。 
    FLASH_EraseByte(addr);    
    FLASH_Lock(FLASH_MEMTYPE_DATA);             //上锁 
    FLASH_DeInit();                             //回复寄存器值 
    FLASH_Unlock(FLASH_MEMTYPE_DATA);           //解锁 
    
}
