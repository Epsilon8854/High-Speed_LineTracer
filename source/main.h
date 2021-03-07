#ifndef __MAIN_H__
#define __MAIN_H__

#include "stm32f10x.h"
#include "acc_table(12000).h"
#include "handle.h"
#include <stdio.h>

#define ADC_A 			GPIOA

#define RCC_ADC_A_ON	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE)

#define RCC_ADC1_ON 	RCC_APB2PeriphClockCmd(RCC_APB2Periph_ADC1, ENABLE)
#define RCC_AFIO_ON		RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO, ENABLE)
#define RCC_ADC_TIM_ON	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM4, ENABLE)
#define GPIO_ADC_A		GPIO_Pin_0 | GPIO_Pin_1 | GPIO_Pin_2 | GPIO_Pin_3 | GPIO_Pin_4 | GPIO_Pin_5 | GPIO_Pin_6 | GPIO_Pin_7

#define Switch			GPIOB
#define RCC_Switch_ON 	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE)
#define GPIO_EXTI_Line1	GPIO_EXTILineConfig(GPIO_PortSourceGPIOB, GPIO_PinSource5)
#define GPIO_EXTI_Line2	GPIO_EXTILineConfig(GPIO_PortSourceGPIOB, GPIO_PinSource6)
#define GPIO_EXTI_Line3	GPIO_EXTILineConfig(GPIO_PortSourceGPIOB, GPIO_PinSource7)
#define GPIO_EXTI_Line4	GPIO_EXTILineConfig(GPIO_PortSourceGPIOB, GPIO_PinSource8)
#define GPIO_Switch		GPIO_Pin_5 | GPIO_Pin_6 | GPIO_Pin_7 | GPIO_Pin_8
#define EXTI_Lines 		EXTI_Line5 | EXTI_Line6 | EXTI_Line7 | EXTI_Line8

#define L_Motor 		GPIOG
#define RCC_L_Motor_ON 	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOG, ENABLE)
#define RCC_L_TIM_ON	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2, ENABLE)
#define RCC_L_TIM_OFF	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2, DISABLE)
#define L_Motor_A		GPIO_Pin_7
#define L_Motor_A_		GPIO_Pin_5
#define L_Motor_B		GPIO_Pin_3
#define L_Motor_B_		GPIO_Pin_8
#define GPIO_L_Motor	L_Motor_A | L_Motor_A_ | L_Motor_B | L_Motor_B_

#define R_Motor 		GPIOD
#define RCC_R_Motor_ON 	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOD, ENABLE)
#define RCC_R_TIM_ON	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3, ENABLE)
#define RCC_R_TIM_OFF	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3, DISABLE)
#define R_Motor_A		GPIO_Pin_4
#define R_Motor_A_		GPIO_Pin_5
#define R_Motor_B		GPIO_Pin_6
#define R_Motor_B_		GPIO_Pin_7
#define GPIO_R_Motor	R_Motor_A | R_Motor_A_ | R_Motor_B | R_Motor_B_

#define Ray				GPIOE
#define RCC_Ray_ON		RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOE, ENABLE)
#define GPIO_Ray		GPIO_Pin_0 | GPIO_Pin_1 | GPIO_Pin_2 | GPIO_Pin_3 | GPIO_Pin_4 | GPIO_Pin_5 | GPIO_Pin_6 | GPIO_Pin_7

#define LCD 			GPIOF
#define RCC_LCD_ON		RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOF, ENABLE)
#define GPIO_LCD_RS		GPIO_Pin_0
#define GPIO_LCD_RW		GPIO_Pin_1
#define GPIO_LCD_EN		GPIO_Pin_2
#define GPIO_LCD_D4		GPIO_Pin_4
#define GPIO_LCD_D5		GPIO_Pin_5
#define GPIO_LCD_D6		GPIO_Pin_6
#define GPIO_LCD_D7		GPIO_Pin_7
#define GPIO_LCD		GPIO_LCD_RS | GPIO_LCD_RW | GPIO_LCD_EN | GPIO_LCD_D4 | GPIO_LCD_D5 | GPIO_LCD_D6 | GPIO_LCD_D7

