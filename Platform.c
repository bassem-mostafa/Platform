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

KERNEL_Status_t Task_PWR_Initialize( void );
KERNEL_Status_t Task_PWR_Cycle( void );
KERNEL_Status_t Task_PWR_DeInitialize( void );

KERNEL_Status_t Task_GPIO_Initialize( void );
KERNEL_Status_t Task_GPIO_Cycle( void );
KERNEL_Status_t Task_GPIO_DeInitialize( void );

KERNEL_Status_t Task_USB_Initialize( void );
KERNEL_Status_t Task_USB_Cycle( void );
KERNEL_Status_t Task_USB_DeInitialize( void );

KERNEL_Status_t Task_UART_Initialize( void );
KERNEL_Status_t Task_UART_Cycle( void );
KERNEL_Status_t Task_UART_DeInitialize( void );

KERNEL_Status_t Task_LOG_Initialize( void );
KERNEL_Status_t Task_LOG_Cycle( void );
KERNEL_Status_t Task_LOG_DeInitialize( void );

KERNEL_Status_t Task_RTC_Initialize( void );
KERNEL_Status_t Task_RTC_Cycle( void );
KERNEL_Status_t Task_RTC_DeInitialize( void );

KERNEL_Status_t Task_TIM_Initialize( void );
KERNEL_Status_t Task_TIM_Cycle( void );
KERNEL_Status_t Task_TIM_DeInitialize( void );

KERNEL_Status_t Task_SPI_Initialize( void );
KERNEL_Status_t Task_SPI_Cycle( void );
KERNEL_Status_t Task_SPI_DeInitialize( void );

KERNEL_Status_t Task_EEPROM_Initialize( void );
KERNEL_Status_t Task_EEPROM_Cycle( void );
KERNEL_Status_t Task_EEPROM_DeInitialize( void );

KERNEL_Status_t Task_TDC_Initialize( void );
KERNEL_Status_t Task_TDC_Cycle( void );
KERNEL_Status_t Task_TDC_DeInitialize( void );

KERNEL_Status_t Task_GSM_Initialize( void );
KERNEL_Status_t Task_GSM_Cycle( void );
KERNEL_Status_t Task_GSM_DeInitialize( void );

KERNEL_Status_t Task_LCD_Initialize( void );
KERNEL_Status_t Task_LCD_Cycle( void );
KERNEL_Status_t Task_LCD_DeInitialize( void );

KERNEL_Status_t Task_CLI_Initialize( void );
KERNEL_Status_t Task_CLI_Cycle( void );
KERNEL_Status_t Task_CLI_DeInitialize( void );

// #############################################################################
// #### Private Variable(s) ####################################################
// #############################################################################

static KERNEL_Task_t KERNEL_Task_PWR = {
    Task_PWR_Initialize,
    Task_PWR_Cycle,
    Task_PWR_DeInitialize,
};

static KERNEL_Task_t KERNEL_Task_GPIO = {
    Task_GPIO_Initialize,
    Task_GPIO_Cycle,
    Task_GPIO_DeInitialize,
};

static KERNEL_Task_t KERNEL_Task_USB = {
    Task_USB_Initialize,
    Task_USB_Cycle,
    Task_USB_DeInitialize,
};

static KERNEL_Task_t KERNEL_Task_UART = {
    Task_UART_Initialize,
    Task_UART_Cycle,
    Task_UART_DeInitialize,
};

static KERNEL_Task_t KERNEL_Task_LOG = {
    Task_LOG_Initialize,
    Task_LOG_Cycle,
    Task_LOG_DeInitialize,
};

static KERNEL_Task_t KERNEL_Task_RTC = {
    Task_RTC_Initialize,
    Task_RTC_Cycle,
    Task_RTC_DeInitialize,
};

static KERNEL_Task_t KERNEL_Task_TIM = {
    Task_TIM_Initialize,
    Task_TIM_Cycle,
    Task_TIM_DeInitialize,
};

