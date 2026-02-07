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

/**
 *  @file
 *
 *  @brief Platform Flow Meter PORT
 */

// #############################################################################
// #### Control Include(s) #####################################################
// #############################################################################

// #############################################################################
// #### Control Macro(s) #######################################################
// #############################################################################

// #############################################################################
// #### File Guard #############################################################
// #############################################################################

/**
 *  @addtogroup Platform_Port
 *
 *  @{
 */

/**
 *  @defgroup Flow_Meter_Port Flow Meter
 *
 *  @{
 */

#ifndef PLATFORM_FLOW_METER_PORT_H_
    #define PLATFORM_FLOW_METER_PORT_H_

    #ifndef PLATFORM_FLOW_METER
        #define PLATFORM_FLOW_METER
    #endif

// #############################################################################
// #### Include(s) #############################################################
// #############################################################################

// #############################################################################
// #### Public Macro(s) ########################################################
// #############################################################################

/**
 *  @defgroup Flow_Meter_Port_Kernel Kernel
 *
 *  @{
 */

/**
 *  @brief Activated Kernel Variant
 *
 *  @{
 */

    #define KERNEL_FLOW_METER

/**
 *  @}
 *
 *  @}
 */

/**
 *  @defgroup Flow_Meter_Port_Module Module
 *
 *  @{
 */

/**
 *  @brief Activated Module PORT
 *
 *  @{
 */

    #define ADC_FLOW_METER
    #define DMA_FLOW_METER
    #define EEPROM_FLOW_METER
    #define FLASH_FLOW_METER
    #define GPIO_FLOW_METER
    #define GPRS_FLOW_METER
    #define GSM_FLOW_METER
    #define LCD_FLOW_METER
    #define LORA_FLOW_METER
    #define PWR_FLOW_METER
    #define RAM_FLOW_METER
    #define RTC_FLOW_METER
    #define SPI_FLOW_METER
    #define TCH_FLOW_METER
    #define TDC_FLOW_METER
    #define TMR_FLOW_METER
    #define UART_FLOW_METER
    #define USB_FLOW_METER

/**
 *  @}
 *
 *  @}
 */

/**
 *  @defgroup Flow_Meter_Port_Service Service
 *
 *  @{
 */

/**
 *  @brief Activated Service PORT
 *
 *  @{
 */

    #define CLI_FLOW_METER
    #define LOG_FLOW_METER
    #define MEM_FLOW_METER
    #define NET_FLOW_METER
    #define TIM_FLOW_METER

/**
 *  @}
 *
 *  @}
 */

/**
 *  @defgroup Flow_Meter_Port_Mapping Peripheral/Pin Mapping
 *
 *  @{
 */

/**
 *  @brief Peripheral/Pin Mapping
 *
 *  @{
 */

    #define PLATFORM_DEFAULT_LOG     LOG_1
    #define PLATFORM_DEFAULT_TIM     TIM_1

    #define SPI_1_SCK                GPIO_89 // PB3
    #define SPI_1_MOSI               GPIO_91 // PB5
    #define SPI_1_MISO               GPIO_Null

    #define SPI_2_SCK                GPIO_52 // PB13
    #define SPI_2_MOSI               GPIO_54 // PB15
    #define SPI_2_MISO               GPIO_53 // PB14

    #define SPI_3_SCK                GPIO_78 // PC10
    #define SPI_3_MOSI               GPIO_80 // PC12
    #define SPI_3_MISO               GPIO_79 // PC11

    #define UART_1_TX                GPIO_92 // PB6
    #define UART_1_RX                GPIO_93 // PB7

    #define UART_2_TX                GPIO_25 // PA2
    #define UART_2_RX                GPIO_26 // PA3

    #define USB_1_D_Plus             GPIO_71 // PA12
    #define USB_1_D_Minus            GPIO_70 // PA11
    #define USB_1_VBUS_Sense         GPIO_68 // PA9

    #define LCD_SPI                  SPI_1
    #define LCD_GPIO_SCK             SPI_1_SCK
    #define LCD_GPIO_MOSI            SPI_1_MOSI
    #define LCD_GPIO_BacklightEnable GPIO_85 // PD4
    #define LCD_GPIO_PowerEnable     GPIO_84 // PD3
    #define LCD_GPIO_RegisterSelect  GPIO_88 // PD7
    #define LCD_GPIO_Reset           GPIO_87 // PD6
    #define LCD_GPIO_ChipSelect      GPIO_86 // PD5

    #define TDC_SPI                  SPI_2
    #define TDC_GPIO_SCK             SPI_2_SCK
    #define TDC_GPIO_MOSI            SPI_2_MOSI
    #define TDC_GPIO_MISO            SPI_2_MISO
    #define TDC_GPIO_PowerEnable     GPIO_58 // PD11
    #define TDC_GPIO_Reset           GPIO_56 // PD9
    #define TDC_GPIO_ChipSelect      GPIO_55 // PD8
    #define TDC_GPIO_Interrupt       GPIO_57 // PD10
    #define TDC_GPIO_Fire            GPIO_Null
    #define TDC_GPIO_Start           GPIO_Null
    #define TDC_GPIO_StartEnable     GPIO_Null
    #define TDC_GPIO_Stop_1_Enable   GPIO_Null
    #define TDC_GPIO_Stop_2_Enable   GPIO_Null

    #define EEPROM_SPI               SPI_3
    #define EEPROM_GPIO_SCK          SPI_3_SCK
    #define EEPROM_GPIO_MOSI         SPI_3_MOSI
    #define EEPROM_GPIO_MISO         SPI_3_MISO
    #define EEPROM_GPIO_ChipSelect   GPIO_77 // PA15
    #define EEPROM_GPIO_PowerEnable  GPIO_81 // PD0

    #define GSM_UART                 UART_2
    #define GSM_GPIO_TX              UART_2_TX
    #define GSM_GPIO_RX              UART_2_RX
    #define GSM_GPIO_PSM_EINT        GPIO_30 // PA5
    #define GSM_GPIO_RESET           GPIO_33 // PC4
    #define GSM_GPIO_PWRKEY          GPIO_38 // PE7
    #define GSM_GPIO_PowerEnable     GPIO_40 // PE9
    #define GSM_GPIO_RI              GPIO_Null

    #define GSM_UART_DBG             UART_Null
    #define GSM_GPIO_DBG_TX          GPIO_Null
    #define GSM_GPIO_DBG_RX          GPIO_Null

    #define ACQ_GPIO_PULSE           GPIO_43 // PE12
    #define ACQ_GPIO_CAPTURE         GPIO_44 // PE13
    #define ACQ_GPIO_ModeSwitch      GPIO_45 // PE14

    #define DEBUG_GPIO_O_1           GPIO_41 // PE10
    #define DEBUG_GPIO_O_2           GPIO_42 // PE11

/**
 *  @}
 *
 *  @}
 */

// #############################################################################
// #### Public Type(s) #########################################################
// #############################################################################

// #############################################################################
// #### Public Method(s) #######################################################
// #############################################################################

// #############################################################################
// #### Public Variable(s) #####################################################
// #############################################################################

// #############################################################################
// #### File Guard #############################################################
// #############################################################################

#endif /* PLATFORM_FLOW_METER_PORT_H_ */

/**
 *  @}
 *
 *  @}
 */

// #############################################################################
// #### END OF FILE ############################################################
// #############################################################################
