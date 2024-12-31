# Service

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
 *  @brief Platform <Service>
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
 *  @addtogroup Platform_Service
 *
 *  @{
 */

/**
 *  @defgroup Platform_<Service_ID> <Service>
 *
 *  @note Default port is STUB if Unspecified
 *
 *  @{
 */

#ifndef <Service>_H_
#define <Service>_H_

#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */

// #############################################################################
// #### Include(s) #############################################################
// #############################################################################

#include "<Service>_Port.h"

// #############################################################################
// #### Public Macro(s) ########################################################
// #############################################################################

// #############################################################################
// #### Public Type(s) #########################################################
// #############################################################################

/**
 *  @brief <Service> Operation Status
 *
 *  @enum <Service>_Status_t
 */
typedef enum <Service>_Status
{
  <Service>_Status_Success = 0,      ///< Success
  <Service>_Status_ArgumentInvalid,  ///< Argument Invalid
  <Service>_Status_NotSupported,     ///< Not Supported
  <Service>_Status_Error,            ///< General Error
  <Service>_Status_Busy,             ///< Busy Error
  <Service>_Status_Timeout,          ///< Timeout Error
} <Service>_Status_t;

// #############################################################################
// #### Public Method(s) #######################################################
// #############################################################################

/**
 *  @brief Initialize ALL <Service>s
 *
 *  @return <Service>_Status_t
 */
<Service>_Status_t <Service>_Initialize( void );

/**
 *  @brief Cycle ALL <Service>s
 *
 *  @return <Service>_Status_t
 */
<Service>_Status_t <Service>_Cycle( void );

/**
 *  @brief DeInitialize ALL <Service>s
 *
 *  @return <Service>_Status_t
 */
<Service>_Status_t <Service>_DeInitialize( void );

// #############################################################################
// #### Public Variable(s) #####################################################
// #############################################################################

/**
 *  @brief Version
 */
extern const char <Service>_VERSION[];

// #############################################################################
// #### File Guard #############################################################
// #############################################################################

#ifdef __cplusplus
} /* extern "C" */
#endif /* __cplusplus */

#endif /* <Service>_H_ */

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

#include "<Service>.h"
#include "<Service>_Internal.h"

// #############################################################################
// #### Private Macro(s) #######################################################
// #############################################################################

// #############################################################################
// #### Private Type(s) ########################################################
// #############################################################################

// #############################################################################
// #### Private Method(s) Prototype ############################################
// #############################################################################

static <Service>_Status_t <Service>_Context_Initialize( void );
static <Service>_Status_t <Service>_Context_Cycle( void );
static <Service>_Status_t <Service>_Context_DeInitialize( void );

// #############################################################################
// #### Private Variable(s) ####################################################
// #############################################################################

// #############################################################################
// #### Private Method(s) ######################################################
// #############################################################################

static <Service>_Status_t <Service>_Context_Initialize( void )
{
  <Service>_Status_t <Service>_Status = <Service>_Status_Error;
  do
  {
    <Service>_Trace( "%s( void )", __FUNCTION__ );
    for ( <Service>_t <Service> = <Service>_Null; <Service> < <Service>_NUMBER_OF_INSTANCES; ++<Service> )
    {
      <Service>_Context.Instance[ <Service> ].<Service> = <Service>;
      if ( ( <Service>_Status = <Service>_Instance_Initialize( &<Service>_Context.Instance[ <Service> ] ) ) != <Service>_Status_Success )
      {
        <Service>_Warning( "<Service>_%d Initialize Failed: Status %d", <Service>, <Service>_Status );
      }
    }
    <Service>_Status = <Service>_Status_Success;
  }
  while(0);
  return <Service>_Status;
}

static <Service>_Status_t <Service>_Context_Cycle( void )
{
  <Service>_Status_t <Service>_Status = <Service>_Status_Error;
  do
  {
    <Service>_Trace( "%s( void )", __FUNCTION__ );
    for ( <Service>_t <Service> = <Service>_Null; <Service> < <Service>_NUMBER_OF_INSTANCES; ++<Service> )
    {
      <Service>_Context.Instance[ <Service> ].<Service> = <Service>;
      if ( ( <Service>_Status = <Service>_Instance_Cycle( &<Service>_Context.Instance[ <Service> ] ) ) != <Service>_Status_Success )
      {
        <Service>_Warning( "<Service>_%d Cycle Failed: Status %d", <Service>, <Service>_Status );
      }
    }
    <Service>_Status = <Service>_Status_Success;
  }
  while(0);
  return <Service>_Status;
}

static <Service>_Status_t <Service>_Context_DeInitialize( void )
{
  <Service>_Status_t <Service>_Status = <Service>_Status_Error;
  do
  {
    <Service>_Trace( "%s( void )", __FUNCTION__ );
    for ( <Service>_t <Service> = <Service>_Null; <Service> < <Service>_NUMBER_OF_INSTANCES; ++<Service> )
    {
      <Service>_Context.Instance[ <Service> ].<Service> = <Service>;
      if ( ( <Service>_Status = <Service>_Instance_DeInitialize( &<Service>_Context.Instance[ <Service> ] ) ) != <Service>_Status_Success )
      {
        <Service>_Warning( "<Service>_%d DeInitialize Failed: Status %d", <Service>, <Service>_Status );
      }
    }
    <Service>_Status = <Service>_Status_Success;
  }
  while(0);
  return <Service>_Status;
}

// #############################################################################
// #### Public Method(s) #######################################################
// #############################################################################

<Service>_Status_t <Service>_Initialize( void )
{
  <Service>_Status_t <Service>_Status = <Service>_Status_Error;
  do
  {
    <Service>_Trace( "%s( void )", __FUNCTION__ );
    <Service>_Status = <Service>_Context_Initialize( );
  }
  while(0);
  return <Service>_Status;
}

<Service>_Status_t <Service>_Cycle( void )
{
  <Service>_Status_t <Service>_Status = <Service>_Status_Error;
  do
  {
    <Service>_Trace( "%s( void )", __FUNCTION__ );
    <Service>_Status = <Service>_Context_Cycle( );
  }
  while(0);
  return <Service>_Status;
}

<Service>_Status_t <Service>_DeInitialize( void )
{
  <Service>_Status_t <Service>_Status = <Service>_Status_Error;
  do
  {
    <Service>_Trace( "%s( void )", __FUNCTION__ );
    <Service>_Status = <Service>_Context_DeInitialize( );
  }
  while(0);
  return <Service>_Status;
}

// #############################################################################
// #### Public Variable(s) #####################################################
// #############################################################################

const char <Service>_VERSION[] = "<major>.<minor>.<patch>.v<Year><Month><Day>-<Hour><Minute>";

// #############################################################################
// #### File Guard #############################################################
// #############################################################################

// #############################################################################
// #### END OF FILE ############################################################
// #############################################################################
```

---
## Internal
### Header
### Source

---
## Port
### Header
### Folder
#### Device
##### Header
##### Source