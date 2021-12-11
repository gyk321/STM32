#include "stm32f10x.h"     
#include "bsp_usart.h"
#include "adc.h"

extern __IO uint16_t ADC_ConvertedValue;

uint16_t Current_Temp;

void Delay(__IO uint32_t nCount)
{
  for(; nCount != 0; nCount--);
} 

int main(void)
{
	USART_Config();
	
	ADCx_Init();
	
	printf("--------------这是一个内部温度传感器实验-----------------");
	while(1)
	{
		Delay(0xffffee);
		
		Current_Temp = (V25 - ADC_ConvertedValue) / AVG_SLOPE + 25;

		
		printf("\r\n The current AD tem = %3d ℃\r\n",Current_Temp);

		
	}
	
}


