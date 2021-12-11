#include "adc.h"

__IO uint16_t ADC_ConvertedValue;

#define ADC1_DR_Address    ((u32)ADC1_BASE+0x4c)

static void ADCx_GPIO_Config(void)
{
	/* Enable ADC1 and GPIOC clock */
	ADC_GPIO_APBxClock_FUN(ADC_CLK,ENABLE);
	/* Enable DMA clock */
	RCC_AHBPeriphClockCmd(RCC_AHBPeriph_DMA1, ENABLE);
}

static void ADCx_Mode_Config(void)
{
	/*----------------DMA初始化结构体-------------*/
	DMA_InitTypeDef DMA_InitStruct;
	
	DMA_DeInit(ADC_DMA_CHANNEL);
	DMA_InitStruct.DMA_DIR = DMA_DIR_PeripheralSRC;
	DMA_InitStruct.DMA_BufferSize = 1;
	DMA_InitStruct.DMA_M2M = DMA_M2M_Disable;
	DMA_InitStruct.DMA_MemoryBaseAddr = (uint32_t)&ADC_ConvertedValue;
	DMA_InitStruct.DMA_MemoryDataSize = DMA_MemoryDataSize_HalfWord;
	DMA_InitStruct.DMA_MemoryInc = DMA_MemoryInc_Disable;
	DMA_InitStruct.DMA_Mode = DMA_Mode_Circular;
	DMA_InitStruct.DMA_PeripheralBaseAddr = ADC1_DR_Address;
	DMA_InitStruct.DMA_PeripheralDataSize = DMA_PeripheralDataSize_HalfWord;
	DMA_InitStruct.DMA_PeripheralInc = DMA_PeripheralInc_Disable;
	DMA_InitStruct.DMA_Priority = DMA_Priority_High;
	DMA_Init(ADC_DMA_CHANNEL, &DMA_InitStruct);
	DMA_Cmd(ADC_DMA_CHANNEL,ENABLE);
	
	/*-----------------ADC初始化结构体------------*/
	ADC_InitTypeDef ADC_InitStruct;

	ADC_InitStruct.ADC_ContinuousConvMode = ENABLE;
	ADC_InitStruct.ADC_DataAlign = ADC_DataAlign_Right;
	ADC_InitStruct.ADC_ExternalTrigConv = ADC_ExternalTrigConv_None;
	ADC_InitStruct.ADC_Mode = ADC_Mode_Independent;
	ADC_InitStruct.ADC_NbrOfChannel = 1;
	ADC_InitStruct.ADC_ScanConvMode = ENABLE;
	ADC_Init(ADC_x, &ADC_InitStruct);
	RCC_ADCCLKConfig(RCC_PCLK2_Div8);
	
	ADC_RegularChannelConfig(ADC_x,ADC_Channel_16,1,ADC_SampleTime_239Cycles5);
	ADC_TempSensorVrefintCmd(ENABLE); 
	
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

