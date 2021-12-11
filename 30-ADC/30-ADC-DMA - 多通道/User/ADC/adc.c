#include "adc.h"

__IO uint16_t ADC_ConvertedValue[NOFCHANEL] = {0,0,0,0,0,0};

static void ADCx_GPIO_Config(void)
{
	GPIO_InitTypeDef GPIO_InitStruct;
	
	ADC_GPIO_APBxClock_FUN(ADC_GPIO_CLK,ENABLE);
	
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_AIN;
	
	GPIO_InitStruct.GPIO_Pin = ADC_PIN1 | ADC_PIN2| ADC_PIN3
															| ADC_PIN4| ADC_PIN5| ADC_PIN6;
	
	GPIO_Init(ADC_PORT, &GPIO_InitStruct);
}

static void ADCx_Mode_Config(void)
{
	/*----------------DMA初始化结构体-------------*/
	DMA_InitTypeDef DMA_InitStruct;
	RCC_AHBPeriphClockCmd(RCC_AHBPeriph_DMA1, ENABLE);
	DMA_DeInit(ADC_DMA_CHANNEL);
	DMA_InitStruct.DMA_DIR = DMA_DIR_PeripheralSRC;
	DMA_InitStruct.DMA_BufferSize = NOFCHANEL;
	DMA_InitStruct.DMA_M2M = DMA_M2M_Disable;
	DMA_InitStruct.DMA_MemoryBaseAddr = (uint32_t)&ADC_ConvertedValue;
	DMA_InitStruct.DMA_MemoryDataSize = DMA_MemoryDataSize_HalfWord;
	DMA_InitStruct.DMA_MemoryInc = DMA_MemoryInc_Enable;
	DMA_InitStruct.DMA_Mode = DMA_Mode_Circular;
	DMA_InitStruct.DMA_PeripheralBaseAddr = (uint32_t)(&(ADC_x->DR));
	DMA_InitStruct.DMA_PeripheralDataSize = DMA_PeripheralDataSize_HalfWord;
	DMA_InitStruct.DMA_PeripheralInc = DMA_PeripheralInc_Disable;
	DMA_InitStruct.DMA_Priority = DMA_Priority_High;
	DMA_Init(ADC_DMA_CHANNEL, &DMA_InitStruct);
	DMA_Cmd(ADC_DMA_CHANNEL,ENABLE);
	
	/*-----------------ADC初始化结构体------------*/
	ADC_InitTypeDef ADC_InitStruct;
	ADC_APBxClock_FUN(ADC_CLK,ENABLE);
	ADC_InitStruct.ADC_ContinuousConvMode = ENABLE;
	ADC_InitStruct.ADC_DataAlign = ADC_DataAlign_Right;
	ADC_InitStruct.ADC_ExternalTrigConv = ADC_ExternalTrigConv_None;
	ADC_InitStruct.ADC_Mode = ADC_Mode_Independent;
	ADC_InitStruct.ADC_NbrOfChannel = NOFCHANEL;
	ADC_InitStruct.ADC_ScanConvMode = ENABLE;
	ADC_Init(ADC_x, &ADC_InitStruct);
	RCC_ADCCLKConfig(RCC_PCLK2_Div8);
	
	ADC_RegularChannelConfig(ADC_x,ADC_Channel_10,1,ADC_SampleTime_55Cycles5);
	ADC_RegularChannelConfig(ADC_x,ADC_Channel_11,2,ADC_SampleTime_55Cycles5);
	ADC_RegularChannelConfig(ADC_x,ADC_Channel_12,3,ADC_SampleTime_55Cycles5);
	ADC_RegularChannelConfig(ADC_x,ADC_Channel_13,4,ADC_SampleTime_55Cycles5);
	ADC_RegularChannelConfig(ADC_x,ADC_Channel_14,5,ADC_SampleTime_55Cycles5);
	ADC_RegularChannelConfig(ADC_x,ADC_Channel_15,6,ADC_SampleTime_55Cycles5);
	
	ADC_DMACmd(ADC_x,ENABLE);
	ADC_Cmd(ADC_x, ENABLE);
	ADC_ResetCalibration(ADC_x);
	while(ADC_GetResetCalibrationStatus(ADC_x));
	ADC_StartCalibration(ADC_x);
	while(ADC_GetCalibrationStatus(ADC_x));
	ADC_SoftwareStartConvCmd(ADC_x, ENABLE);
}
void ADCx_Init(void)
{
	ADCx_GPIO_Config();
	ADCx_Mode_Config();
}

