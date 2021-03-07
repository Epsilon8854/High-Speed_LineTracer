#include "main.h"

void RCC_Configuration_Switch(void)
{
    RCC_AFIO_ON;
    RCC_Switch_ON; 
}

void GPIO_Configuration_Switch(void)
{
 	GPIO_InitTypeDef GPIO_InitStructure;
  
	/* Motor Pin Set */
	GPIO_InitStructure.GPIO_Pin = GPIO_Switch;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;
	GPIO_Init(Switch, &GPIO_InitStructure);
}

void EXTI_Configuration_Switch(void)
{
	EXTI_InitTypeDef EXTI_InitStructure;

	GPIO_EXTI_Line1;
	GPIO_EXTI_Line2;
	GPIO_EXTI_Line3;
	GPIO_EXTI_Line4;

	EXTI_InitStructure.EXTI_Line = EXTI_Lines;
	EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;
	EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Falling;  
	EXTI_InitStructure.EXTI_LineCmd = ENABLE;

	EXTI_Init(&EXTI_InitStructure);
}

void NVIC_Configuration_Switch(void)
{
	NVIC_InitTypeDef NVIC_InitStructure;

	NVIC_InitStructure.NVIC_IRQChannel = EXTI9_5_IRQn;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 1;
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE; 
	NVIC_Init(&NVIC_InitStructure);

}

void EXTI9_5_IRQHandler(void)
{
	delay_ms(200);
	if(EXTI_GetITStatus(EXTI_Line5) != RESET)
	{
		if(menu_select)
		{
			menu_select = 0;
			menu = menu_selected;
			if(menu == 1 || menu == 2 || menu == 5 || menu == 6) 
			{
				ADC_ON();
			}	

		}
		else if(menu == 10 && race == 0)
		{
			race = 1;
		}
		else if(race == 1)
		{
			
		}
		else
		{
			if(menu == 9) Set_Weight();
			menu_select = 1;
			menu = 0;

			Motor_OFF();
			ADC_OFF();
		}
    	EXTI_ClearITPendingBit(EXTI_Line5);
    }
	if(EXTI_GetITStatus(EXTI_Line6) != RESET)
  	{		
		if(menu == 0 && menu_select) menu_selected--;
		if(menu_selected < 0) menu_selected = MENU_Limit;
		if(menu == 7) Acc_Limit -= 10;
		if(menu == 8) hand -= 5;
		if(menu == 9) wei[Wei_Num] -= 5;
		if(menu == 11) End_Step -= 10;
		if(menu == 13) Course_Num--;
		if(Course_Num < 0) Course_Num = 0;
		if(menu == 14) Race_Mode = !Race_Mode;
		if(menu == 15) Acc_Max -= 50;
  		EXTI_ClearITPendingBit(EXTI_Line6);
  	}
	if(EXTI_GetITStatus(EXTI_Line7) != RESET)
	{
		if(menu == 9)
		{
			Wei_Num++;
			if(Wei_Num > 2) Wei_Num = 0;
		}
		EXTI_ClearITPendingBit(EXTI_Line7);
	}
	if(EXTI_GetITStatus(EXTI_Line8) != RESET)
	{
		if(menu == 0 && menu_select) menu_selected++;
		if(menu_selected > MENU_Limit) menu_selected = 0;
		if(menu == 7) Acc_Limit += 10;
		if(menu == 8) hand += 5;
		if(menu == 9) wei[Wei_Num] += 5;
		if(menu == 11) End_Step += 10;
		if(menu == 13) Course_Num ++;
		if(menu == 14) Race_Mode = !Race_Mode;
		if(menu == 15) Acc_Max += 50;
		EXTI_ClearITPendingBit(EXTI_Line8);
	}
}
