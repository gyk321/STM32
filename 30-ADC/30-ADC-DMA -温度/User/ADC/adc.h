#ifndef _ADC_H
#define _ADC_H

#include "stm32f10x.h"

#define    ADC_APBxClock_FUN             RCC_APB2PeriphClockCmd
#define    ADC_CLK                       RCC_APB2Periph_ADC1
// 注意：用作ADC采集的IO必须没有复用，否则采集电压会有影响
#define    ADC_GPIO_APBxClock_FUN        RCC_APB2PeriphClockCmd
#define		 ADC_DMA_CHANNEL							 DMA1_Channel1

//对于12位的ADC，3.3V的ADC值为0xfff,温度为25度时对应的电压值为1.43V即0x6EE
#define 	V25  														0x6EE	 
//斜率 每摄氏度4.3mV 对应每摄氏度0x05
#define 		AVG_SLOPE 										0x05 
// ADC1 对应 DMA1通道1，ADC3对应DMA2通道5，ADC2没有DMA功能
#define    ADC_x                         ADC1
#define    ADC_DMA_CLK                   RCC_AHBPeriph_DMA1

void ADCx_Init(void);
#endif