static KERNEL_Task_t KERNEL_Task_SPI = {
    Task_SPI_Initialize,
    Task_SPI_Cycle,
    Task_SPI_DeInitialize,
};

static KERNEL_Task_t KERNEL_Task_EEPROM = {
    Task_EEPROM_Initialize,
    Task_EEPROM_Cycle,
    Task_EEPROM_DeInitialize,
};

static KERNEL_Task_t KERNEL_Task_TDC = {
    Task_TDC_Initialize,
    Task_TDC_Cycle,
    Task_TDC_DeInitialize,
};

static KERNEL_Task_t KERNEL_Task_GSM = {
    Task_GSM_Initialize,
    Task_GSM_Cycle,
    Task_GSM_DeInitialize,
};

static KERNEL_Task_t KERNEL_Task_LCD = {
    Task_LCD_Initialize,
    Task_LCD_Cycle,
    Task_LCD_DeInitialize,
};

static KERNEL_Task_t KERNEL_Task_CLI = {
    Task_CLI_Initialize,
    Task_CLI_Cycle,
    Task_CLI_DeInitialize,
};

static KERNEL_Task_t * KERNEL_Task[] = {
    &KERNEL_Task_PWR,
    &KERNEL_Task_GPIO,

    &KERNEL_Task_RTC,
    &KERNEL_Task_TIM,

    &KERNEL_Task_USB,
    &KERNEL_Task_UART,
    &KERNEL_Task_LOG,

    &KERNEL_Task_SPI,
    &KERNEL_Task_EEPROM,
    &KERNEL_Task_TDC,

    &KERNEL_Task_GSM,

    &KERNEL_Task_LCD,
    &KERNEL_Task_CLI,

    NULL, // End indicator
};

// #############################################################################
// #### Private Method(s) ######################################################
// #############################################################################

KERNEL_Status_t Task_PWR_Initialize( void )
{
    KERNEL_Status_t Status = KERNEL_Status_Error;
    do
    {
        PWR_Status_t PWR_Status = PWR_Status_Error;
        if ( ( PWR_Status = PWR_Initialize( ) ) != PWR_Status_Success )
        {
            Status = KERNEL_Status_Error;
            break;
        }
        Status = KERNEL_Status_Success;
    }
    while ( 0 );
    return Status;
}

KERNEL_Status_t Task_PWR_Cycle( void )
{
    KERNEL_Status_t Status = KERNEL_Status_Error;
    do
    {
        PWR_Status_t PWR_Status = PWR_Status_Error;
        if ( ( PWR_Status = PWR_Cycle( ) ) != PWR_Status_Success )
        {
            Status = KERNEL_Status_Error;
            break;
        }
        Status = KERNEL_Status_Success;
    }
    while ( 0 );
    return Status;
}

KERNEL_Status_t Task_PWR_DeInitialize( void )
{
    KERNEL_Status_t Status = KERNEL_Status_Error;
    do
    {
        PWR_Status_t PWR_Status = PWR_Status_Error;
        if ( ( PWR_Status = PWR_DeInitialize( ) ) != PWR_Status_Success )
        {
            Status = KERNEL_Status_Error;
            break;
        }
        Status = KERNEL_Status_Success;
    }
    while ( 0 );
    return Status;
}

KERNEL_Status_t Task_GPIO_Initialize( void )
{
    KERNEL_Status_t Status = KERNEL_Status_Error;

    do
    {
        GPIO_Status_t GPIO_Status = GPIO_Status_Error;
        if ( ( GPIO_Status = GPIO_Initialize( GPIO_All ) ) != GPIO_Status_Success )
        {
            Status = KERNEL_Status_Error;
            break;
        }

        Status = KERNEL_Status_Success;
    }
    while ( 0 );

    return Status;
}

