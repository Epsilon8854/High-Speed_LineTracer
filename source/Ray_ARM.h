#include "main.h"

void RCC_Configuration_Ray(void)
{
    RCC_Ray_ON; 
}

void GPIO_Configuration_Ray(void)
{
  GPIO_InitTypeDef GPIO_InitStructure;
  
  /* Motor Pin Set */
  GPIO_InitStructure.GPIO_Pin = GPIO_Ray;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
  GPIO_Init(Ray, &GPIO_InitStructure);
}
