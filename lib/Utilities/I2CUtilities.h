
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
#include "ArduinoJson.h"

#define ST(A) #A
#define STR(A) ST(A)

DynamicJsonDocument getI2CDeviceListJson();

String getI2CDeviceListJsonText();
String getI2CFoundDesc(const I2CDeviceInfo& deviceInfo);

void addI2CDevicesMatchingAddressList(String& deviceStr, const JsonVariant& device, const I2CDeviceInfo& deviceInfo);
void addI2CDevicesMatchingAddressSets(String& deviceStr, const JsonVariant& device, const I2CDeviceInfo& deviceInfo);
void addI2CDeviceStr(String& deviceStr, const JsonVariant& device);
