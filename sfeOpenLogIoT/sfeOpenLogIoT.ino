/*
 *---------------------------------------------------------------------------------
 *
 * Copyright (c) 2022-2024, SparkFun Electronics Inc.
 *
 * SPDX-License-Identifier: MIT
 *
 *---------------------------------------------------------------------------------
 */

/*
 * Firmware for the OpenLog IoT - Arduino Entry
 *
 */

// Flux framework
#include "sfeOpenLogIoT.h"

// Our data logger application
sfeOpenLogIoT theOpenLogIoT;

//---------------------------------------------------------------------
// Arduino Setup
//
void setup()
{

    // Start up the framework
    flux.start();
}

//---------------------------------------------------------------------
// Arduino loop -
void loop()
{

    ///////////////////////////////////////////////////////////////////
    // Flux
    //
    // Just call the Flux framework loop() method. Flux will manage
    // the dispatch of processing to the components that were added
    // to the system during setup.
    if (flux.loop()) // will return true if an action did something
        theOpenLogIoT.onSystemActivityLow();

    delay(1);
}
