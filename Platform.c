// #############################################################################
// #### Copyright ##############################################################
// #############################################################################

/*
 * Copyright 2024 BaSSeM
 *
 *    Licensed under the Apache License, Version 2.0 (the "License");
 *    you may not use this file except in compliance with the License.
 *    You may obtain a copy of the License at
 *
 *        http://www.apache.org/licenses/LICENSE-2.0
 *
 *    Unless required by applicable law or agreed to in writing, software
 *    distributed under the License is distributed on an "AS IS" BASIS,
 *    WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *    See the License for the specific language governing permissions and
 *    limitations under the License.
 */

// #############################################################################
// #### Description ############################################################
// #############################################################################

// #############################################################################
// #### Control Include(s) #####################################################
// #############################################################################

#include "Platform.h"

// #############################################################################
// #### Control Macro(s) #######################################################
// #############################################################################

#ifndef DEBUG
    #define DEBUG
#endif

#ifdef DEBUG
    #undef DEBUG
#endif

// #############################################################################
// #### File Guard #############################################################
// #############################################################################

// #############################################################################
// #### Include(s) #############################################################
// #############################################################################

// #############################################################################
// #### Private Macro(s) #######################################################
// #############################################################################

// #############################################################################
// #### Private Type(s) ########################################################
// #############################################################################

// #############################################################################
// #### Private Method(s) Prototype ############################################
// #############################################################################

// #############################################################################
// #### Private Variable(s) ####################################################
// #############################################################################

// #############################################################################
// #### Private Method(s) ######################################################
// #############################################################################

// #############################################################################
// #### Public Method(s) #######################################################
// #############################################################################

PLATFORM_Status_t PLATFORM_Initialize( void )
{
    PLATFORM_Status_t Status = PLATFORM_Status_Success;
    KERNEL_Status_t KERNEL_Status = KERNEL_Status_Success;
    WDG_Status_t WDG_Status = WDG_Status_Success;
    GPIO_Status_t GPIO_Status = GPIO_Status_Success;
    RTC_Status_t RTC_Status = RTC_Status_Success;
    DMA_Status_t DMA_Status = DMA_Status_Success;
    CRC_Status_t CRC_Status = CRC_Status_Success;
    USB_Status_t USB_Status = USB_Status_Success;
    UART_Status_t UART_Status = UART_Status_Success;
    SPI_Status_t SPI_Status = SPI_Status_Success;
    EEPROM_Status_t EEPROM_Status = EEPROM_Status_Success;
    TDC_Status_t TDC_Status = TDC_Status_Success;
    LCD_Status_t LCD_Status = LCD_Status_Success;
    GSM_Status_t GSM_Status = GSM_Status_Success;
    PWR_Status_t PWR_Status = PWR_Status_Success;
    LOG_Status_t LOG_Status = LOG_Status_Success;
    TIM_Status_t TIM_Status = TIM_Status_Success;
    CLI_Status_t CLI_Status = CLI_Status_Success;

    do
    {
        // TODO The kernel should be last to be initialized,
        //      So as to guarantee that modules and services have been initialized and ready to serve
        // @note Initialize the kernel
        if ( ( KERNEL_Status = KERNEL_Initialize( PLATFORM_DEFAULT_KERNEL ) ) != KERNEL_Status_Success )
        {
            Status = PLATFORM_Status_Error;
            break;
        }

        // @note Initialize the modules
        if ( ( WDG_Status = WDG_Initialize( WDG_All ) ) != WDG_Status_Success )
        {
            Status = PLATFORM_Status_Error;
            break;
        }

        if ( ( GPIO_Status = GPIO_Initialize( GPIO_All ) ) != GPIO_Status_Success )
        {
            Status = PLATFORM_Status_Error;
            break;
        }

        if ( ( RTC_Status = RTC_Initialize( RTC_All ) ) != RTC_Status_Success )
        {
            Status = PLATFORM_Status_Error;
            break;
        }

        if ( ( DMA_Status = DMA_Initialize( DMA_All ) ) != DMA_Status_Success )
        {
            Status = PLATFORM_Status_Error;
            break;
        }

        if ( ( CRC_Status = CRC_Initialize( CRC_All ) ) != CRC_Status_Success )
        {
            Status = PLATFORM_Status_Error;
            break;
        }

        if ( ( USB_Status = USB_Initialize( USB_All ) ) != USB_Status_Success )
        {
            Status = PLATFORM_Status_Error;
            break;
        }

        if ( ( UART_Status = UART_Initialize( UART_All ) ) != UART_Status_Success )
        {
            Status = PLATFORM_Status_Error;
            break;
        }

        if ( ( SPI_Status = SPI_Initialize( SPI_All ) ) != SPI_Status_Success )
        {
            Status = PLATFORM_Status_Error;
            break;
        }

        if ( ( EEPROM_Status = EEPROM_Initialize( EEPROM_All ) ) != EEPROM_Status_Success )
        {
            Status = PLATFORM_Status_Error;
            break;
        }

        if ( ( TDC_Status = TDC_Initialize( TDC_All ) ) != TDC_Status_Success )
        {
            Status = PLATFORM_Status_Error;
            break;
        }

        if ( ( LCD_Status = LCD_Initialize( LCD_All ) ) != LCD_Status_Success )
        {
            Status = PLATFORM_Status_Error;
            break;
        }

        if ( ( GSM_Status = GSM_Initialize( GSM_All ) ) != GSM_Status_Success )
        {
            Status = PLATFORM_Status_Error;
            break;
        }

        if ( ( PWR_Status = PWR_Initialize( PWR_All ) ) != PWR_Status_Success )
        {
            Status = PLATFORM_Status_Error;
            break;
        }

        // @note Initialize the services
        if ( ( LOG_Status = LOG_Initialize( LOG_All ) ) != LOG_Status_Success )
        {
            Status = PLATFORM_Status_Error;
            break;
        }

        if ( ( TIM_Status = TIM_Initialize( TIM_All ) ) != TIM_Status_Success )
        {
            Status = PLATFORM_Status_Error;
            break;
        }

        if ( ( CLI_Status = CLI_Initialize( CLI_All ) ) != CLI_Status_Success )
        {
            Status = PLATFORM_Status_Error;
            break;
        }

        // @note Set kernel tick source
        // TODO Kernel should be able to select the tick source

        // @note Delegate control to kernel
        // TODO Kernel should be able to take control
    }
    while ( 0 );

    return Status;
}

