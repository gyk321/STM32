#include "stm32f10x.h"      //相当于51单片机中的 #include<reg51.h>
#include "bsp_usart.h"
#include "adc.h"

extern __IO uint16_t ADC_ConvertedValue[NOFCHANEL];

float ADC_ConvertedValueLocal[NOFCHANEL];

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
		ADC_ConvertedValueLocal[0] = (float)ADC_ConvertedValue[0]/4096*3.3;
		ADC_ConvertedValueLocal[1] = (float)ADC_ConvertedValue[1]/4096*3.3;
		ADC_ConvertedValueLocal[2] = (float)ADC_ConvertedValue[2]/4096*3.3;
		ADC_ConvertedValueLocal[3] = (float)ADC_ConvertedValue[3]/4096*3.3;
		ADC_ConvertedValueLocal[4] = (float)ADC_ConvertedValue[4]/4096*3.3;
		ADC_ConvertedValueLocal[5] = (float)ADC_ConvertedValue[5]/4096*3.3;
		
		printf("\r\n The current AD value = %f V \r\n",ADC_ConvertedValueLocal[0]);
		printf("\r\n The current AD value = %f V \r\n",ADC_ConvertedValueLocal[1]);
		printf("\r\n The current AD value = %f V \r\n",ADC_ConvertedValueLocal[2]);
		printf("\r\n The current AD value = %f V \r\n",ADC_ConvertedValueLocal[3]);
		printf("\r\n The current AD value = %f V \r\n",ADC_ConvertedValueLocal[4]);
		printf("\r\n The current AD value = %f V \r\n",ADC_ConvertedValueLocal[5]);
		
		printf("\r\n\r\n");
		Delay(0xfffee);
	}
	
}


