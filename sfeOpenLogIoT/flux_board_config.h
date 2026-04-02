/*
 *---------------------------------------------------------------------------------
 *
 * Copyright (c) 2022-2024, SparkFun Electronics Inc.
 *
 * SPDX-License-Identifier: MIT
 *
 *---------------------------------------------------------------------------------
 */

// Board specific things for the application..
#pragma once

#include <cstdint>

// Simple board definitions - used by the application framework

// The on board user button/ boot button
#define FLUX_BOARD_APP_BUTTON 0

// LED Built in
#define FLUX_BOARD_APP_LED 4

// RGB LED
// #define FLUX_BOARD_APP_LED_RGB

// Version information

// Major version number
#define FLUX_APP_VERSION_MAJOR 1

// Minor version number
#define FLUX_APP_VERSION_MINOR 0

// Point version number
#define FLUX_APP_VERSION_POINT 0

// Version string description
#define FLUX_APP_VERSION_DESCRIPTOR "Version 1.0.0"

// app name/class ID string
#define FLUX_APP_CLASS_NAME_ID "SFE-OPENLOG-IOT"