KERNEL_Status_t Task_GPIO_Cycle( void )
{
    KERNEL_Status_t Status = KERNEL_Status_Error;

    do
    {
        GPIO_Status_t GPIO_Status = GPIO_Status_Error;
        if ( ( GPIO_Status = GPIO_Cycle( GPIO_All ) ) != GPIO_Status_Success )
        {
            Status = KERNEL_Status_Error;
            break;
        }

        Status = KERNEL_Status_Success;
    }
    while ( 0 );

    return Status;
}

KERNEL_Status_t Task_GPIO_DeInitialize( void )
{
    KERNEL_Status_t Status = KERNEL_Status_Error;

    do
    {
        GPIO_Status_t GPIO_Status = GPIO_Status_Error;
        if ( ( GPIO_Status = GPIO_DeInitialize( GPIO_All ) ) != GPIO_Status_Success )
        {
            Status = KERNEL_Status_Error;
            break;
        }

        Status = KERNEL_Status_Success;
    }
    while ( 0 );

    return Status;
}

KERNEL_Status_t Task_USB_Initialize( void )
{
    KERNEL_Status_t Status = KERNEL_Status_Error;
    do
    {
        USB_Status_t USB_Status = USB_Status_Error;
        if ( ( USB_Status = USB_Initialize( USB_All ) ) != USB_Status_Success )
        {
            Status = KERNEL_Status_Error;
            break;
        }
        Status = KERNEL_Status_Success;
    }
    while ( 0 );
    return Status;
}

KERNEL_Status_t Task_USB_Cycle( void )
{
    KERNEL_Status_t Status = KERNEL_Status_Error;
    do
    {
        USB_Status_t USB_Status = USB_Status_Error;
        if ( ( USB_Status = USB_Cycle( USB_All ) ) != USB_Status_Success )
        {
            Status = KERNEL_Status_Error;
            break;
        }
        Status = KERNEL_Status_Success;
    }
    while ( 0 );
    return Status;
}

KERNEL_Status_t Task_USB_DeInitialize( void )
{
    KERNEL_Status_t Status = KERNEL_Status_Error;
    do
    {
        USB_Status_t USB_Status = USB_Status_Error;
        if ( ( USB_Status = USB_DeInitialize( USB_All ) ) != USB_Status_Success )
        {
            Status = KERNEL_Status_Error;
            break;
        }
        Status = KERNEL_Status_Success;
    }
    while ( 0 );
    return Status;
}

KERNEL_Status_t Task_UART_Initialize( void )
{
    KERNEL_Status_t Status = KERNEL_Status_Error;
    do
    {
        UART_Status_t UART_Status = UART_Status_Error;
        if ( ( UART_Status = UART_Initialize( UART_All ) ) != UART_Status_Success )
        {
            Status = KERNEL_Status_Error;
            break;
        }
        Status = KERNEL_Status_Success;
    }
    while ( 0 );
    return Status;
}

KERNEL_Status_t Task_UART_Cycle( void )
{
    KERNEL_Status_t Status = KERNEL_Status_Error;
    do
    {
        UART_Status_t UART_Status = UART_Status_Error;
        if ( ( UART_Status = UART_Cycle( UART_All ) ) != UART_Status_Success )
        {
            Status = KERNEL_Status_Error;
            break;
        }
        Status = KERNEL_Status_Success;
    }
    while ( 0 );
    return Status;
}

KERNEL_Status_t Task_UART_DeInitialize( void )
{
    KERNEL_Status_t Status = KERNEL_Status_Error;
    do
    {
        UART_Status_t UART_Status = UART_Status_Error;
        if ( ( UART_Status = UART_DeInitialize( UART_All ) ) != UART_Status_Success )
        {
            Status = KERNEL_Status_Error;
            break;
        }
        Status = KERNEL_Status_Success;
    }
    while ( 0 );
    return Status;
}

