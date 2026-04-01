
/*
 *---------------------------------------------------------------------------------
 *
 * Copyright (c) 2022-2026, SparkFun Electronics Inc.
 *
 * SPDX-License-Identifier: MIT
 *
 *---------------------------------------------------------------------------------
 */

// Base class for application level / controlled LEDs. This builds out the core
// functionality, defines a base class as well as command/task queue.
//
// Since LED updates can occur rapidly, a FreeROTS queue and task are used to manage
// the posted commands/requests. This also allows event compression.
//
#pragma once

//---------------------------------------------------------------
class flxAppLEDCore
{
  public:
    flxAppLEDCore();

    // TODO
    // Could maybe do this in a sub-class, but I'm lazy, and will need
    // color in the command queue struct for the RGB LED. So here is our colors section

    // Color type
    typedef uint32_t LEDColor_t;

    // colors
    static constexpr LEDColor_t Black = 0x000000;
    static constexpr LEDColor_t Blue = 0x0000FF;
    static constexpr LEDColor_t Green = 0x008000;
    static constexpr LEDColor_t Yellow = 0xFFFF00;
    static constexpr LEDColor_t Red = 0xFF0000;
    static constexpr LEDColor_t Gray = 0x808080;
    static constexpr LEDColor_t LightGray = 0x778899;
    static constexpr LEDColor_t Orange = 0xFFA500;
    static constexpr LEDColor_t White = 0xFFFFFF;
    static constexpr LEDColor_t Purple = 0x80008;

    // Some Handy Flash levels...
    static constexpr uint16_t const kLEDFlashSlow = 600;
    static constexpr uint16_t const kLEDFlashMedium = 200;
    static constexpr uint16_t const kLEDFlashFast = 80;

    // our methods

    bool initialize(uint8_t pin);
    void on(LEDColor_t color);
    void off(void);
    void blink(uint32_t);
    void blink(LEDColor_t, uint32_t);
    void stop(bool off = true);
    void flash(LEDColor_t color);
    void refresh(void);

    void setDisabled(bool bDisable);

    bool disabled(void)
    {
        return _disabled;
    }

  protected:
    typedef struct
    {
        LEDColor_t color;
        uint32_t ticks;
    } ledState_t;

    // Command Type
    typedef enum
    {
        kCmdNone = 0,
        kCmdOn = (1 << 0),
        kCmdOff = (1 << 1),
        kCmdFlash = (1 << 2),
        kCmdBlink = (1 << 3),
        kCmdReset = (1 << 4),
        kCmdUpdate = (1 << 5)
    } cmdType_t;

    // Command struct
    typedef struct
    {
        cmdType_t type;
        ledState_t data;
        flxAppLEDCore *led;
    } cmdStruct_t;
    // methods the sub-class  implements
    virtual void onTimer(void) = 0;
    virtual void onUpdate(ledState_t &) = 0;
    virtual bool onInitialize(uint8_t) = 0;

    // blink state
    bool _blinkOn;

  private:
    void onEvent(cmdStruct_t &theCommand);
    void update(void);
    void popState(void);
    bool pushState(ledState_t &);
    void queueCommand(cmdType_t command, LEDColor_t color = 0, uint32_t ticks = 0);

    // a stack that is used to manage the state of the LED.
    static constexpr const uint16_t kStackSize = 10;
    ledState_t _ledStack[kStackSize];

    int _current;
    bool _isInitialized;

    bool _disabled;

    // FreeRTOS timer
    xTimerHandle _hTimer;
    static constexpr const uint16_t kTimerPeriod = 100;

    // static methods that are used to manage the command queue;
    static void rtosTimerCallback(xTimerHandle pxTimer);
    static void rtosTaskProcessing(void *parameter);
    static bool rtosSetup(void);
};
