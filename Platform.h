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
 * @file
 *
 * @brief Platform
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
 *  @defgroup Platform Platform
 *
 *  @{
 */

#ifndef PLATFORM_H_
    #define PLATFORM_H_

    #ifdef __cplusplus
extern "C"
{
    #endif /* __cplusplus */

    // #############################################################################
    // #### Include(s) #############################################################
    // #############################################################################

    /**
     *  @defgroup Platform_Port Port
     *
     *  @{
     */

    #include "Platform_Port.h"

    /**
     *  @}
     */

    /**
     *  @defgroup Platform_Library Library
     *
     *  @{
     */

    #include "Library/BUFFER/BUFFER.h"
    #include "Library/LIST/LIST.h"
    #include "Library/UTIL/UTIL.h"

    /**
     *  @}
     */

    /**
     *  @defgroup Platform_Kernel Kernel
     *
     *  @{
     */

    #include "Kernel/Kernel.h"

    /**
     *  @}
     */

    /**
     *  @defgroup Platform_Module Module
     *
     *  @{
     */

    #include "Module/ADC/ADC.h"
    #include "Module/DMA/DMA.h"
    #include "Module/EEPROM/EEPROM.h"
    #include "Module/FLASH/FLASH.h"
    #include "Module/GPIO/GPIO.h"
    // #include "Module/GPRS/GPRS.h" // TODO
    #include "Module/GSM/GSM.h"
    #include "Module/LCD/LCD.h"
    // #include "Module/LORA/LORA.h" // TODO
    #include "Module/PWR/PWR.h"
    #include "Module/RAM/RAM.h"
    #include "Module/RTC/RTC.h"
    #include "Module/SPI/SPI.h"
    // #include "Module/TCH/TCH.h" // TODO
    #include "Module/TDC/TDC.h"
    #include "Module/TMR/TMR.h"
    #include "Module/UART/UART.h"
    #include "Module/USB/USB.h"

    /**
     *  @}
     */

    /**
     *  @defgroup Platform_Service Service
     *
     *  @{
     */

    #include "Service/CLI/CLI.h"
    #include "Service/LOG/LOG.h"
    // #include "Service/MEM/MEM.h" // TODO
    // #include "Service/NET/NET.h" // TODO
    #include "Service/TIM/TIM.h"

    /**
     *  @}
     */

    // #############################################################################
    // #### Public Macro(s) ########################################################
    // #############################################################################

    // #############################################################################
    // #### Public Type(s) #########################################################
    // #############################################################################

    /**
     *  @brief Platform Operation Status
     *
     *  @enum PLATFORM_Status_t
     */
    typedef enum PLATFORM_Status
    {
        PLATFORM_Status_Success = 0,     ///< Success
        PLATFORM_Status_ArgumentInvalid, ///< Argument Invalid
        PLATFORM_Status_NotSupported,    ///< Not Supported
        PLATFORM_Status_Error,           ///< General Error
        PLATFORM_Status_Busy,            ///< Busy
        PLATFORM_Status_Timeout,         ///< Timeout
    } PLATFORM_Status_t;

    // #############################################################################
    // #### Public Method(s) #######################################################
    // #############################################################################

    /**
     *  @brief Initialize platform kernel/modules/services
     *
     *  @note MUST BE called before using any platform API
     *
     *  @return PLATFORM_Status_t
     */
    PLATFORM_Status_t PLATFORM_Initiatize( void );

    /**
     *  @brief Cycle platform kernel/modules/services
     *
     *  @return PLATFORM_Status_t
     */
    PLATFORM_Status_t PLATFORM_Cycle( void );

    /**
     *  @brief DeInitialize platform kernel/modules/services
     *
     *  @return PLATFORM_Status_t
     */
    PLATFORM_Status_t PLATFORM_DeInitiatize( void );

    // #############################################################################
    // #### Public Variable(s) #####################################################
    // #############################################################################

    /**
     *  @brief Version
     */
    extern const char PLATFORM_VERSION[];

    // #############################################################################
    // #### File Guard #############################################################
    // #############################################################################

    #ifdef __cplusplus
} /* extern "C" */
    #endif /* __cplusplus */

#endif /* PLATFORM_H_ */

/**
 *  @}
 */

// #############################################################################
// #### END OF FILE ############################################################
// #############################################################################
