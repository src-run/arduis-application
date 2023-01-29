
/*
 * This file is part of the `src-run/arduis-application` project.
 *
 * (c) Rob Frawley 2nd <rmf@src.run>
 *
 * For the full copyright and license information, please view the LICENSE.md
 * file that was distributed with this source code.
 */

#pragma once

#include "CommonArduino.h"
#include "Config.h"
#include "I2CDeviceInfo.h"
#include "UtilitiesInline.h"
#include "DateTimeReading.h"

#define ARRAY_SIZE(A) (*(&A + 1) - A)

#define PIN_MODE_UNKNOWN      0xff
#define PIN_MODE_INPUT        INPUT
#define PIN_MODE_INPUT_PULLUP INPUT_PULLUP
#define PIN_MODE_OUTPUT       OUTPUT

extern void outI2CFoundInfo(const I2CDeviceInfo&);

String               getCompilationDate();
String               getCompilationTime();
DateTimeReading      getCompilationDateTime();

String               strPadsChar(const String value, const int padding = -1, const String useChar = " ", const StringPadDirection useSide = StringPadDirection::lft);

void setupSystem();
void setupWiring();
void writeScannedI2C();
void delayForever(bool writeSerialMessage = false);
void writeI2cDevFailureAndDelayForever(String device, byte address = 0);
