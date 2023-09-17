/*
 * main.c
 *
 *  Created on: Sep 16, 2023
 *      Author: abdelrahman
 */

#include "common_macros.h"
#include "std_types.h"
#include "RCC_interface.h"
#include "GPIO_interface.h"


void delay(void)
{
	for ( u32 i= 0;  i< 10000;i++ )
	{
		asm("nop");
	}
}
int main()
{
	MRCC_voidInit();
	MRCC_voidEnablePeripheral(RCC_BUS_APB2,2);

	MGPIO_voidSetPinDirecion(PORTA,0,GPIOA_OUTPUT_2MHZ,GPIOA_OUTPUT_PUSH_PULL);
	MGPIO_voidSetPinDirecion(PORTA,1,GPIOA_OUTPUT_2MHZ,GPIOA_OUTPUT_PUSH_PULL);
	MGPIO_voidSetPinDirecion(PORTA,2,GPIOA_OUTPUT_2MHZ,GPIOA_OUTPUT_PUSH_PULL);
	MGPIO_voidSetPinDirecion(PORTA,3,GPIOA_OUTPUT_2MHZ,GPIOA_OUTPUT_PUSH_PULL);
	MGPIO_voidSetPinDirecion(PORTA,4,GPIOA_OUTPUT_2MHZ,GPIOA_OUTPUT_PUSH_PULL);
	MGPIO_voidSetPinDirecion(PORTA,5,GPIOA_OUTPUT_2MHZ,GPIOA_OUTPUT_PUSH_PULL);
	MGPIO_voidSetPinDirecion(PORTA,6,GPIOA_OUTPUT_2MHZ,GPIOA_OUTPUT_PUSH_PULL);
	MGPIO_voidSetPinDirecion(PORTA,7,GPIOA_OUTPUT_2MHZ,GPIOA_OUTPUT_PUSH_PULL);
	MGPIO_voidSetPinDirecion(PORTA,8,GPIOA_INPUT,GPIOA_INPUT_PULLUP);
	MGPIO_voidSetPinDirecion(PORTA,9,GPIOA_INPUT,GPIOA_INPUT_PULLUP);

	while(1)
	{
		if(MGPIO_u8GetPinValue(PORTA,8) == 0 && MGPIO_u8GetPinValue(PORTA,0)==0)
		{
			for(u8 pin=0 ;pin<8 ;pin++)
			{
			MGPIO_voidSetPinValue(PORTA,pin,1);
			delay();
			}
		}
		if(MGPIO_u8GetPinValue(PORTA,9) == 0 &&MGPIO_u8GetPinValue(PORTA,0)==1)
		{
			for(u8 pin=8 ;pin>0 ;pin--)
		    {
			MGPIO_voidSetPinValue(PORTA,pin-1,0);
		    delay();

		    }
		}




	}
}

