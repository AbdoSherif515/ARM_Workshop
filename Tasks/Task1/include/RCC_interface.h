/***********************************************************************************************/
/* Author  :   Abdelrahman Sherif Hassan                                                       */
/* Date    :   16/9/2023                                                                       */
/* Version :   V01                                                                             */
/***********************************************************************************************/

#ifndef  RCC_INTERFACE_H
#define  RCC_INTERFACE_H

/* Options for bus id */
#define RCC_BUS_AHB    0
#define RCC_BUS_APB2   1
#define RCC_BUS_APB1   2

/* Prototypes */
void MRCC_voidEnablePeripheral(u8 Copy_u8BusId,u8 Copy_u8PerifId);
void MRCC_voidDisablePeripheral(u8 Copy_u8BusId,u8 Copy_u8PerifId);
void MRCC_voidInit(void);

#endif