KERNEL_Status_t Task_LOG_Initialize( void )
{
    KERNEL_Status_t Status = KERNEL_Status_Error;

    do
    {
        LOG_Status_t LOG_Status = LOG_Status_Error;
        if ( ( LOG_Status = LOG_Initialize( LOG_All ) ) != LOG_Status_Success )
        {
            Status = KERNEL_Status_Error;
            break;
        }

        Status = KERNEL_Status_Success;
    }
    while ( 0 );

    return Status;
}

KERNEL_Status_t Task_LOG_Cycle( void )
{
    KERNEL_Status_t Status = KERNEL_Status_Error;
    do
    {
        LOG_Status_t LOG_Status = LOG_Status_Error;
        if ( ( LOG_Status = LOG_Cycle( LOG_All ) ) != LOG_Status_Success )
        {
            Status = KERNEL_Status_Error;
            break;
        }
        Status = KERNEL_Status_Success;
    }
    while ( 0 );
    return Status;
}

KERNEL_Status_t Task_LOG_DeInitialize( void )
{
    KERNEL_Status_t Status = KERNEL_Status_Error;
    do
    {
        LOG_Status_t LOG_Status = LOG_Status_Error;
        if ( ( LOG_Status = LOG_DeInitialize( LOG_All ) ) != LOG_Status_Success )
        {
            Status = KERNEL_Status_Error;
            break;
        }
        Status = KERNEL_Status_Success;
    }
    while ( 0 );
    return Status;
}

KERNEL_Status_t Task_RTC_Initialize( void )
{
    KERNEL_Status_t Status = KERNEL_Status_Error;
    do
    {
        RTC_Status_t RTC_Status = RTC_Status_Error;
        if ( ( RTC_Status = RTC_Initialize( RTC_All ) ) != RTC_Status_Success )
        {
            Status = KERNEL_Status_Error;
            break;
        }
        Status = KERNEL_Status_Success;
    }
    while ( 0 );
    return Status;
}

KERNEL_Status_t Task_RTC_Cycle( void )
{
    KERNEL_Status_t Status = KERNEL_Status_Error;
    do
    {
        RTC_Status_t RTC_Status = RTC_Status_Error;
        if ( ( RTC_Status = RTC_Cycle( RTC_All ) ) != RTC_Status_Success )
        {
            Status = KERNEL_Status_Error;
            break;
        }
        Status = KERNEL_Status_Success;
    }
    while ( 0 );
    return Status;
}

KERNEL_Status_t Task_RTC_DeInitialize( void )
{
    KERNEL_Status_t Status = KERNEL_Status_Error;
    do
    {
        RTC_Status_t RTC_Status = RTC_Status_Error;
        if ( ( RTC_Status = RTC_DeInitialize( RTC_All ) ) != RTC_Status_Success )
        {
            Status = KERNEL_Status_Error;
            break;
        }
        Status = KERNEL_Status_Success;
    }
    while ( 0 );
    return Status;
}

KERNEL_Status_t Task_TIM_Initialize( void )
{
    KERNEL_Status_t Status = KERNEL_Status_Error;
    do
    {
        TIM_Status_t TIM_Status = TIM_Status_Error;
        if ( ( TIM_Status = TIM_Initialize( TIM_All ) ) != TIM_Status_Success )
        {
            Status = KERNEL_Status_Error;
            break;
        }
        Status = KERNEL_Status_Success;
    }
    while ( 0 );
    return Status;
}

KERNEL_Status_t Task_TIM_Cycle( void )
{
    KERNEL_Status_t Status = KERNEL_Status_Error;
    do
    {
        TIM_Status_t TIM_Status = TIM_Status_Error;
        if ( ( TIM_Status = TIM_Cycle( TIM_All ) ) != TIM_Status_Success )
        {
            Status = KERNEL_Status_Error;
            break;
        }
        Status = KERNEL_Status_Success;
    }
    while ( 0 );
    return Status;
}

