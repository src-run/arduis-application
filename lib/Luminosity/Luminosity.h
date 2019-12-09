
/*
 * This file is part of the `src-run/arduis-application` project.
 *
 * (c) Rob Frawley 2nd <rmf@src.run>
 *
 * For the full copyright and license information, please view the LICENSE.md
 * file that was distributed with this source code.
 */

#ifndef _ARDUIS_HR_LUMINOSITY
#define _ARDUIS_HR_LUMINOSITY

#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_TSL2591.h>

#include "DateTime.h"

extern Adafruit_TSL2591 tsl;

struct LuminosityReading {
    DateTime dateTime;
    uint32_t rawData;
    uint16_t infraRed;
    uint16_t fullSpectrum;
    uint16_t visible;
    float    lux;
};

void initializeLuminosityLocation(void);
void initializeLuminosityCfgSetup(void);
void initializeLuminosity(void);
LuminosityReading luminosityResolve(void);
void luminosityDebugWriteSerialReadingValues(void);
void luminosityDebugWriteSerialSensorDetails(void);

#endif
