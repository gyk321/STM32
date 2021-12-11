#include "stm32f10x.h"      //相当于51单片机中的 #include<reg51.h>
#include "bsp_usart.h"
#include "adc.h"

extern __IO uint16_t ADC_ConvertedValue;

float ADC_ConvertedValueLocal;

void Delay(__IO uint32_t nCount)
{
  for(; nCount != 0; nCount--);
} 

int main(void)
{
	USART_Config();
	
	ADCx_Init();
	
	printf("--------------这是一个ADC测试实验-----------------");
	while(1)
	{
		ADC_ConvertedValueLocal = (float)ADC_ConvertedValue/4096*3.3;
		printf("\r\n The current AD value = 0x%04X \r\n",ADC_ConvertedValue);
		printf("\r\n The current AD value = %f V \r\n",ADC_ConvertedValueLocal);
		printf("\r\n\r\n");
		Delay(0xfffee);
	}
	
}