#define BUSSER_Pin		GPIO_Pin_13
#define BUSSER 			GPIOC
#define BUSSER_ON		BUSSER->BSRR = BUSSER_Pin
#define BUSSER_OFF		BUSSER->BRR = BUSSER_Pin


#define FUNCSET	0x0028		// Function Set/
#define ENTMODE	0x0006		// Entry Mode Set
#define ALLCLR	0x0001		// All Clear
#define DISPON	0x000c		// Display On
#define DISPOFF	0x0008		// Display Off
// #define LINE1   0x0008		// 1st Line Move 이거 오류남. HOME 사용할 것.
#define LINE2	0x00C0		// 2nd Line Move
#define HOME	0x0002		// Cursor Home
#define CURON	0x000F		// Cursor On
#define LSHIFT	0x0018		// Display Left Shift
#define RSHIFT	0x001C		// Display Right Shift

#define MENU_Limit 15

/* ADC Function */
void ADC_ON(void);
void ADC_OFF(void);
void RCC_Configuration_ADC(void);
void GPIO_Configuration_ADC(void);
void NVIC_Configuration_ADC(void);
void TIM_Configuration_ADC(void);
void ADC1_Configuration(void);
void ADC_Channel_Converter(void);

/* Switch Function */
void RCC_Configuration_Switch(void);
void GPIO_Configuration_Switch(void);
void EXTI_Configuration_Switch(void);
void NVIC_Configuration_Switch(void);

/* Motor Function */
void Motor_ON(void);
void Motor_OFF(void);
void RCC_Configuration_Motor(void);
void GPIO_Configuration_Motor(void);
void NVIC_Configuration_Motor(void);
void TIM_Configuration_Motor(void);
void set_step(void);

/* Ray Function */
void RCC_Configuration_Ray(void);
void GPIO_Configuration_Ray(void);

/* LCD Function */
void RCC_Configuration_LCD(void);
void GPIO_Configuration_LCD(void);
void LCD_init(void);

// void LCD_String(char flash str[]);
void LCD_Value(char val[]);
void LCD_print(void);		// LCD 화면 한 번 출력하기
void LCD_print_nonCLR(void);		// LCD 화면 한 번 출력하기(Clear 없이 덮어쓰기)
void Command(unsigned char byte);
void Data(unsigned char byte);
void Busy(void);
void delay_cnt_LCD(uint32_t cnt);


/* Main Function Declaration */
void RCC_Configuration(void);
void GPIO_Configuration(void);
void EXTI_Configuration(void);
void NVIC_Configuration(void);
void TIM_Configuration(void);

void Reset(void);
void Set_Weight(void);
void Turtle_Are_you_ready(void);
void View_ADC_Max(void);
void View_ADC_Min(void);
void View_ADC_Normal(void);
void View_MisValue(void);
void Modyfy_Acc_Limit(void);
void Modyfy_Handle(void);
void Modyfy_Weight(void);
void racing(void);
void Modyfy_End_Step(void);
void View_Turn_Mark(void);
void Check_Cource(void);
void View_Course(void);
void Choose_Race(void);
void Modyfy_Acc_Max(void);

int MIN(int a, int b);

/* test */
void test_Motor_Speed(void);

/* Nomal Function Declaration */
void delay_ms(uint32_t delay);
void delay_us(uint32_t delay);

