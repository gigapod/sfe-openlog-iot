/*
 *---------------------------------------------------------------------------------
 *
 * Copyright (c) 2022-2026, SparkFun Electronics Inc.
 *
 * SPDX-License-Identifier: MIT
 *
 *---------------------------------------------------------------------------------
 */

/*
 * SparkFun OpenLog IoT
 *
 */

#include "sfeOpenLogIoT.h"

//---------------------------------------------------------------------------
// Constructor
//---------------------------------------------------------------------------
//

sfeOpenLogIoT::sfeOpenLogIoT()
{
}

//---------------------------------------------------------------------------
// Flux flxApplication LifeCycle Method
//---------------------------------------------------------------------------
// onSetup()
//
// Called by the system before devices are loaded, and system initialized
bool sfeOpenLogIoT::onSetup()
{
    setName("SparkFun OpenLog IoT");
    setDescription("(c) 2023-2026 SparkFun Electronics");

    flxLog_I("user - onSetup()");
    return true;
}

//---------------------------------------------------------------------------
// Flux flxApplication LifeCycle Method
//---------------------------------------------------------------------------
//---------------------------------------------------------------------
// onDeviceLoad()
//
// Called after qwiic/i2c auto-load, but before system state restore

void sfeOpenLogIoT::onDeviceLoad()
{

    flxLog_I("user - onDeviceLoad");
}
//---------------------------------------------------------------------
// onRestore()
//
// Called just before settings are restored on startup.

void sfeOpenLogIoT::onRestore(void)
{

    flxLog_I("user - onRestore");
    //     // At this point, we know enough about the device to set details about it.
    //     char prefix[5] = "0000";
    //     // (void)dlModeCheckPrefix(_modeFlags, prefix);
    //     setAppClassID(kDLAppClassNameID, prefix); // internal name string for this app type
    // }

    //---------------------------------------------------------------------------
    // onInit()
    //
    // Called before the system/framework is up
}
void sfeOpenLogIoT::onInit(void)
{
    flxLog_I("user - onInit");
}

//---------------------------------------------------------------------------
// Flux flxApplication LifeCycle Method
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
// onStart()
//
// Called after the system is loaded, restored and initialized
bool sfeOpenLogIoT::onStart()
{
    flxLog_I("user - onStart");

    return true;
}
