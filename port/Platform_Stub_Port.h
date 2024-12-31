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
 *  @brief Platform Stub PORT
 *
 *  @note DEFAULT Platform PORT
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
 *  @defgroup Stub_Port Stub
 *
 *  @{
 */

#ifndef PLATFORM_STUB_PORT_H_
    #define PLATFORM_STUB_PORT_H_

    #ifndef PLATFORM_STUB
        #define PLATFORM_STUB
    #endif

    #warning "Platform Stub Port In Use"

// #############################################################################
// #### Include(s) #############################################################
// #############################################################################

// #############################################################################
// #### Public Macro(s) ########################################################
// #############################################################################

/**
 *  @defgroup Stub_Port_Kernel Kernel
 *
 *  @{
 */

/**
 *  @brief Activated Kernel Variant
 *
 *  @{
 */

    #define KERNEL_STUB

/**
 *  @}
 *
 *  @}
 */

/**
 *  @defgroup Stub_Port_Module Module
 *
 *  @{
 */

/**
 *  @brief Activated Module PORT
 *
 *  @{
 */

    #define ADC_STUB
    #define EEPROM_STUB
    #define FLASH_STUB
    #define GPIO_STUB
    #define GPRS_STUB
    #define GSM_STUB
    #define LCD_STUB
    #define LORA_STUB
    #define PWR_STUB
    #define RAM_STUB
    #define RTC_STUB
    #define SPI_STUB
    #define TCH_STUB
    #define TDC_STUB
    #define TMR_STUB
    #define UART_STUB
    #define USB_STUB

/**
 *  @}
 *
 *  @}
 */

/**
 *  @defgroup Stub_Port_Service Service
 *
 *  @{
 */

/**
 *  @brief Activated Service PORT
 *
 *  @{
 */

    #define CLI_STUB
    #define LOG_STUB
    #define MEM_STUB
    #define NET_STUB
    #define TIM_STUB
    #define UTIL_STUB

/**
 *  @}
 *
 *  @}
 */

/**
 *  @defgroup Stub_Port_Mapping Mapping
 *
 *  @{
 */

/**
 *  @brief Peripheral/Pin Mapping
 *
 *  @{
 */

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

#endif /* PLATFORM_STUB_PORT_H_ */

/**
 *  @}
 *  @}
 */

// #############################################################################
// #### END OF FILE ############################################################
// #############################################################################
