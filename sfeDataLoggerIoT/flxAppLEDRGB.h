
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

// quiet a damn pragma message - silly
#define FASTLED_INTERNAL
#include <FastLED.h>

#include <flxAppLEDCore.h>
//---------------------------------------------------------------
class flxAppLEDRGB : public flxAppLEDBase
{
  protected:
    static constexpr const uint8_t kLEDDefaultBrightness = 20;

    void onTimer(void)
    {
        _theLED = _blinkOn ? flxAppLEDBase::Black : currentState(void).color;
        FastLED.show();

        _blinkOn = !_blinkOn;
    }
    void onUpdate(ledState_t &theState)
    {

        _theLED = currentState(void).color;
        FastLED.show();
    }
    bool onInitialize(uint8_t thePin)
    {
        // Begin setup - turn on board LED during setup.
        pinMode(thePin, OUTPUT);

        FastLED.addLeds<WS2812, thePin, GRB>(&_theLED, 1).setCorrection(TypicalLEDStrip);
        FastLED.setBrightness(kLEDDefaultBrightness);

        return true;
    }

  private:
    CRGB _theLED;
};