PLATFORM_Status_t PLATFORM_Cycle( void )
{
    PLATFORM_Status_t Status = PLATFORM_Status_Success;
    KERNEL_Status_t KERNEL_Status = KERNEL_Status_Success;
    WDG_Status_t WDG_Status = WDG_Status_Success;
    GPIO_Status_t GPIO_Status = GPIO_Status_Success;
    RTC_Status_t RTC_Status = RTC_Status_Success;
    DMA_Status_t DMA_Status = DMA_Status_Success;
    CRC_Status_t CRC_Status = CRC_Status_Success;
    USB_Status_t USB_Status = USB_Status_Success;
    UART_Status_t UART_Status = UART_Status_Success;
    SPI_Status_t SPI_Status = SPI_Status_Success;
    EEPROM_Status_t EEPROM_Status = EEPROM_Status_Success;
    TDC_Status_t TDC_Status = TDC_Status_Success;
    LCD_Status_t LCD_Status = LCD_Status_Success;
    GSM_Status_t GSM_Status = GSM_Status_Success;
    PWR_Status_t PWR_Status = PWR_Status_Success;
    LOG_Status_t LOG_Status = LOG_Status_Success;
    TIM_Status_t TIM_Status = TIM_Status_Success;
    CLI_Status_t CLI_Status = CLI_Status_Success;

    do
    {
        // TODO Enhance underlying tasks cycle to have consistent timing
        // TODO Monitor tasks' cycle duration, keep record of min, max, average, ...etc statistics

        // @note Cycle the kernel
        if ( ( KERNEL_Status = KERNEL_Cycle( PLATFORM_DEFAULT_KERNEL ) ) != KERNEL_Status_Success )
        {
            Status = PLATFORM_Status_Error;
            break;
        }

        // @note Cycle the modules
        if ( ( WDG_Status = WDG_Cycle( WDG_All ) ) != WDG_Status_Success )
        {
            Status = PLATFORM_Status_Error;
            break;
        }

        if ( ( GPIO_Status = GPIO_Cycle( GPIO_All ) ) != GPIO_Status_Success )
        {
            Status = PLATFORM_Status_Error;
            break;
        }

        if ( ( RTC_Status = RTC_Cycle( RTC_All ) ) != RTC_Status_Success )
        {
            Status = PLATFORM_Status_Error;
            break;
        }

        if ( ( DMA_Status = DMA_Cycle( DMA_All ) ) != DMA_Status_Success )
        {
            Status = PLATFORM_Status_Error;
            break;
        }

        if ( ( CRC_Status = CRC_Cycle( CRC_All ) ) != CRC_Status_Success )
        {
            Status = PLATFORM_Status_Error;
            break;
        }

        if ( ( USB_Status = USB_Cycle( USB_All ) ) != USB_Status_Success )
        {
            Status = PLATFORM_Status_Error;
            break;
        }

        if ( ( UART_Status = UART_Cycle( UART_All ) ) != UART_Status_Success )
        {
            Status = PLATFORM_Status_Error;
            break;
        }

        if ( ( SPI_Status = SPI_Cycle( SPI_All ) ) != SPI_Status_Success )
        {
            Status = PLATFORM_Status_Error;
            break;
        }

        if ( ( EEPROM_Status = EEPROM_Cycle( EEPROM_All ) ) != EEPROM_Status_Success )
        {
            Status = PLATFORM_Status_Error;
            break;
        }

        if ( ( TDC_Status = TDC_Cycle( TDC_All ) ) != TDC_Status_Success )
        {
            Status = PLATFORM_Status_Error;
            break;
        }

        if ( ( LCD_Status = LCD_Cycle( LCD_All ) ) != LCD_Status_Success )
        {
            Status = PLATFORM_Status_Error;
            break;
        }

        if ( ( GSM_Status = GSM_Cycle( GSM_All ) ) != GSM_Status_Success )
        {
            Status = PLATFORM_Status_Error;
            break;
        }

        GPIO_Write( DEBUG_GPIO_O_2, GPIO_Value_Low );
        if ( ( PWR_Status = PWR_Cycle( PWR_All ) ) != PWR_Status_Success )
        {
            Status = PLATFORM_Status_Error;
            break;
        }
        GPIO_Write( DEBUG_GPIO_O_2, GPIO_Value_High );

        // @note Cycle the services
        if ( ( LOG_Status = LOG_Cycle( LOG_All ) ) != LOG_Status_Success )
        {
            Status = PLATFORM_Status_Error;
            break;
        }

        if ( ( TIM_Status = TIM_Cycle( TIM_All ) ) != TIM_Status_Success )
        {
            Status = PLATFORM_Status_Error;
            break;
        }

        if ( ( CLI_Status = CLI_Cycle( CLI_All ) ) != CLI_Status_Success )
        {
            Status = PLATFORM_Status_Error;
            break;
        }
    }
    while ( 0 );

    return Status;
}

