/***********************************************************************************************/
/* Author  :   Abdelrahman Sherif Hassan                                                       */
/* Date    :   16/9/2023                                                                       */
/* Version :   V01                                                                             */
/***********************************************************************************************/
#include "RCC_priv.h"
#ifndef  RCC_CONFIG_H
#define  RCC_CONFIG_H


/* Options :     RCC_HSI
                 RCC_HSE_CRYSTAL
                 RCC_HSE_RC
                 RCC_PLL
                 */

#define CLOCK_TYPE       RCC_HSI

/* Options :   AHB_PRESCALE_NOT_DIV
			   AHB_PRESCALE_2
			   AHB_PRESCALE_4
			   AHB_PRESCALE_8
			   AHB_PRESCALE_16
			   AHB_PRESCALE_64
			   AHB_PRESCALE_128
			   AHB_PRESCALE_256
			   AHB_PRESCALE_512
                 */

#define  AHB_PRESCALE    AHB_PRESCALE_8
/* Options :   APB2_PRESCALE_NOT_DIV
			   APB2_PRESCALE_2
			   APB2_PRESCALE_4
			   APB2_PRESCALE_8
			   APB2_PRESCALE_16
                 */
#define  APB2_PRESCALE   APB2_PRESCALE_NOT_DIV
/* Options :   APB1_PRESCALE_NOT_DIV
			   APB1_PRESCALE_2
			   APB1_PRESCALE_4
			   APB1_PRESCALE_8
			   APB1_PRESCALE_16
                 */
#define  APB1_PRESCALE   APB1_PRESCALE_NOT_DIV

/* Options :    PLL_CLOCK_MUL_4
				PLL_CLOCK_MUL_5
				PLL_CLOCK_MUL_6
				PLL_CLOCK_MUL_7
				PLL_CLOCK_MUL_8
				PLL_CLOCK_MUL_9
                PLL_CLOCK_MUL_6_5 */

#define PLL_CLOCK_MUL   PLL_CLOCK_MUL_4

/* Options :    PLL_INPUT_HSI_DIV_2
				PLL_INPUT_HSE
				PLL_INPUT_HSE_DIV_2
				*/
#define PLL_INPUT       PLL_INPUT_HSI_DIV_2




#endif
