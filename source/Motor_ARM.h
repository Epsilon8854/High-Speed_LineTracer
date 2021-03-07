#include "main.h"

void Motor_ON(void)
{
  End = 0;
  End_step_count = 0;
  Current_Limit = Acc_Limit; 
  Start_End = 0;
  Motor_Speed = 0;
  TIM_ITConfig(TIM2, TIM_IT_Update, ENABLE);
  TIM_Cmd(TIM2, ENABLE);

  TIM_ITConfig(TIM3, TIM_IT_Update, ENABLE);
  TIM_Cmd(TIM3, ENABLE);
}

void Motor_OFF(void)
{
  TIM_ITConfig(TIM2, TIM_IT_Update, DISABLE);
  TIM_Cmd(TIM2, DISABLE);

  TIM_ITConfig(TIM3, TIM_IT_Update, DISABLE);
  TIM_Cmd(TIM3, DISABLE);

  L_Motor->BRR = 0xFFFF;
  R_Motor->BRR = 0xFFFF;
}

void RCC_Configuration_Motor(void)
{
    RCC_L_Motor_ON;
    RCC_R_Motor_ON; 
    RCC_L_TIM_ON;
    RCC_R_TIM_ON;
}

void GPIO_Configuration_Motor(void)
{
  GPIO_InitTypeDef GPIO_InitStructure;
  
  /* Motor Pin Set */
  GPIO_InitStructure.GPIO_Pin = GPIO_L_Motor;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
  GPIO_Init(L_Motor, &GPIO_InitStructure);

  GPIO_InitStructure.GPIO_Pin = GPIO_R_Motor;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
  GPIO_Init(R_Motor, &GPIO_InitStructure);
}

void NVIC_Configuration_Motor(void)
{
  NVIC_InitTypeDef NVIC_InitStructure;

  NVIC_InitStructure.NVIC_IRQChannel = TIM2_IRQn;
  NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;
  NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1;
  NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE; 
  NVIC_Init(&NVIC_InitStructure);

  NVIC_InitStructure.NVIC_IRQChannel = TIM3_IRQn;
  NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;
  NVIC_InitStructure.NVIC_IRQChannelSubPriority = 2;
  NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE; 
  NVIC_Init(&NVIC_InitStructure);
}

void TIM_Configuration_Motor(void) 
{ 
  TIM_TimeBaseInitTypeDef TIM_TimeBaseStructure;

  TIM_TimeBaseStructure.TIM_Period = L_Motor_Speed;
  TIM_TimeBaseStructure.TIM_Prescaler = 8 - 1; 
  TIM_TimeBaseStructure.TIM_ClockDivision = 0;
  TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;
   
  TIM_TimeBaseInit(TIM2, &TIM_TimeBaseStructure);
   
  TIM_ITConfig(TIM2, TIM_IT_Update, ENABLE);

  TIM_Cmd(TIM2, ENABLE);

  TIM_TimeBaseStructure.TIM_Period = R_Motor_Speed;
  TIM_TimeBaseStructure.TIM_Prescaler = 8 - 1; 
  TIM_TimeBaseStructure.TIM_ClockDivision = 0;
  TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;
   
  TIM_TimeBaseInit(TIM3, &TIM_TimeBaseStructure);
   
  TIM_ITConfig(TIM3, TIM_IT_Update, ENABLE);

  TIM_Cmd(TIM3, ENABLE);
}

void set_step(void)
{
  L_Motor_step[0] = L_Motor_A;
  L_Motor_step[1] = L_Motor_A | L_Motor_B;
  L_Motor_step[2] = L_Motor_B;
  L_Motor_step[3] = L_Motor_A_ | L_Motor_B;
  L_Motor_step[4] = L_Motor_A_;
  L_Motor_step[5] = L_Motor_A_ | L_Motor_B_;
  L_Motor_step[6] = L_Motor_B_;
  L_Motor_step[7] = L_Motor_A | L_Motor_B_;

  R_Motor_step[0] = R_Motor_A;
  R_Motor_step[1] = R_Motor_A | R_Motor_B;
  R_Motor_step[2] = R_Motor_B;
  R_Motor_step[3] = R_Motor_A_ | R_Motor_B;
  R_Motor_step[4] = R_Motor_A_;
  R_Motor_step[5] = R_Motor_A_ | R_Motor_B_;
  R_Motor_step[6] = R_Motor_B_;
  R_Motor_step[7] = R_Motor_A | R_Motor_B_;
}

void TIM2_IRQHandler(void)
{
   if(TIM_GetITStatus(TIM2,TIM_IT_Update) != RESET)
   {
      TIM_ClearITPendingBit(TIM2, TIM_IT_Update); // Clear the interrupt flag
			if(End) End_step_count++;
      if(Motor_Speed < Current_Limit) Motor_Speed++;
      else if(Motor_Speed > Current_Limit) Motor_Speed -= 6;

      L_Motor_Speed = (step_acc[Motor_Speed] * handle[hand - mis_value]) >> 10; 

      TIM2->ARR = L_Motor_Speed;
      L_Motor->ODR = L_Motor_step[L_step];

      if(--L_step < 0) L_step = 7;
   }
}

void TIM3_IRQHandler(void)
{
   if(TIM_GetITStatus(TIM3,TIM_IT_Update) != RESET)
   {
      TIM_ClearITPendingBit(TIM3, TIM_IT_Update); // Clear the interrupt flag
      Count_Step++;
      R_Motor_Speed = (step_acc[Motor_Speed] * handle[hand + mis_value]) >> 10; 

      TIM3->ARR = R_Motor_Speed;
      R_Motor->ODR = R_Motor_step[R_step];

      if(++R_step > 7) R_step = 0;
   }
}
