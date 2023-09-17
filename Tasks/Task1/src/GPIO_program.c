/***********************************************************************************************/
/* Author  :   Abdelrahman Sherif Hassan                                                       */
/* Date    :   16/9/2023                                                                       */
/* Version :   V01                                                                             */
/***********************************************************************************************/

// Include necessary header files
#include "std_types.h"
#include "common_macros.h"

#include "GPIO_config.h"
#include "GPIO_interface.h"
#include "GPIO_priv.h"

// Function to set the direction and mode of a GPIO pin
void MGPIO_voidSetPinDirecion(u8 Copy_u8PortId, u8 Copy_u8PinId, u8 Copy_u8Direction, u8 Copy_u8Mode)
{
    switch (Copy_u8PortId)
    {
        case PORTA:
            if (Copy_u8PinId < 8)
            {
                // Adjust the pin index for pins 0-7
                Copy_u8PinId *= 4;
                // Clear and set the direction
                GPIOA_CRL &= ~(0b1111 << Copy_u8PinId);
                GPIOA_CRL |= (Copy_u8Direction << Copy_u8PinId);

                // Set the mode or pull-up/pull-down resistor
                if (Copy_u8Direction == GPIOA_INPUT && (Copy_u8Mode == GPIOA_INPUT_PULLUP || Copy_u8Mode == GPIOA_INPUT_PULLDOWN))
                {
                    GPIOA_CRL |= (GPIOA_INPUT_PULLUP << (Copy_u8PinId + 2));
                }
                else
                {
                    GPIOA_CRL |= (Copy_u8Mode << (Copy_u8PinId + 2));
                }

                if (Copy_u8Mode == GPIOA_INPUT_PULLUP)
                {
                    SET_BIT(GPIOA_ODR, Copy_u8PinId / 4);
                }
                else if (Copy_u8Mode == GPIOA_INPUT_PULLDOWN)
                {
                    CLR_BIT(GPIOA_ODR, Copy_u8PinId / 4);
                }
            }
            else if (Copy_u8PinId >= 8)
            {
                // Adjust the pin index for pins 8 and higher
                Copy_u8PinId = (Copy_u8PinId - 8) * 4;
                // Clear and set the direction
                GPIOA_CRH &= ~(0b1111 << Copy_u8PinId);
                GPIOA_CRH |= (Copy_u8Direction << Copy_u8PinId);

                // Set the mode or pull-up/pull-down resistor
                if (Copy_u8Direction == GPIOA_INPUT && (Copy_u8Mode == GPIOA_INPUT_PULLUP || Copy_u8Mode == GPIOA_INPUT_PULLDOWN))
                {
                    GPIOA_CRH |= (GPIOA_INPUT_PULLUP << (Copy_u8PinId + 2));
                }
                else
                {
                    GPIOA_CRH |= (Copy_u8Mode << (Copy_u8PinId + 2));
                }

                if (Copy_u8Mode == GPIOA_INPUT_PULLUP)
                {
                    SET_BIT(GPIOA_ODR, ((Copy_u8PinId / 4) + 8));
                }
                else if (Copy_u8Mode == GPIOA_INPUT_PULLDOWN)
                {
                    CLR_BIT(GPIOA_ODR, ((Copy_u8PinId / 4) + 8));
                }
            }
            break;
    }
}

// Function to set the value of a GPIO pin
void MGPIO_voidSetPinValue(u8 Copy_u8PortId, u8 Copy_u8PinId, u8 Copy_u8PinValue)
{
    switch (Copy_u8PortId)
    {
        case PORTA:
            // Clear and set the pin value
            CLR_BIT(GPIOA_ODR, Copy_u8PinId);
            GPIOA_ODR |= (Copy_u8PinValue << Copy_u8PinId);
            break;
    }
}

// Function to get the value of a GPIO pin
u8 MGPIO_u8GetPinValue(u8 Copy_u8PortId, u8 Copy_u8PinId)
{
    u8 Local_u8PinValue = 0;
    switch (Copy_u8PortId)
    {
        case PORTA:
            // Read the pin value
            Local_u8PinValue = GET_BIT(GPIOA_IDR, Copy_u8PinId);
            break;
    }
    return Local_u8PinValue;
}
