#ifndef _ADC_H
#define _ADC_H

#include "stm32f10x.h"

#define    ADC_APBxClock_FUN             RCC_APB2PeriphClockCmd
#define    ADC_CLK                       RCC_APB2Periph_ADC1
// ע�⣺����ADC�ɼ���IO����û�и��ã�����ɼ���ѹ����Ӱ��
#define    ADC_GPIO_APBxClock_FUN        RCC_APB2PeriphClockCmd
#define		 ADC_DMA_CHANNEL							 DMA1_Channel1

//����12λ��ADC��3.3V��ADCֵΪ0xfff,�¶�Ϊ25��ʱ��Ӧ�ĵ�ѹֵΪ1.43V��0x6EE
#define 	V25  														0x6EE	 
//б�� ÿ���϶�4.3mV ��Ӧÿ���϶�0x05
#define 		AVG_SLOPE 										0x05 
// ADC1 ��Ӧ DMA1ͨ��1��ADC3��ӦDMA2ͨ��5��ADC2û��DMA����
#define    ADC_x                         ADC1
#define    ADC_DMA_CLK                   RCC_AHBPeriph_DMA1

void ADCx_Init(void);
#endif
