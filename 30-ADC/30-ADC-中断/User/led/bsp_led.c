//bsp:board suport package  �弫֧�ְ�
#include "bsp_led.h"

void LED_GPIO_Config(void)
{
	//����һ���ṹ�壬������GPIO_InitStructure,�ṹ��ԭ����GPIO_InitTypeDef ȷ��
	GPIO_InitTypeDef  GPIO_InitStruct;  
	
	RCC_APB2PeriphClockCmd(LED1_GPIO_CLK,ENABLE);
	RCC_APB2PeriphClockCmd(LED2_GPIO_CLK,ENABLE);
  RCC_APB2PeriphClockCmd(LED3_GPIO_CLK,ENABLE);
	
	GPIO_InitStruct.GPIO_Pin = LED1_GPIO_PIN;
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(LED1_GPIO_PORT, &GPIO_InitStruct);
	
	GPIO_InitStruct.GPIO_Pin = LED2_GPIO_PIN;
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(LED2_GPIO_PORT, &GPIO_InitStruct);
	
	GPIO_InitStruct.GPIO_Pin = LED3_GPIO_PIN;
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(LED3_GPIO_PORT, &GPIO_InitStruct);
	
}