PLATFORM_Status_t PLATFORM_DeInitialize( void )
{
    PLATFORM_Status_t Status = PLATFORM_Status_Success;
    KERNEL_Status_t KERNEL_Status = KERNEL_Status_Success;
    WDG_Status_t WDG_Status = WDG_Status_Success;
    GPIO_Status_t GPIO_Status = GPIO_Status_Success;
    RTC_Status_t RTC_Status = RTC_Status_Success;
    DMA_Status_t DMA_Status = DMA_Status_Success;
    CRC_Status_t CRC_Status = CRC_Status_Success;
    USB_Status_t USB_Status = USB_Status_Success;
    UART_Status_t UART_Status = UART_Status_Success;
    SPI_Status_t SPI_Status = SPI_Status_Success;
    EEPROM_Status_t EEPROM_Status = EEPROM_Status_Success;
    TDC_Status_t TDC_Status = TDC_Status_Success;
    LCD_Status_t LCD_Status = LCD_Status_Success;
    GSM_Status_t GSM_Status = GSM_Status_Success;
    PWR_Status_t PWR_Status = PWR_Status_Success;
    LOG_Status_t LOG_Status = LOG_Status_Success;
    TIM_Status_t TIM_Status = TIM_Status_Success;
    CLI_Status_t CLI_Status = CLI_Status_Success;

    do
    {
        // @note DeInitialize the kernel
        if ( ( KERNEL_Status = KERNEL_DeInitialize( PLATFORM_DEFAULT_KERNEL ) ) != KERNEL_Status_Success )
        {
            Status = PLATFORM_Status_Error;
            break;
        }

        // @note DeInitialize the modules
        if ( ( WDG_Status = WDG_DeInitialize( WDG_All ) ) != WDG_Status_Success )
        {
            Status = PLATFORM_Status_Error;
            break;
        }

        if ( ( GPIO_Status = GPIO_DeInitialize( GPIO_All ) ) != GPIO_Status_Success )
        {
            Status = PLATFORM_Status_Error;
            break;
        }

        if ( ( RTC_Status = RTC_DeInitialize( RTC_All ) ) != RTC_Status_Success )
        {
            Status = PLATFORM_Status_Error;
            break;
        }

        if ( ( DMA_Status = DMA_DeInitialize( DMA_All ) ) != DMA_Status_Success )
        {
            Status = PLATFORM_Status_Error;
            break;
        }

        if ( ( CRC_Status = CRC_DeInitialize( CRC_All ) ) != CRC_Status_Success )
        {
            Status = PLATFORM_Status_Error;
            break;
        }

        if ( ( USB_Status = USB_DeInitialize( USB_All ) ) != USB_Status_Success )
        {
            Status = PLATFORM_Status_Error;
            break;
        }

        if ( ( UART_Status = UART_DeInitialize( UART_All ) ) != UART_Status_Success )
        {
            Status = PLATFORM_Status_Error;
            break;
        }

        if ( ( SPI_Status = SPI_DeInitialize( SPI_All ) ) != SPI_Status_Success )
        {
            Status = PLATFORM_Status_Error;
            break;
        }

        if ( ( EEPROM_Status = EEPROM_DeInitialize( EEPROM_All ) ) != EEPROM_Status_Success )
        {
            Status = PLATFORM_Status_Error;
            break;
        }

        if ( ( TDC_Status = TDC_DeInitialize( TDC_All ) ) != TDC_Status_Success )
        {
            Status = PLATFORM_Status_Error;
            break;
        }

        if ( ( LCD_Status = LCD_DeInitialize( LCD_All ) ) != LCD_Status_Success )
        {
            Status = PLATFORM_Status_Error;
            break;
        }

        if ( ( GSM_Status = GSM_DeInitialize( GSM_All ) ) != GSM_Status_Success )
        {
            Status = PLATFORM_Status_Error;
            break;
        }

        if ( ( PWR_Status = PWR_DeInitialize( PWR_All ) ) != PWR_Status_Success )
        {
            Status = PLATFORM_Status_Error;
            break;
        }

        // @note DeInitialize the services
        if ( ( LOG_Status = LOG_DeInitialize( LOG_All ) ) != LOG_Status_Success )
        {
            Status = PLATFORM_Status_Error;
            break;
        }

        if ( ( TIM_Status = TIM_DeInitialize( TIM_All ) ) != TIM_Status_Success )
        {
            Status = PLATFORM_Status_Error;
            break;
        }

        if ( ( CLI_Status = CLI_DeInitialize( CLI_All ) ) != CLI_Status_Success )
        {
            Status = PLATFORM_Status_Error;
            break;
        }
    }
    while ( 0 );

    return Status;
}

// #############################################################################
// #### Public Variable(s) #####################################################
// #############################################################################

const char PLATFORM_VERSION[] = "0.0.0.v20261005-0352";

// #############################################################################
// #### File Guard #############################################################
// #############################################################################

// #############################################################################
// #### END OF FILE ############################################################
// #############################################################################
