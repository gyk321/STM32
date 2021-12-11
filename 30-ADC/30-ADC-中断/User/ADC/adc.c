#include "adc.h"

__IO uint16_t ADC_ConvertedValue;

static void ADCx_GPIO_Config(void)
{
	GPIO_InitTypeDef GPIO_InitStruct;
	
	ADC_GPIO_APBxClock_FUN(ADC_GPIO_CLK,ENABLE);
	
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_AIN;
	
	GPIO_InitStruct.GPIO_Pin = ADC_PIN;
	
	GPIO_Init(ADC_PORT, &GPIO_InitStruct);
}

static void ADCx_Mode_Config(void)
{
	ADC_InitTypeDef ADC_InitStruct;
	
	ADC_APBxClock_FUN(ADC_CLK,ENABLE);
	ADC_InitStruct.ADC_ContinuousConvMode = ENABLE;
	ADC_InitStruct.ADC_DataAlign = ADC_DataAlign_Right;
	ADC_InitStruct.ADC_ExternalTrigConv = ADC_ExternalTrigConv_None;
	ADC_InitStruct.ADC_Mode = ADC_Mode_Independent;
	ADC_InitStruct.ADC_NbrOfChannel = 1;
	ADC_InitStruct.ADC_ScanConvMode = DISABLE;
	ADC_Init(ADCx, &ADC_InitStruct);
	
	RCC_ADCCLKConfig(RCC_PCLK2_Div8);
	
	ADC_RegularChannelConfig(ADCx,ADC_CHANNEL,1,ADC_SampleTime_55Cycles5);
	ADC_ITConfig(ADCx,ADC_IT_EOC, ENABLE);
	ADC_Cmd(ADCx, ENABLE);
	
	while(ADC_GetResetCalibrationStatus(ADCx));
	
	ADC_StartCalibration(ADCx);
	while(ADC_GetCalibrationStatus(ADCx));
	ADC_SoftwareStartConvCmd(ADCx, ENABLE);
}
static void ADCx_NVIC_Config(void)
{
	NVIC_InitTypeDef NVIC_InitStruct;
	NVIC_InitStruct.NVIC_IRQChannel = ADC_IRQ;
	NVIC_InitStruct.NVIC_IRQChannelCmd = ENABLE;
	NVIC_InitStruct.NVIC_IRQChannelPreemptionPriority = 1;
	NVIC_InitStruct.NVIC_IRQChannelSubPriority = 1;
	NVIC_Init(&NVIC_InitStruct);
}
void ADCx_Init(void)
{
	ADCx_GPIO_Config();
	ADCx_Mode_Config();
	ADCx_NVIC_Config();
}