KERNEL_Status_t Task_TIM_DeInitialize( void )
{
    KERNEL_Status_t Status = KERNEL_Status_Error;
    do
    {
        TIM_Status_t TIM_Status = TIM_Status_Error;
        if ( ( TIM_Status = TIM_DeInitialize( TIM_All ) ) != TIM_Status_Success )
        {
            Status = KERNEL_Status_Error;
            break;
        }
        Status = KERNEL_Status_Success;
    }
    while ( 0 );
    return Status;
}

KERNEL_Status_t Task_SPI_Initialize( void )
{
    KERNEL_Status_t Status = KERNEL_Status_Error;
    do
    {
        SPI_Status_t SPI_Status = SPI_Status_Error;
        if ( ( SPI_Status = SPI_Initialize( SPI_All ) ) != SPI_Status_Success )
        {
            Status = KERNEL_Status_Error;
            break;
        }
        Status = KERNEL_Status_Success;
    }
    while ( 0 );
    return Status;
}

KERNEL_Status_t Task_SPI_Cycle( void )
{
    KERNEL_Status_t Status = KERNEL_Status_Error;
    do
    {
        SPI_Status_t SPI_Status = SPI_Status_Error;
        if ( ( SPI_Status = SPI_Cycle( SPI_All ) ) != SPI_Status_Success )
        {
            Status = KERNEL_Status_Error;
            break;
        }
        Status = KERNEL_Status_Success;
    }
    while ( 0 );
    return Status;
}

KERNEL_Status_t Task_SPI_DeInitialize( void )
{
    KERNEL_Status_t Status = KERNEL_Status_Error;
    do
    {
        SPI_Status_t SPI_Status = SPI_Status_Error;
        if ( ( SPI_Status = SPI_DeInitialize( SPI_All ) ) != SPI_Status_Success )
        {
            Status = KERNEL_Status_Error;
            break;
        }
        Status = KERNEL_Status_Success;
    }
    while ( 0 );
    return Status;
}

KERNEL_Status_t Task_EEPROM_Initialize( void )
{
    KERNEL_Status_t Status = KERNEL_Status_Error;
    do
    {
        EEPROM_Status_t EEPROM_Status = EEPROM_Status_Error;
        if ( ( EEPROM_Status = EEPROM_Initialize( EEPROM_All ) ) != EEPROM_Status_Success )
        {
            Status = KERNEL_Status_Error;
            break;
        }
        Status = KERNEL_Status_Success;
    }
    while ( 0 );
    return Status;
}

KERNEL_Status_t Task_EEPROM_Cycle( void )
{
    KERNEL_Status_t Status = KERNEL_Status_Error;
    do
    {
        EEPROM_Status_t EEPROM_Status = EEPROM_Status_Error;
        if ( ( EEPROM_Status = EEPROM_Cycle( EEPROM_All ) ) != EEPROM_Status_Success )
        {
            Status = KERNEL_Status_Error;
            break;
        }
        Status = KERNEL_Status_Success;
    }
    while ( 0 );
    return Status;
}

KERNEL_Status_t Task_EEPROM_DeInitialize( void )
{
    KERNEL_Status_t Status = KERNEL_Status_Error;
    do
    {
        EEPROM_Status_t EEPROM_Status = EEPROM_Status_Error;
        if ( ( EEPROM_Status = EEPROM_DeInitialize( EEPROM_All ) ) != EEPROM_Status_Success )
        {
            Status = KERNEL_Status_Error;
            break;
        }
        Status = KERNEL_Status_Success;
    }
    while ( 0 );
    return Status;
}

KERNEL_Status_t Task_TDC_Initialize( void )
{
    KERNEL_Status_t Status = KERNEL_Status_Error;
    do
    {
        TDC_Status_t TDC_Status = TDC_Status_Error;
        if ( ( TDC_Status = TDC_Initialize( TDC_All ) ) != TDC_Status_Success )
        {
            Status = KERNEL_Status_Error;
            break;
        }
        Status = KERNEL_Status_Success;
    }
    while ( 0 );
    return Status;
}

