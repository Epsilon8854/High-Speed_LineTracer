#include "main.h"
#include "ADC_ARM.h"
#include "Motor_ARM.h"
#include "Switch_ARM.h"
#include "Ray_ARM.h"
#include "LCD_ARM.h"

int main()
{
	set_step();
	RCC_Configuration();
	GPIO_Configuration();
	NVIC_Configuration();
	EXTI_Configuration();
	TIM_Configuration();
	Reset();

	LCD_init();
	LCD_print();
	delay_ms(100);

	while(1)
	{
		Turtle_Are_you_ready();
		ADC_MAX_Sensing();
		ADC_MIN_Sensing();
		View_ADC_Max();
		View_ADC_Min();
		View_ADC_Normal();
		View_MisValue();
		Modyfy_Acc_Limit();
		Modyfy_Handle();
		Modyfy_Weight();
		racing();
		Modyfy_End_Step();
		View_Turn_Mark();
		View_Course();
		Choose_Race();
		Modyfy_Acc_Max();
	}
}
