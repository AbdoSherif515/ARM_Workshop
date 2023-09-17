/***********************************************************************************************/
/* Author  :   Abdelrahman Sherif Hassan                                                       */
/* Date    :   16/9/2023                                                                       */
/* Version :   V01                                                                             */
/***********************************************************************************************/
#include "std_types.h"

#ifndef  RCC_PRIV_H
#define  RCC_PRIV_H

/*   REGISTERS  */

#define RCC_BASE_ADDRESS  0x40021000

#define RCC_CR               *((volatile u32*) (RCC_BASE_ADDRESS + 0x00))
#define RCC_CFGR             *((volatile u32*) (RCC_BASE_ADDRESS + 0x04))
#define RCC_CIR              *((volatile u32*) (RCC_BASE_ADDRESS + 0x08))
#define RCC_APB2RSTR         *((volatile u32*) (RCC_BASE_ADDRESS + 0x0C))
#define RCC_APB1RSTR         *((volatile u32*) (RCC_BASE_ADDRESS + 0x10))
#define RCC_AHBENR           *((volatile u32*) (RCC_BASE_ADDRESS + 0x14))
#define RCC_APB2ENR          *((volatile u32*) (RCC_BASE_ADDRESS + 0x18))
#define RCC_APB1ENR          *((volatile u32*) (RCC_BASE_ADDRESS + 0x1C))
#define RCC_BDCR             *((volatile u32*) (RCC_BASE_ADDRESS + 0x20))
#define RCC_CSR              *((volatile u32*) (RCC_BASE_ADDRESS + 0x24))


/*  Option for clock type */

#define RCC_HSI                   0
#define RCC_HSE_CRYSTAL           1
#define RCC_HSE_RC                2
#define RCC_PLL                   3

 /* PLL_MUL     18:21  BITS */
#define PLL_CLOCK_MUL_4    0b0010
#define PLL_CLOCK_MUL_5    0b0011
#define PLL_CLOCK_MUL_6    0b0100
#define PLL_CLOCK_MUL_7    0b0101
#define PLL_CLOCK_MUL_8    0b0110
#define PLL_CLOCK_MUL_9    0b0111
#define PLL_CLOCK_MUL_6_5  0b1101
/* PLL INPUT MODES */
#define PLL_INPUT_HSI_DIV_2    0
#define PLL_INPUT_HSE          1
#define PLL_INPUT_HSE_DIV_2    2

/* AHB prescale */
#define AHB_PRESCALE_NOT_DIV  0b0000
#define AHB_PRESCALE_2        0b1000
#define AHB_PRESCALE_4        0b1001
#define AHB_PRESCALE_8        0b1010
#define AHB_PRESCALE_16       0b1011
#define AHB_PRESCALE_64       0b1100
#define AHB_PRESCALE_128      0b1101
#define AHB_PRESCALE_256      0b1110
#define AHB_PRESCALE_512      0b1111

/* APB2 prescale */
#define APB2_PRESCALE_NOT_DIV   0b000
#define APB2_PRESCALE_2         0b100
#define APB2_PRESCALE_4         0b101
#define APB2_PRESCALE_8         0b110
#define APB2_PRESCALE_16        0b111

/* APB1 prescale */
#define APB1_PRESCALE_NOT_DIV     0b000
#define APB1_PRESCALE_2           0b100
#define APB1_PRESCALE_4           0b101
#define APB1_PRESCALE_8           0b110
#define APB1_PRESCALE_16          0b111

#endif