KERNEL_Status_t Task_TDC_Cycle( void )
{
    KERNEL_Status_t Status = KERNEL_Status_Error;
    do
    {
        TDC_Status_t TDC_Status = TDC_Status_Error;
        if ( ( TDC_Status = TDC_Cycle( TDC_All ) ) != TDC_Status_Success )
        {
            Status = KERNEL_Status_Error;
            break;
        }
        Status = KERNEL_Status_Success;
    }
    while ( 0 );
    return Status;
}

KERNEL_Status_t Task_TDC_DeInitialize( void )
{
    KERNEL_Status_t Status = KERNEL_Status_Error;
    do
    {
        TDC_Status_t TDC_Status = TDC_Status_Error;
        if ( ( TDC_Status = TDC_DeInitialize( TDC_All ) ) != TDC_Status_Success )
        {
            Status = KERNEL_Status_Error;
            break;
        }
        Status = KERNEL_Status_Success;
    }
    while ( 0 );
    return Status;
}

KERNEL_Status_t Task_GSM_Initialize( void )
{
    KERNEL_Status_t Status = KERNEL_Status_Error;
    do
    {
        GSM_Status_t GSM_Status = GSM_Status_Error;
        if ( ( GSM_Status = GSM_Initialize( GSM_All ) ) != GSM_Status_Success )
        {
            Status = KERNEL_Status_Error;
            break;
        }
        Status = KERNEL_Status_Success;
    }
    while ( 0 );
    return Status;
}

KERNEL_Status_t Task_GSM_Cycle( void )
{
    KERNEL_Status_t Status = KERNEL_Status_Error;
    do
    {
        GSM_Status_t GSM_Status = GSM_Status_Error;
        if ( ( GSM_Status = GSM_Cycle( GSM_All ) ) != GSM_Status_Success )
        {
            Status = KERNEL_Status_Error;
            break;
        }
        Status = KERNEL_Status_Success;
    }
    while ( 0 );
    return Status;
}

KERNEL_Status_t Task_GSM_DeInitialize( void )
{
    KERNEL_Status_t Status = KERNEL_Status_Error;
    do
    {
        GSM_Status_t GSM_Status = GSM_Status_Error;
        if ( ( GSM_Status = GSM_DeInitialize( GSM_All ) ) != GSM_Status_Success )
        {
            Status = KERNEL_Status_Error;
            break;
        }
        Status = KERNEL_Status_Success;
    }
    while ( 0 );
    return Status;
}

KERNEL_Status_t Task_LCD_Initialize( void )
{
    KERNEL_Status_t Status = KERNEL_Status_Error;
    do
    {
        LCD_Status_t LCD_Status = LCD_Status_Error;
        if ( ( LCD_Status = LCD_Initialize( ) ) != LCD_Status_Success )
        {
            Status = KERNEL_Status_Error;
            break;
        }
        Status = KERNEL_Status_Success;
    }
    while ( 0 );
    return Status;
}

KERNEL_Status_t Task_LCD_Cycle( void )
{
    KERNEL_Status_t Status = KERNEL_Status_Error;
    do
    {
        LCD_Status_t LCD_Status = LCD_Status_Error;
        if ( ( LCD_Status = LCD_Cycle( ) ) != LCD_Status_Success )
        {
            Status = KERNEL_Status_Error;
            break;
        }
        Status = KERNEL_Status_Success;
    }
    while ( 0 );
    return Status;
}

KERNEL_Status_t Task_LCD_DeInitialize( void )
{
    KERNEL_Status_t Status = KERNEL_Status_Error;
    do
    {
        LCD_Status_t LCD_Status = LCD_Status_Error;
        if ( ( LCD_Status = LCD_DeInitialize( ) ) != LCD_Status_Success )
        {
            Status = KERNEL_Status_Error;
            break;
        }
        Status = KERNEL_Status_Success;
    }
    while ( 0 );
    return Status;
}

