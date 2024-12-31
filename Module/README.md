# Module

---
# Template
## Header

```c/c++
// #############################################################################
// #### Copyright ##############################################################
// #############################################################################

/*
 * Copyright 2025 BaSSeM
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
 *  @brief Platform <Module>
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
 *  @addtogroup Platform_Module
 *
 *  @{
 */

/**
 *  @defgroup Platform_<Module_ID> <Module>
 *
 *  @note Default port is STUB if Unspecified
 *
 *  @{
 */

#ifndef <Module>_H_
#define <Module>_H_

#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */

// #############################################################################
// #### Include(s) #############################################################
// #############################################################################

#include "<Module>_Port.h"

// #############################################################################
// #### Public Macro(s) ########################################################
// #############################################################################

// #############################################################################
// #### Public Type(s) #########################################################
// #############################################################################

/**
 *  @brief <Module> Operation Status
 *
 *  @enum <Module>_Status_t
 */
typedef enum <Module>_Status
{
  <Module>_Status_Success = 0,      ///< Success
  <Module>_Status_ArgumentInvalid,  ///< Argument Invalid
  <Module>_Status_NotSupported,     ///< Not Supported
  <Module>_Status_Error,            ///< General Error
  <Module>_Status_Busy,             ///< Busy Error
  <Module>_Status_Timeout,          ///< Timeout Error
} <Module>_Status_t;

// #############################################################################
// #### Public Method(s) #######################################################
// #############################################################################

/**
 *  @brief Initialize ALL <Module>s
 *
 *  @return <Module>_Status_t
 */
<Module>_Status_t <Module>_Initialize( void );

/**
 *  @brief Cycle ALL <Module>s
 *
 *  @return <Module>_Status_t
 */
<Module>_Status_t <Module>_Cycle( void );

/**
 *  @brief DeInitialize ALL <Module>s
 *
 *  @return <Module>_Status_t
 */
<Module>_Status_t <Module>_DeInitialize( void );

// #############################################################################
// #### Public Variable(s) #####################################################
// #############################################################################

/**
 *  @brief Version
 */
extern const char <Module>_VERSION[];

// #############################################################################
// #### File Guard #############################################################
// #############################################################################

#ifdef __cplusplus
} /* extern "C" */
#endif /* __cplusplus */

#endif /* <Module>_H_ */

/**
 *  @}
 *
 *  @}
 */

// #############################################################################
// #### END OF FILE ############################################################
// #############################################################################
```

## Source

```c/c++
// #############################################################################
// #### Copyright ##############################################################
// #############################################################################

/*
 * Copyright 2025 BaSSeM
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

#include "<Module>.h"
#include "<Module>_Internal.h"

// #############################################################################
// #### Private Macro(s) #######################################################
// #############################################################################

// #############################################################################
// #### Private Type(s) ########################################################
// #############################################################################

// #############################################################################
// #### Private Method(s) Prototype ############################################
// #############################################################################

static <Module>_Status_t <Module>_Context_Initialize( void );
static <Module>_Status_t <Module>_Context_Cycle( void );
static <Module>_Status_t <Module>_Context_DeInitialize( void );

// #############################################################################
// #### Private Variable(s) ####################################################
// #############################################################################

// #############################################################################
// #### Private Method(s) ######################################################
// #############################################################################

static <Module>_Status_t <Module>_Context_Initialize( void )
{
  <Module>_Status_t <Module>_Status = <Module>_Status_Error;
  do
  {
    <Module>_Trace( "%s( void )", __FUNCTION__ );
    for ( <Module>_t <Module> = <Module>_Null; <Module> < <Module>_NUMBER_OF_INSTANCES; ++<Module> )
    {
      <Module>_Context.Instance[ <Module> ].<Module> = <Module>;
      if ( ( <Module>_Status = <Module>_Instance_Initialize( &<Module>_Context.Instance[ <Module> ] ) ) != <Module>_Status_Success )
      {
        <Module>_Warning( "<Module>_%d Initialize Failed: Status %d", <Module>, <Module>_Status );
      }
    }
    <Module>_Status = <Module>_Status_Success;
  }
  while(0);
  return <Module>_Status;
}

static <Module>_Status_t <Module>_Context_Cycle( void )
{
  <Module>_Status_t <Module>_Status = <Module>_Status_Error;
  do
  {
    <Module>_Trace( "%s( void )", __FUNCTION__ );
    for ( <Module>_t <Module> = <Module>_Null; <Module> < <Module>_NUMBER_OF_INSTANCES; ++<Module> )
    {
      <Module>_Context.Instance[ <Module> ].<Module> = <Module>;
      if ( ( <Module>_Status = <Module>_Instance_Cycle( &<Module>_Context.Instance[ <Module> ] ) ) != <Module>_Status_Success )
      {
        <Module>_Warning( "<Module>_%d Cycle Failed: Status %d", <Module>, <Module>_Status );
      }
    }
    <Module>_Status = <Module>_Status_Success;
  }
  while(0);
  return <Module>_Status;
}

static <Module>_Status_t <Module>_Context_DeInitialize( void )
{
  <Module>_Status_t <Module>_Status = <Module>_Status_Error;
  do
  {
    <Module>_Trace( "%s( void )", __FUNCTION__ );
    for ( <Module>_t <Module> = <Module>_Null; <Module> < <Module>_NUMBER_OF_INSTANCES; ++<Module> )
    {
      <Module>_Context.Instance[ <Module> ].<Module> = <Module>;
      if ( ( <Module>_Status = <Module>_Instance_DeInitialize( &<Module>_Context.Instance[ <Module> ] ) ) != <Module>_Status_Success )
      {
        <Module>_Warning( "<Module>_%d DeInitialize Failed: Status %d", <Module>, <Module>_Status );
      }
    }
    <Module>_Status = <Module>_Status_Success;
  }
  while(0);
  return <Module>_Status;
}

// #############################################################################
// #### Public Method(s) #######################################################
// #############################################################################

<Module>_Status_t <Module>_Initialize( void )
{
  <Module>_Status_t <Module>_Status = <Module>_Status_Error;
  do
  {
    <Module>_Trace( "%s( void )", __FUNCTION__ );
    <Module>_Status = <Module>_Context_Initialize( );
  }
  while(0);
  return <Module>_Status;
}

<Module>_Status_t <Module>_Cycle( void )
{
  <Module>_Status_t <Module>_Status = <Module>_Status_Error;
  do
  {
    <Module>_Trace( "%s( void )", __FUNCTION__ );
    <Module>_Status = <Module>_Context_Cycle( );
  }
  while(0);
  return <Module>_Status;
}

<Module>_Status_t <Module>_DeInitialize( void )
{
  <Module>_Status_t <Module>_Status = <Module>_Status_Error;
  do
  {
    <Module>_Trace( "%s( void )", __FUNCTION__ );
    <Module>_Status = <Module>_Context_DeInitialize( );
  }
  while(0);
  return <Module>_Status;
}

// #############################################################################
// #### Public Variable(s) #####################################################
// #############################################################################

const char <Module>_VERSION[] = "<major>.<minor>.<patch>.v<Year><Month><Day>-<Hour><Minute>";

// #############################################################################
// #### File Guard #############################################################
// #############################################################################

// #############################################################################
// #### END OF FILE ############################################################
// #############################################################################
```

## Internal
### Header
### Source
## Driver
### Header
### Folder
#### SoC/Chip
##### Header
##### Source

## Port
### Header
### Folder
#### Device
##### Header
##### Source