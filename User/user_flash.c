#include "user_flash.h"
#include "stm8s_flash.h"
void user_flash_init(void){
	/* Define FLASH programming time */
    FLASH_SetProgrammingTime(FLASH_PROGRAMTIME_STANDARD);
}
uint8_t user_Read_Flash(uint32_t addr){
    FLASH_DeInit();                             //��ԭĬ�ϼĴ���ֵ
    FLASH_Unlock(FLASH_MEMTYPE_DATA);           //EEPROM������ 
    uint8_t readData = FLASH_ReadByte(addr);    //�������鿴�Ƿ���ȷ��
    FLASH_Lock(FLASH_MEMTYPE_DATA);             //���� 
    FLASH_DeInit();                             //�ظ��Ĵ���ֵ 
    FLASH_Unlock(FLASH_MEMTYPE_DATA);           //���� 
    return readData;
}
void user_Write_Flash(uint32_t addr,uint8_t data){
    FLASH_DeInit();                             //��ԭĬ�ϼĴ���ֵ
    FLASH_Unlock(FLASH_MEMTYPE_DATA);           //EEPROM������ 
    uint8_t writeData = data;
    FLASH_ProgramByte(addr, writeData);
    FLASH_Lock(FLASH_MEMTYPE_DATA);             //���� 
    FLASH_DeInit();                             //�ظ��Ĵ���ֵ 
    FLASH_Unlock(FLASH_MEMTYPE_DATA);           //���� 
}
void user_Erase_Flash(uint32_t addr){
    FLASH_DeInit();                             //��ԭĬ�ϼĴ���ֵ
    FLASH_Unlock(FLASH_MEMTYPE_DATA);           //EEPROM������ 
    FLASH_EraseByte(addr);    
    FLASH_Lock(FLASH_MEMTYPE_DATA);             //���� 
    FLASH_DeInit();                             //�ظ��Ĵ���ֵ 
    FLASH_Unlock(FLASH_MEMTYPE_DATA);           //���� 
    
}