KERNEL_Status_t Task_CLI_Initialize( void )
{
    KERNEL_Status_t Status = KERNEL_Status_Error;
    do
    {
        CLI_Status_t CLI_Status = CLI_Status_Error;
        if ( ( CLI_Status = CLI_Initialize( ) ) != CLI_Status_Success )
        {
            Status = KERNEL_Status_Error;
            break;
        }
        Status = KERNEL_Status_Success;
    }
    while ( 0 );
    return Status;
}

KERNEL_Status_t Task_CLI_Cycle( void )
{
    KERNEL_Status_t Status = KERNEL_Status_Error;
    do
    {
        CLI_Status_t CLI_Status = CLI_Status_Error;
        if ( ( CLI_Status = CLI_Cycle( ) ) != CLI_Status_Success )
        {
            Status = KERNEL_Status_Error;
            break;
        }
        Status = KERNEL_Status_Success;
    }
    while ( 0 );
    return Status;
}

KERNEL_Status_t Task_CLI_DeInitialize( void )
{
    KERNEL_Status_t Status = KERNEL_Status_Error;
    do
    {
        CLI_Status_t CLI_Status = CLI_Status_Error;
        if ( ( CLI_Status = CLI_DeInitialize( ) ) != CLI_Status_Success )
        {
            Status = KERNEL_Status_Error;
            break;
        }
        Status = KERNEL_Status_Success;
    }
    while ( 0 );
    return Status;
}

// #############################################################################
// #### Public Method(s) #######################################################
// #############################################################################

PLATFORM_Status_t PLATFORM_Initiatize( void )
{
    PLATFORM_Status_t Status = PLATFORM_Status_Error;

    do
    {
        KERNEL_Status_t KERNEL_Status = KERNEL_Status_Error;
        if ( ( KERNEL_Status = KERNEL_Initialize( ) ) != KERNEL_Status_Success )
        {
            Status = PLATFORM_Status_Error;
            break;
        }

        for ( KERNEL_Task_t ** Task = KERNEL_Task; *Task != NULL; Task++ )
        {
            if ( ( KERNEL_Status = KERNEL_TaskCreate( *Task ) ) != KERNEL_Status_Success )
            {
                // FIXME
            }
        }

        Status = PLATFORM_Status_Success;
    }
    while ( 0 );

    return Status;
}

PLATFORM_Status_t PLATFORM_Cycle( void )
{
    PLATFORM_Status_t Status = PLATFORM_Status_Error;

    do
    {
        KERNEL_Status_t KERNEL_Status = KERNEL_Status_Error;
        if ( ( KERNEL_Status = KERNEL_Cycle( ) ) != KERNEL_Status_Success )
        {
            Status = PLATFORM_Status_Error;
            break;
        }

        Status = PLATFORM_Status_Success;
    }
    while ( 0 );

    return Status;
}

PLATFORM_Status_t PLATFORM_DeInitiatize( void )
{
    PLATFORM_Status_t Status = PLATFORM_Status_Error;

    do
    {
        KERNEL_Status_t KERNEL_Status = KERNEL_Status_Error;
        if ( ( KERNEL_Status = KERNEL_DeInitialize( ) ) != KERNEL_Status_Success )
        {
            Status = PLATFORM_Status_Error;
            break;
        }

        Status = PLATFORM_Status_Success;
    }
    while ( 0 );

    return Status;
}

// #############################################################################
// #### Public Variable(s) #####################################################
// #############################################################################

const char PLATFORM_VERSION[] = "0.0.0.v20260121-1138";

// #############################################################################
// #### File Guard #############################################################
// #############################################################################

// #############################################################################
// #### END OF FILE ############################################################
// #############################################################################
