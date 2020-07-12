#include "sys.h"
#include "delay.h"
#include "usart.h"
#include "led.h"
/************************************************
 ALIENTEK ̽����STM32F407������ ʵ��1
 �����ʵ��-HAL��汾
 ����֧�֣�www.openedv.com
 �Ա����̣�http://eboard.taobao.com 
 ��ע΢�Ź���ƽ̨΢�źţ�"����ԭ��"����ѻ�ȡSTM32���ϡ�
 ������������ӿƼ����޹�˾  
 ���ߣ�����ԭ�� @ALIENTEK
************************************************/


/*������������ʹ��HAL�⺯��ʵ�ֿ���IO�����*/

int main(void)
{ 
    HAL_Init();                    	//��ʼ��HAL��    
    Stm32_Clock_Init(336,8,2,7);  	//����ʱ��,168Mhz
	delay_init(168);               	//��ʼ����ʱ����
	LED_Init();						//��ʼ��LED	
	
	while(1)
	{
        HAL_GPIO_WritePin(GPIOF,GPIO_PIN_9,GPIO_PIN_RESET); 	//LED0��Ӧ����PF9���ͣ�������ͬ��LED0(0)
        HAL_GPIO_WritePin(GPIOF,GPIO_PIN_10,GPIO_PIN_SET);   	//LED1��Ӧ����PF10���ߣ��𣬵�ͬ��LED1(1)
        delay_ms(500);											//��ʱ500ms
        HAL_GPIO_WritePin(GPIOF,GPIO_PIN_9,GPIO_PIN_SET);   	//LED0��Ӧ����PF9���ߣ��𣬵�ͬ��LED0(1)
        HAL_GPIO_WritePin(GPIOF,GPIO_PIN_10,GPIO_PIN_RESET); 	//LED1��Ӧ����PF10���ͣ�������ͬ��LED1(0)
        delay_ms(500);                                      	//��ʱ500ms 
	}
}

/*����������ʹ��λ������ʵ�֣�*/

/*int main(void)
{ 
    HAL_Init();                    	//��ʼ��HAL��    
    Stm32_Clock_Init(336,8,2,7);  	//����ʱ��,168Mhz
	delay_init(168);               	//��ʼ����ʱ����
	LED_Init();						//��ʼ��LED	
	while(1)
	{
         LED0=0;			     	//LED0��
	     LED1=1;				 	//LED1��
		 delay_ms(500);
		 LED0=1;					//LED0��
		 LED1=0;					//LED1��
		 delay_ms(500);
	 }
}*/




/*
����������ʹ��ֱ�Ӳ����������ʽʵ�������
*/

/*int main(void)
{ 
    HAL_Init();                    	//��ʼ��HAL��    
    Stm32_Clock_Init(336,8,2,7);  	//����ʱ��,168Mhz
	delay_init(168);               	//��ʼ����ʱ����
	LED_Init();						//��ʼ��LED	

	while(1)
	{
      GPIOF->BSRR=GPIO_PIN_9;     	//LED0��
	  GPIOF->BSRR=GPIO_PIN_10<<16; 	//LED1��
	  delay_ms(500);
      GPIOF->BSRR=GPIO_PIN_9<<16; 	//LED0��
	  GPIOF->BSRR=GPIO_PIN_10;     	//LED1��
	  delay_ms(500);
	 }
}*/	
