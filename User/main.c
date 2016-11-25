/**
  ******************************************************************************
  * @file    Project/main.c 
  * @author  MCD Application Team
  * @version V2.1.0
  * @date    18-November-2011
  * @brief   Main program body
  ******************************************************************************
  * @attention
  *
  * THE PRESENT FIRMWARE WHICH IS FOR GUIDANCE ONLY AIMS AT PROVIDING CUSTOMERS
  * WITH CODING INFORMATION REGARDING THEIR PRODUCTS IN ORDER FOR THEM TO SAVE
  * TIME. AS A RESULT, STMICROELECTRONICS SHALL NOT BE HELD LIABLE FOR ANY
  * DIRECT, INDIRECT OR CONSEQUENTIAL DAMAGES WITH RESPECT TO ANY CLAIMS ARISING
  * FROM THE CONTENT OF SUCH FIRMWARE AND/OR THE USE MADE BY CUSTOMERS OF THE
  * CODING INFORMATION CONTAINED HEREIN IN CONNECTION WITH THEIR PRODUCTS.
  *
  * <h2><center>&copy; COPYRIGHT 2011 STMicroelectronics</center></h2>
  ******************************************************************************
  */ 


/* Includes ------------------------------------------------------------------*/
#include "stm8s.h"
#include "main.h"
#include "Uart1Dev.h"
#include "LightRGBWDrv.h"
/* Private defines -----------------------------------------------------------*/
uint8_t USART1_ReceiveDataBuf[32];
uint8_t Buff_Cnt ;
uint8_t USART1_FLAG ;
/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/



void Delay(uint32_t cnt)
{
  uint32_t count = 500;
  for(; cnt > 0;cnt --)
  {
    for(; count > 0;count --)
    {
    }
  }
}


void main(void)
{
  CLK_DeInit();
  /* Initialization of the clock ;Clock divider to HSI/1 */
  CLK_HSIPrescalerConfig(CLK_PRESCALER_HSIDIV1);
  CLK_HSECmd(ENABLE);
  //CLK_HSICmd(ENABLE);
  
  uart1_config();//RX IRQ
  
  TIM1_Counter_Init();//4PWM 
  
  //TIM1RGBWCtrl(128,128,128,128);//50% PWM  test
  
  while (1)
  {
    
    if(USART1_FLAG==1)//when RX IRQ produce
    {
      Buff_Cnt=0;
      USART1_FLAG=0;
      //TODO:MESSAGE DEAL WITH     data array:USART1_ReceiveDataBuf[32]
      
    
    
    }
    

  }
}




#ifdef USE_FULL_ASSERT

/**
  * @brief  Reports the name of the source file and the source line number
  *   where the assert_param error has occurred.
  * @param file: pointer to the source file name
  * @param line: assert_param error line source number
  * @retval : None
  */
void assert_failed(u8* file, u32 line)
{ 
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */

  /* Infinite loop */
  while (1)
  {
  }
}
#endif

/******************* (C) COPYRIGHT 2011 STMicroelectronics *****END OF FILE****/
