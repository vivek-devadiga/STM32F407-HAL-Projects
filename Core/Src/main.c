#include "main.h"

// IR sensor
#define IR_PORT GPIOA
#define IR_PIN GPIO_PIN_0

// LED
#define LED_PORT GPIOD
#define LED_PIN GPIO_PIN_14

void led_ir(void);

int main()
{
	HAL_Init();
	led_ir();
	while(1)
	{
		if(HAL_GPIO_ReadPin(IR_PORT,IR_PIN)==GPIO_PIN_SET)
		{
			HAL_GPIO_WritePin(LED_PORT,LED_PIN,GPIO_PIN_RESET);
		}
		else
		{
			HAL_GPIO_WritePin(LED_PORT,LED_PIN,GPIO_PIN_RESET);

		}

	}
}

void led_ir(void)
{
	__HAL_RCC_GPIOA_CLK_ENABLE();


	GPIO_InitTypeDef GPIO_InitStruct = {0};

	GPIO_InitStruct.Pin = GPIO_PIN_0;
	GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
	GPIO_InitStruct.Pull = GPIO_NOPULL;

	HAL_GPIO_Init(GPIOA,&GPIO_InitStruct);

	__HAL_RCC_GPIOD_CLK_ENABLE();
	GPIO_InitStruct.Pin =GPIO_PIN_14;
	GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
	GPIO_InitStruct.Pull = GPIO_NOPULL;

	HAL_GPIO_Init(GPIOD, &GPIO_InitStruct);


}
