
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

extern Adafruit_TSL2591 tsl;

void luminosityDisplaySensorDetails(void);
void luminosityConfigureSensor(void);
void luminosityInitialize(void);

#endif
