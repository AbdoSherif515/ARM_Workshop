#include <stdint.h>

#include "stm32f103x8.h"

#include "BIT_MATH.h"
#include "STD_TYPES.h"

#include "GPIO.h"
#include "EXTI.h"
#include "RCC_interface.h"
#include "STK_interface.h"



void GPIO_init()
{
	GPIO_PinConfig_t cfg;
	cfg.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	cfg.GPIO_Output_Speed = GPIO_SPEED_2M;
	cfg.GPIO_PinNumber = GPIO_PIN_0;
	MCAL_GPIO_Init(GPIOA, &cfg);

	cfg.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	cfg.GPIO_Output_Speed = GPIO_SPEED_2M;
	cfg.GPIO_PinNumber = GPIO_PIN_1;
	MCAL_GPIO_Init(GPIOA, &cfg);

	cfg.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	cfg.GPIO_Output_Speed = GPIO_SPEED_2M;
	cfg.GPIO_PinNumber = GPIO_PIN_2;
	MCAL_GPIO_Init(GPIOA, &cfg);

	cfg.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	cfg.GPIO_Output_Speed = GPIO_SPEED_2M;
	cfg.GPIO_PinNumber = GPIO_PIN_3;
	MCAL_GPIO_Init(GPIOA, &cfg);

	cfg.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	cfg.GPIO_Output_Speed = GPIO_SPEED_2M;
	cfg.GPIO_PinNumber = GPIO_PIN_4;
	MCAL_GPIO_Init(GPIOA, &cfg);

	cfg.GPIO_MODE = GPIO_MODE_INPUT_PU;
	cfg.GPIO_PinNumber = GPIO_PIN_5;
	MCAL_GPIO_Init(GPIOA, &cfg);

	cfg.GPIO_MODE = GPIO_MODE_INPUT_PU;
	cfg.GPIO_PinNumber = GPIO_PIN_6;
	MCAL_GPIO_Init(GPIOA, &cfg);


}

void Left();
void Right();


int main(void)
{
	STK_Init(1000);
	MCAL_RCC_InitSysClock();
	MCAL_RCC_EnablePeripheral(RCC_APB2, RCC_APB2ENR_IOPAEN);
	GPIO_init();

	while(1)
	{
		if(MCAL_GPIO_ReadPin(GPIOA, GPIO_PIN_5) == 0)
		{
			Left();
		}

		if(MCAL_GPIO_ReadPin(GPIOA, GPIO_PIN_6) == 0)
		{
			Right();
		}
    }

}

void Left()
{
	MCAL_GPIO_WritePin(GPIOA, GPIO_PIN_0 , GPIO_PIN_SET);
	STK_SetDelay_ms(300);


	MCAL_GPIO_WritePin(GPIOA, GPIO_PIN_1 , GPIO_PIN_SET);
	STK_SetDelay_ms(300);


	MCAL_GPIO_WritePin(GPIOA, GPIO_PIN_2 , GPIO_PIN_SET);
	STK_SetDelay_ms(300);


	MCAL_GPIO_WritePin(GPIOA, GPIO_PIN_3 , GPIO_PIN_SET);
	STK_SetDelay_ms(300);


	MCAL_GPIO_WritePin(GPIOA, GPIO_PIN_4 , GPIO_PIN_SET);
	STK_SetDelay_ms(300);


}

void Right()
{

	MCAL_GPIO_WritePin(GPIOA, GPIO_PIN_4 , GPIO_PIN_RESET);
	STK_SetDelay_ms(300);


	MCAL_GPIO_WritePin(GPIOA, GPIO_PIN_3 , GPIO_PIN_RESET);
	STK_SetDelay_ms(300);


	MCAL_GPIO_WritePin(GPIOA, GPIO_PIN_2 , GPIO_PIN_RESET);
	STK_SetDelay_ms(300);


	MCAL_GPIO_WritePin(GPIOA, GPIO_PIN_1 , GPIO_PIN_RESET);
	STK_SetDelay_ms(300);


	MCAL_GPIO_WritePin(GPIOA, GPIO_PIN_0 , GPIO_PIN_RESET);
	STK_SetDelay_ms(300);


}