/* ADC variance */
volatile int adc_num = 0;
volatile int ADC[8] = {0, 0, 0, 0, 0, 0, 0, 0};
volatile int weight[8] = {0, -120, -60, -30, 30, 60, 120, 0};
volatile int wei[3];
volatile int ADC_Max[16] 	= {10, 10, 10, 10, 10, 10, 10, 10};
volatile int ADC_Min[16] 	= {0, 0, 0, 0, 0, 0, 0, 0};
volatile int ADC_Normal[16] = {0, 0, 0, 0, 0, 0, 0, 0};
volatile int mis_value = 0;
volatile int tmp_value = 0;
volatile int ADC_Sum = 0;
volatile int tmp_Sum = 0;
volatile int i = 0;

/* LCD variance */
char LCD_LINE1[20] = "LCD_TEST";
char LCD_LINE2[20] = "TURTLE";

/* Motor variance */
volatile int Acc_Limit;
volatile int hand;
volatile uint16_t L_Motor_step[8];
volatile uint16_t R_Motor_step[8];
volatile unsigned long Motor_Speed = 0;
volatile unsigned long L_Motor_Speed = 40000;
volatile unsigned long R_Motor_Speed = 40000;
volatile int L_step = 0;
volatile int R_step = 0;
volatile uint16_t temp = 0;

/* Main variance */
volatile int menu = 0;
volatile int menu_selected = 0;
volatile int menu_select = 1;
volatile int View_adc_num = 0;
volatile int race = 0;
volatile int Wei_Num = 0;
volatile int Cross_Flag = 0;
volatile int Left_Flag = 0;
volatile int Right_Flag = 0;
volatile int Start_End_Flag = 0;
volatile int Start_End = 0;
volatile int End = 0;
volatile int Current_Limit = 0;
volatile int End_Step = 400;
volatile int End_step_count = 0;
volatile int End_Speed = 100;

volatile int L_Turn_Mark = 0;
volatile int R_Turn_Mark = 0;
volatile int Race_Mode = 0;
volatile int straight = 0;

volatile int Count_Step = 0;
volatile int Start_Step = 600;
volatile int steps[200];
volatile char Turn_Mark[200] = {'S'};
volatile char cource[200] = {'S'};
volatile int Course_Num = 0;
volatile int Decrease_Step = 600;
volatile int Acc_Max = 2000;

/* Main Function Define */
void RCC_Configuration(void)
{
	RCC_Configuration_ADC();
	RCC_Configuration_Switch();
	RCC_Configuration_Motor();
	RCC_Configuration_Ray();
	RCC_Configuration_LCD();
}
void GPIO_Configuration(void)
{
	GPIO_Configuration_ADC();
	GPIO_Configuration_Switch();
	GPIO_Configuration_Motor();
	GPIO_Configuration_Ray();
	GPIO_Configuration_LCD();
}
void EXTI_Configuration(void)
{
	EXTI_Configuration_Switch();
}
void NVIC_Configuration(void)
{
	NVIC_Configuration_ADC();
	NVIC_Configuration_Motor();
	NVIC_Configuration_Switch();
}
void TIM_Configuration(void)
{
	TIM_Configuration_ADC();
	TIM_Configuration_Motor();
}

/* Nomal Function Define */
void delay_ms(uint32_t delay)
{
	uint32_t cnt = 0;
	while (cnt++ < delay * 4800);
}

void delay_us(uint32_t delay)
{
	uint32_t cnt = 0;
	while(cnt++ < delay * 5);
}

void Reset(void)
{
	int i;
	adc_num = 0;
	//weight[16] = {0, 0, 0, 0, -120, -60, -30, -15, 15, 30, 60, 120, 0, 0, 0, 0};
	wei[0] = 30;
	wei[1] = 110;
	wei[2] = 270;

	Set_Weight();

	for(i = 0; i < 8; i++)
	{
		ADC[i] = 0;
		ADC_Max[i] = 10;
		ADC_Min[i] = 0;
		ADC_Normal[i] = 0;
	}

	Acc_Limit = 1000;
	hand = 380;
	Motor_Speed = 0;
	L_Motor_Speed = step_acc[0];
	R_Motor_Speed = step_acc[0];
	L_step = 0;
	R_step = 0;

	Motor_OFF();
	ADC_OFF();
}
void Set_Weight(void)
{
	weight[1] = -wei[2];
	weight[2] = -wei[1];
	weight[3] = -wei[0];
	weight[4] = wei[0];
	weight[5] = wei[1];
	weight[6] = wei[2];
}

