/***********************************************************************************************/
/* Author  :   Abdelrahman Sherif Hassan                                                       */
/* Date    :   16/9/2023                                                                       */
/* Version :   V01                                                                             */
/***********************************************************************************************/
/* Standard lib */
#include "std_types.h"
#include "common_macros.h"

/* Lower layers */

/* Peripheral */
#include "RCC_config.h"
#include "RCC_priv.h"
#include "RCC_interface.h"
void PLL_voidInput(void);
void MRCC_voidInit(void)
{
	/* 1-Determine clock type */
	switch(CLOCK_TYPE)
		{
		case RCC_HSI        :    SET_BIT(RCC_CR,0);          // Enable HSI
		                         RCC_CFGR=0b00;              //Set as system clck
		                         break;
		case RCC_HSE_CRYSTAL:    SET_BIT(RCC_CR,16);         // Enable HSE
								 CLR_BIT(RCC_CR,18);		 // Disable ByPass
								 RCC_CFGR=0b01;              //Set as system clck
								 break;
		case RCC_HSE_RC      :   SET_BIT(RCC_CR,16);         // Enable HSE
								 SET_BIT(RCC_CR,18);		 // Enable ByPass
								 RCC_CFGR=0b01;              //Set as system clck
								 break;
		case RCC_PLL         :   SET_BIT(RCC_CR,24);         // Enable HSE
		                         RCC_CFGR=0b10;              //Set as system clck
							     PLL_voidInput();            //set the pll input
							     RCC_CFGR|=(PLL_CLOCK_MUL<<18);

		}
	/* 1-Determine path prescale */
      RCC_CFGR|=(AHB_PRESCALE<<4);
      RCC_CFGR|=(APB1_PRESCALE<<8);
      RCC_CFGR|=(APB2_PRESCALE<<11);
		}

void PLL_voidInput(void)
{
	switch(PLL_INPUT) //select if HSI/ or HSE/2 or HSE
	 {
      case PLL_INPUT_HSI_DIV_2 : CLR_BIT(RCC_CFGR,16);break;
      case PLL_INPUT_HSE       : SET_BIT(RCC_CFGR,16);
       	   	   	   	   	         CLR_BIT(RCC_CFGR,17); break;
      case PLL_INPUT_HSE_DIV_2 :SET_BIT(RCC_CFGR,16);
                                SET_BIT(RCC_CFGR,17); break;

}
}



void MRCC_voidEnablePeripheral(u8 Copy_u8BusId,u8 Copy_u8PerifId)
{
	switch(Copy_u8BusId)
	{
	case RCC_BUS_AHB  : SET_BIT(RCC_AHBENR,Copy_u8PerifId);break;
	case RCC_BUS_APB2 : SET_BIT(RCC_APB2ENR,Copy_u8PerifId);break;
	case RCC_BUS_APB1 : SET_BIT(RCC_APB1ENR,Copy_u8PerifId);break;
	}
}

void MRCC_voidDisablePeripheral(u8 Copy_u8BusId,u8 Copy_u8PerifId)
{
	switch(Copy_u8BusId)
	{
	case RCC_BUS_AHB  : CLR_BIT(RCC_AHBENR,Copy_u8PerifId);break;
	case RCC_BUS_APB2 : CLR_BIT(RCC_APB2ENR,Copy_u8PerifId);break;
	case RCC_BUS_APB1 : CLR_BIT(RCC_APB1ENR,Copy_u8PerifId);break;
	}
}
