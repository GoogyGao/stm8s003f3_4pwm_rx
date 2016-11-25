#include "Uart1Dev.h"
#include "stm8s.h"


void uart1_config(void)
{
  CLK_PeripheralClockConfig(CLK_PERIPHERAL_UART1, ENABLE);
  
  UART1_DeInit();
  
  GPIO_ExternalPullUpConfig(GPIOD, GPIO_PIN_5, ENABLE);//TX
  GPIO_ExternalPullUpConfig(GPIOD, GPIO_PIN_6, ENABLE);//RX
  
  
  UART1_Init(9600, UART1_WORDLENGTH_8D, UART1_STOPBITS_1, UART1_PARITY_NO, UART1_SYNCMODE_CLOCK_DISABLE, UART1_MODE_TXRX_ENABLE);
  
  UART1_ITConfig(UART1_IT_RXNE,ENABLE);
  
  UART1_Cmd(ENABLE);

  /* Enable general interrupts */
    enableInterrupts(); 
}


void Uart1SendByte(uint8_t data)
{
  // Usart1_SendData8 ((unsigned char) data);
  UART1_SendData8( data);
  
  // Loop until the end of tranmission
  while (UART1_GetFlagStatus(UART1_FLAG_TXE) == RESET);
}



uint8_t Uart1SendString(uint8_t *pBuf)
{
    unsigned char ucPos;
  if (!pBuf)
    return 0;
  
  ucPos = 0;
  do {
    if (pBuf[ucPos] != '\0') {
      Uart1SendByte(pBuf[ucPos ++]);
    } else 
      break;
  } while (1);
  
  return 1;


}



