#ifndef __BSP_LED_H
#define __BSP_LED_H

#include "stm32f10x.h"
// R-��ɫ
#define LED1_GPIO_PORT    	GPIOB			              /* GPIO�˿� */
#define LED1_GPIO_CLK 	    RCC_APB2Periph_GPIOB		/* GPIO�˿�ʱ�� */
#define LED1_GPIO_PIN		GPIO_Pin_5			        /* ���ӵ�SCLʱ���ߵ�GPIO */

// G-��ɫ
#define LED2_GPIO_PORT    	GPIOB			              /* GPIO�˿� */
#define LED2_GPIO_CLK 	    RCC_APB2Periph_GPIOB		/* GPIO�˿�ʱ�� */
#define LED2_GPIO_PIN		GPIO_Pin_0			        /* ���ӵ�SCLʱ���ߵ�GPIO */

// B-��ɫ
#define LED3_GPIO_PORT    	GPIOB			              /* GPIO�˿� */
#define LED3_GPIO_CLK 	    RCC_APB2Periph_GPIOB		/* GPIO�˿�ʱ�� */
#define LED3_GPIO_PIN		GPIO_Pin_1			        /* ���ӵ�SCLʱ���ߵ�GPIO */

#define ON   1
#define OFF  0

//���
#define LED_R(a) \
if(a) \
	GPIO_ResetBits(LED_R_GPIO_PORT,LED_R_GPIO_PIN);\
else \
	GPIO_SetBits(LED_R_GPIO_PORT, LED_R_GPIO_PIN);
//�̵�
#define LED_G(a) \
if(a) \
	GPIO_ResetBits(LED_G_GPIO_PORT,LED_G_GPIO_PIN);\
else \
	GPIO_SetBits(LED_G_GPIO_PORT, LED_G_GPIO_PIN);
//����
#define LED_B(a) \
if(a) \
	GPIO_ResetBits(LED_B_GPIO_PORT,LED_B_GPIO_PIN);\
else \
	GPIO_SetBits(LED_B_GPIO_PORT, LED_B_GPIO_PIN);

/* ֱ�Ӳ����Ĵ����ķ�������IO */
#define	digitalHi(p,i)		 {p->BSRR=i;}	 //���Ϊ�ߵ�ƽ		
#define digitalLo(p,i)		 {p->BRR=i;}	 //����͵�ƽ
#define digitalToggle(p,i) {p->ODR ^=i;} //�����ת״̬


/* �������IO�ĺ� */
#define LED1_TOGGLE		 digitalToggle(LED1_GPIO_PORT,LED1_GPIO_PIN)
#define LED1_OFF		   digitalHi(LED1_GPIO_PORT,LED1_GPIO_PIN)
#define LED1_ON			   digitalLo(LED1_GPIO_PORT,LED1_GPIO_PIN)

#define LED2_TOGGLE		 digitalToggle(LED2_GPIO_PORT,LED2_GPIO_PIN)
#define LED2_OFF		   digitalHi(LED2_GPIO_PORT,LED2_GPIO_PIN)
#define LED2_ON			   digitalLo(LED2_GPIO_PORT,LED2_GPIO_PIN)

#define LED3_TOGGLE		 digitalToggle(LED3_GPIO_PORT,LED3_GPIO_PIN)
#define LED3_OFF		   digitalHi(LED3_GPIO_PORT,LED3_GPIO_PIN)
#define LED3_ON			   digitalLo(LED3_GPIO_PORT,LED3_GPIO_PIN)

//��
#define LED_RED  \
					LED1_ON;\
					LED2_OFF\
					LED3_OFF

//��
#define LED_GREEN		\
					LED1_OFF;\
					LED2_ON\
					LED3_OFF

//��
#define LED_BLUE	\
					LED1_OFF;\
					LED2_OFF\
					LED3_ON

					
//��(��+��)					
#define LED_YELLOW	\
					LED1_ON;\
					LED2_ON\
					LED3_OFF
//��(��+��)
#define LED_PURPLE	\
					LED1_ON;\
					LED2_OFF\
					LED3_ON

//��(��+��)
#define LED_CYAN \
					LED1_OFF;\
					LED2_ON\
					LED3_ON
					
//��(��+��+��)
#define LED_WHITE	\
					LED1_ON;\
					LED2_ON\
					LED3_ON
					
//��(ȫ���ر�)
#define LED_RGBOFF	\
					LED1_OFF;\
					LED2_OFF\
					LED3_OFF

void LED_GPIO_Config(void);
	
#endif  /* __BSP_LED_H */