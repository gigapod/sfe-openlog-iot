
/*
 *---------------------------------------------------------------------------------
 *
 * Copyright (c) 2022-2024, SparkFun Electronics Inc.
 *
 * SPDX-License-Identifier: MIT
 *
 *---------------------------------------------------------------------------------
 */

// LED Display for the datalogger - led display in a task
#pragma once

#include <flxAppLEDCore.h>
//---------------------------------------------------------------
class flxAppLED : public flxAppLEDBase
{
  protected:
    void onTimer(void)
    {
        // toggle blink
        _blinkOn = !_blinkOn;

        digitalWrite(_thePin, _blinkOn ? HIGH : LOW);
    }

    void onUpdate(ledState_t &theState)
    {
        // black means off - everything else is on!
        digitalWrite(_thePin, currentState().color == flxAppLEDBase::Black ? LOW : HIGH);
    }

    bool onInitialize(uint8_t thePin)
    {
        // Begin setup - turn on board LED during setup.
        pinMode(thePin, OUTPUT);
        _thePin = thePin;

        return true;
    }

  private:
    uint8_t _thePin;
};