void Check_Cource(void)
{
	int i = 0;

	for(i = 0; i < L_Turn_Mark + R_Turn_Mark; i++)
	{
		cource[i] = Turn_Mark[i];
		if(Turn_Mark[i] == Turn_Mark[i + 1])
		{
			cource[i + 1] = 'S';
			straight++;
			i++;
		}
	}
}
void Turtle_Are_you_ready(void)
{
	while(menu_select == 1)
	{
		while(menu_selected == 0 && menu_select == 1)
		{
			sprintf(LCD_LINE1, "Turtle,");
			sprintf(LCD_LINE2, "I'm ready");
			Command(ALLCLR);
			LCD_print();
			delay_ms(100);
		}
		while(menu_selected == 1 && menu_select == 1)
		{
			sprintf(LCD_LINE1, "1.ADC MAX Sensing");
			sprintf(LCD_LINE2, "");
			Command(ALLCLR);
			LCD_print();
			delay_ms(100);
		}
		while(menu_selected == 2 && menu_select == 1)
		{
			sprintf(LCD_LINE1, "2.ADC MIN Sensing");
			sprintf(LCD_LINE2, "");
			Command(ALLCLR);
			LCD_print();
			delay_ms(100);
		}
		while(menu_selected == 3 && menu_select == 1)
		{
			sprintf(LCD_LINE1, "3.View ADC MAX");
			sprintf(LCD_LINE2, "");
			Command(ALLCLR);
			LCD_print();
			delay_ms(100);
		}
		while(menu_selected == 4 && menu_select == 1)
		{
			sprintf(LCD_LINE1, "4.View ADC MIN");
			sprintf(LCD_LINE2, "");
			Command(ALLCLR);
			LCD_print();
			delay_ms(100);
		}
		while(menu_selected == 5 && menu_select == 1)
		{
			sprintf(LCD_LINE1, "5.View ADC Normal");
			sprintf(LCD_LINE2, "");
			Command(ALLCLR);
			LCD_print();
			delay_ms(100);
		}
		while(menu_selected == 6 && menu_select == 1)
		{
			sprintf(LCD_LINE1, "6.View MisValue");
			sprintf(LCD_LINE2, "");
			Command(ALLCLR);
			LCD_print();
			delay_ms(100);
		}
		while(menu_selected == 7 && menu_select == 1)
		{
			sprintf(LCD_LINE1, "7.Modyfy ");
			sprintf(LCD_LINE2, "      Acc_Limit");
			Command(ALLCLR);
			LCD_print();
			delay_ms(100);
		}
		while(menu_selected == 8 && menu_select == 1)
		{
			sprintf(LCD_LINE1, "8.Modyfu");
			sprintf(LCD_LINE2, "       Handle");
			Command(ALLCLR);
			LCD_print();
			delay_ms(100);
		}
		while(menu_selected == 9 && menu_select == 1)
		{
			sprintf(LCD_LINE1, "9.Modyfy");
			sprintf(LCD_LINE2, "        Weight");
			Command(ALLCLR);
			LCD_print();
			delay_ms(100);
		}
		while(menu_selected == 10 && menu_select == 1)
		{
			sprintf(LCD_LINE1, "Let's go!");
			sprintf(LCD_LINE2, "          Turtle!");
			Command(ALLCLR);
			LCD_print();
			delay_ms(100);
		}
		while(menu_selected == 11 && menu_select == 1)
		{
			sprintf(LCD_LINE1, "Modyfy");
			sprintf(LCD_LINE2, "        End_Step");
			Command(ALLCLR);
			LCD_print();
			delay_ms(100);
		}
		while(menu_selected == 12 && menu_select == 1)
		{
			sprintf(LCD_LINE1, "View Turn Mark");
			sprintf(LCD_LINE2, "       ");
			Command(ALLCLR);
			LCD_print();
			delay_ms(100);
		}
		while(menu_selected == 13 && menu_select == 1)
		{
			sprintf(LCD_LINE1, "View Course");
			sprintf(LCD_LINE2, "       ");
			Command(ALLCLR);
			LCD_print();
			delay_ms(100);
		}
		while(menu_selected == 14 && menu_select == 1)
		{
			sprintf(LCD_LINE1, "Choose Race");
			sprintf(LCD_LINE2, "       ");
			Command(ALLCLR);
			LCD_print();
			delay_ms(100);
		}
		while(menu_selected == 15 && menu_select == 1)
		{
			sprintf(LCD_LINE1, "Modyfy Acc Max");
			sprintf(LCD_LINE2, "       ");
			Command(ALLCLR);
			LCD_print();
			delay_ms(100);
		}
	}
}
void ADC_MAX_Sensing(void)
{
	while(menu == 1 && menu_select == 0)
	{
		{
			sprintf(LCD_LINE1, "%c%3d%c%3d%c%3d%c%3d", 'A', ADC[0] / 5, 'B', ADC[1] / 5, 'C', ADC[2] / 5, 'D', ADC[3] / 5);
			sprintf(LCD_LINE2, "%c%3d%c%3d%c%3d%c%3d", 'E', ADC[4] / 5, 'F', ADC[5] / 5, 'G', ADC[6] / 5, 'H', ADC[7] / 5);
		}
		
		Command(ALLCLR);
		LCD_print();
		delay_ms(100);
	}
}
void ADC_MIN_Sensing(void)
{
	while(menu == 2 && menu_select == 0)
	{
		{
			sprintf(LCD_LINE1, "%c%3d%c%3d%c%3d%c%3d", 'A', ADC[0] / 5, 'B', ADC[1] / 5, 'C', ADC[2] / 5, 'D', ADC[3] / 5);
			sprintf(LCD_LINE2, "%c%3d%c%3d%c%3d%c%3d", 'E', ADC[4] / 5, 'F', ADC[5] / 5, 'G', ADC[6] / 5, 'H', ADC[7] / 5);
		}
		
		Command(ALLCLR);
		LCD_print();
		delay_ms(100);
	}
}

