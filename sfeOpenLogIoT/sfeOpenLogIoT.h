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
#pragma once

#include <Flux.h>

#include <Flux/flxApplication.h>

/////////////////////////////////////////////////////////////////////////
// Define our application class for the data logger
/////////////////////////////////////////////////////////////////////////
class sfeOpenLogIoT : public flxApplication
{
  public:
    //---------------------------------------------------------------------------
    // Constructor
    //

    sfeOpenLogIoT();

    //---------------------------------------------------------------------------
    // onSetup()
    //
    // Called by the system before devices are loaded, and system initialized
    bool onSetup();

    //---------------------------------------------------------------------------
    // onDeviceLoad()
    //
    // Called by the system, right after device auto-load, but before system restore
    // Allows the app to load other devices.
    void onDeviceLoad(void);

    void onRestore(void);

    void resetDevice(void);

  public:
    //---------------------------------------------------------------------------

    // onInit()
    //
    // Called before anything is started
    void onInit();

    // onStart()
    //
    // Called after the system is loaded, restored and initialized
    bool onStart();

    // bool loop();
};