void View_ADC_Max(void)
{
	while(menu == 3 && menu_select == 0)
	{
		{
			sprintf(LCD_LINE1, "%c%3d%c%3d%c%3d%c%3d", 'A', ADC_Max[0] / 5, 'B', ADC_Max[1] / 5, 'C', ADC_Max[2] / 5, 'D', ADC_Max[3] / 5);
			sprintf(LCD_LINE2, "%c%3d%c%3d%c%3d%c%3d", 'E', ADC_Max[4] / 5, 'F', ADC_Max[5] / 5, 'G', ADC_Max[6] / 5, 'H', ADC_Max[7] / 5);
		}
		
		Command(ALLCLR);
		LCD_print();
		delay_ms(100);
	}
}
void View_ADC_Min(void)
{
	while(menu == 4 && menu_select == 0)
	{
		{
			sprintf(LCD_LINE1, "%c%3d%c%3d%c%3d%c%3d", 'A', ADC_Min[0] / 5, 'B', ADC_Min[1] / 5, 'C', ADC_Min[2] / 5, 'D', ADC_Min[3] / 5);
			sprintf(LCD_LINE2, "%c%3d%c%3d%c%3d%c%3d", 'E', ADC_Min[4] / 5, 'F', ADC_Min[5] / 5, 'G', ADC_Min[6] / 5, 'H', ADC_Min[7] / 5);
		}

		Command(ALLCLR);
		LCD_print();
		delay_ms(100);
	}
}
void View_ADC_Normal(void)
{
	while(menu == 5 && menu_select == 0)
	{
		{
			sprintf(LCD_LINE1, "%c%3d%c%3d%c%3d%c%3d", 'A', ADC_Normal[0], 'B', ADC_Normal[1], 'C', ADC_Normal[2], 'D', ADC_Normal[3]);
			sprintf(LCD_LINE2, "%c%3d%c%3d%c%3d%c%3d", 'E', ADC_Normal[4], 'F', ADC_Normal[5], 'G', ADC_Normal[6], 'H', ADC_Normal[7]);
		}

		Command(ALLCLR);
		LCD_print();
		delay_ms(100);
	}
}
void View_MisValue(void)
{
	while(menu == 6 && menu_select == 0)
	{
		sprintf(LCD_LINE1, "Mis Value");
		sprintf(LCD_LINE2, "%8d", mis_value);
		Command(ALLCLR);
		LCD_print();
		delay_ms(100);
	}
}
void Modyfy_Acc_Limit(void)
{
	while(menu == 7 && menu_select == 0)
	{
		sprintf(LCD_LINE1, "Acc Limit");
		sprintf(LCD_LINE2, "%8d", Acc_Limit);
		Command(ALLCLR);
		LCD_print();
		delay_ms(100);
	}
}
void Modyfy_Handle(void)
{
	while(menu == 8 && menu_select == 0)
	{
		sprintf(LCD_LINE1, "Handle");
		sprintf(LCD_LINE2, "%8d", hand);
		Command(ALLCLR);
		LCD_print();
		delay_ms(100);
	}
}
void Modyfy_Weight(void)
{
	while(menu == 9 && menu_select == 0)
	{
		sprintf(LCD_LINE1, "Weight Wei_Num%2d", Wei_Num);
		sprintf(LCD_LINE2, "%4d%4d%4d%4d", wei[0], wei[1], wei[2], wei[3]);
		Command(ALLCLR);
		LCD_print();
		delay_ms(100);
	}
}

void racing(void)
{
	while(menu == 10 && menu_select == 0)
	{
		while(race == 0)
		{
			sprintf(LCD_LINE1, "    Go?");
			sprintf(LCD_LINE2, "");
			Command(ALLCLR);
			LCD_print();
			delay_ms(100);
		}
		ADC_ON();
		sprintf(LCD_LINE1, "    Ready!");
		sprintf(LCD_LINE2, "        I'll go");
		Command(ALLCLR);
		LCD_print();
		delay_ms(500);
		Command(ALLCLR);
		Motor_ON();
		Count_Step = 0;

		L_Turn_Mark = 0;
		R_Turn_Mark = 0;

		while(race == 1 && Race_Mode == 0)
		{
			if(End)
			{
				steps[L_Turn_Mark + R_Turn_Mark] = Count_Step;
        		while(End_step_count < End_Step);
				TIM_ITConfig(TIM2, TIM_IT_Update, DISABLE);
				TIM_Cmd(TIM2, DISABLE);

				TIM_ITConfig(TIM3, TIM_IT_Update, DISABLE);
				TIM_Cmd(TIM3, DISABLE);
        		delay_ms(1500);
				Motor_OFF();
        		sprintf(LCD_LINE1, "Sucess");
        		sprintf(LCD_LINE2, "");
        		Command(ALLCLR);
        		LCD_print();
        		delay_ms(100);
        		race = 0;
				menu = 0;
				break;
			}
			if(ADC_Normal[1] < 20 && ADC_Normal[2] < 20 && ADC_Normal[3] < 20 && ADC_Normal[4] < 20 && ADC_Normal[5] < 20 && ADC_Normal[6] < 20)
			{
				Motor_OFF();
				race = 0;
				menu = 0;
				sprintf(LCD_LINE1, "Out");
				sprintf(LCD_LINE2, "");
				Command(ALLCLR);
				LCD_print();
				delay_ms(100);
			}
			if((ADC_Normal[3] > 40 && ADC_Normal[4] > 40) &&  ((ADC_Normal[2] > 40 && ADC_Normal[5] > 40) || (ADC_Normal[1] > 40 && ADC_Normal[6] > 40)))
			{
				BUSSER_ON;
				Cross_Flag = 1;
			}
			else if(!Cross_Flag)
			{
				if(ADC_Normal[0] > 40) Left_Flag = 1;
				if(ADC_Normal[7] > 40) Right_Flag = 1;
				
				if(Left_Flag && Right_Flag) Start_End_Flag = 1;
				if(ADC_Normal[0] < 30 && ADC_Normal[7] < 30 && Start_End_Flag) 
				{
					Start_End_Flag = 0;
					Start_End++;
					Left_Flag = 0;
					Right_Flag = 0;
					if(Start_End > 1)
					{
						End = 1;
						Current_Limit = End_Speed;
					}
				}
				if(ADC_Normal[0] < 10 & Left_Flag & !Right_Flag)
				{
					Left_Flag = 0;
					steps[L_Turn_Mark + R_Turn_Mark] = Count_Step;
					Count_Step = 0;
					L_Turn_Mark++;
					Turn_Mark[L_Turn_Mark + R_Turn_Mark] = 'L';	
				}
				if(ADC_Normal[7] < 10  & Right_Flag & !Left_Flag)
				{
					Right_Flag = 0;
					steps[L_Turn_Mark + R_Turn_Mark] = Count_Step;
					Count_Step = 0;
					R_Turn_Mark++;
					Turn_Mark[L_Turn_Mark + R_Turn_Mark] = 'R';
				}
			}
			else
			{
				if(ADC_Normal[0] > 40) Left_Flag = 1;
				if(ADC_Normal[7] > 40) Right_Flag = 1;
				
				if((ADC_Normal[0] < 10 && ADC_Normal[7] < 10) && (Left_Flag && Right_Flag))
				{
					BUSSER_OFF;
					Cross_Flag = 0;
					Right_Flag = 0;
					Left_Flag = 0;
				}
			}
		}
		if(Race_Mode == 0) Check_Cource();
		while(race == 1 && Race_Mode == 1)
		{
			if(cource[L_Turn_Mark + R_Turn_Mark] == 'S' && !End)
			{
				BUSSER_ON;
				if((steps[L_Turn_Mark + R_Turn_Mark] - Count_Step) > MIN(((Acc_Max - Acc_Limit) / 6 + Decrease_Step / 2), Decrease_Step) && Count_Step > Start_Step)
					Current_Limit = Acc_Max;
				else
					Current_Limit = Acc_Limit;
			}
			else
				BUSSER_OFF;

			if(End)
			{
				Current_Limit = End_Speed;
				BUSSER_OFF;
        		while(End_step_count < End_Step);
				TIM_ITConfig(TIM2, TIM_IT_Update, DISABLE);
				TIM_Cmd(TIM2, DISABLE);

				TIM_ITConfig(TIM3, TIM_IT_Update, DISABLE);
				TIM_Cmd(TIM3, DISABLE);
        		delay_ms(1500);
				Motor_OFF();
        		sprintf(LCD_LINE1, "Sucess");
        		sprintf(LCD_LINE2, "");
        		Command(ALLCLR);
        		LCD_print();
        		delay_ms(100);
        		race = 0;
				menu = 0;
				
				break;
			}
			if(ADC_Normal[1] < 20 && ADC_Normal[2] < 20 && ADC_Normal[3] < 20 && ADC_Normal[4] < 20 && ADC_Normal[5] < 20 && ADC_Normal[6] < 20)
			{
				Motor_OFF();
				race = 0;
				menu = 0;
				sprintf(LCD_LINE1, "Out");
				sprintf(LCD_LINE2, "");
				Command(ALLCLR);
				LCD_print();
				delay_ms(100);
			}
			if((ADC_Normal[3] > 40 && ADC_Normal[4] > 40) &&  ((ADC_Normal[2] > 40 && ADC_Normal[5] > 40) || (ADC_Normal[1] > 40 && ADC_Normal[6] > 40)))
			{
				Cross_Flag = 1;
			}
			else if(!Cross_Flag)
			{
				if(ADC_Normal[0] > 40) Left_Flag = 1;
				if(ADC_Normal[7] > 40) Right_Flag = 1;
				
				if(Left_Flag && Right_Flag) Start_End_Flag = 1;
				if(ADC_Normal[0] < 30 && ADC_Normal[7] < 30 && Start_End_Flag) 
				{
					Start_End_Flag = 0;
					Start_End++;
					Left_Flag = 0;
					Right_Flag = 0;
					if(Start_End > 1)
					{
						End = 1;
						Current_Limit = End_Speed;
					}
				}
				
				if(ADC_Normal[0] < 10 & Left_Flag & !Right_Flag)
				{
					Left_Flag = 0;
					Count_Step = 0;
					L_Turn_Mark++;
				}
				if(ADC_Normal[7] < 10  & Right_Flag & !Left_Flag)
				{
					Right_Flag = 0;
					Count_Step = 0;
					R_Turn_Mark++;	
				}
			}
			else
			{
				if(ADC_Normal[0] > 40) Left_Flag = 1;
				if(ADC_Normal[7] > 40) Right_Flag = 1;
				
				if((ADC_Normal[0] < 10 && ADC_Normal[7] < 10) && (Left_Flag && Right_Flag))
				{
					Cross_Flag = 0;
					Right_Flag = 0;
					Left_Flag = 0;
				}
			}
		}
		Motor_OFF();
		ADC_OFF();
	}
}
void Modyfy_End_Step(void)
{
	while(menu == 11 && menu_select == 0)
	{
		sprintf(LCD_LINE1, "End Step");
		sprintf(LCD_LINE2, "%8d", End_Step);
		Command(ALLCLR);
		LCD_print();
		delay_ms(100);
	}
}

void View_Turn_Mark(void)
{
	while(menu == 12 && menu_select == 0)
	{
		sprintf(LCD_LINE1, "Turn_Mark");
		sprintf(LCD_LINE2, "L %4d  R %4d", L_Turn_Mark, R_Turn_Mark);
		Command(ALLCLR);
		LCD_print();
		delay_ms(100);
	}
}

void View_Course(void)
{
	while(menu == 13 && menu_select == 0)
	{
		if(cource[Course_Num] == 'L') 		sprintf(LCD_LINE1, "Course[%d]: Left", Course_Num);
		else if(cource[Course_Num] == 'R') 	sprintf(LCD_LINE1, "Course[%d]: Right", Course_Num);
		else if(cource[Course_Num] == 'S') 	sprintf(LCD_LINE1, "Course[%d]: Straigt", Course_Num);
		sprintf(LCD_LINE2, "step : %9d", steps[Course_Num]);

		Command(ALLCLR);
		LCD_print();
		delay_ms(100);
	}
}


void Choose_Race(void)
{
	while(menu == 14 && menu_select == 0)
	{
		sprintf(LCD_LINE1, "Choose_Race");
		if(Race_Mode == 0) sprintf(LCD_LINE2, "1st Race");
		if(Race_Mode == 1) sprintf(LCD_LINE2, "2nd Race");
		Command(ALLCLR);
		LCD_print();
		delay_ms(100);
	}
}
void Modyfy_Acc_Max(void)
{
	while(menu == 15 && menu_select == 0)
	{
		sprintf(LCD_LINE1, "Acc Max");
		sprintf(LCD_LINE2, "%8d", Acc_Max);
		Command(ALLCLR);
		LCD_print();
		delay_ms(100);
	}
}

int MIN(int a, int b)
{
	return (a < b ? a : b);
}

#endif
