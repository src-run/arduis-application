
/*
 * This file is part of the `src-run/arduis-application` project.
 *
 * (c) Rob Frawley 2nd <rmf@src.run>
 *
 * For the full copyright and license information, please view the LICENSE.md
 * file that was distributed with this source code.
 */

#include "Luminosity.h"

Adafruit_TSL2591 tsl = Adafruit_TSL2591(2591);

void initializeLuminosityLocation(void) {
    Serial.print("[TSL] Initializing TSL2591 luminosity device on I2C bus ... ");

    if (!tsl.begin()) {
        Serial.println("[FAIL] (halting due to missing device)");
        while (1);
    }

    Serial.println("[OKAY] (found device at 0x29 and 0x28 I2C addresses)");
}

void initializeLuminosityCfgSetup(void) {
    // gain can be set from low (1x) to medium (25x) to high (428x) to adapt to brighter/dimmer light situations
    tsl.setGain(TSL2591_GAIN_MED);
    tsl.enableAutoRange(true);

    // long integration time provides better light sensing, especially in very low light situations
    // can be assigned values in increments of 100 from 100 to 600 milliseconds
    tsl.setTiming(TSL2591_INTEGRATIONTIME_400MS);
}

void initializeLuminosity(void) {
    initializeLuminosityLocation();
    initializeLuminosityCfgSetup();
}

LuminosityReading luminosityResolve(void) {
    struct LuminosityReading reading;
    uint32_t rawData = tsl.getFullLuminosity();

    reading.dateTime = rtc.now();
    reading.rawData = rawData;
    reading.infraRed = rawData >> 16;
    reading.fullSpectrum = rawData & 0xFFFF;
    reading.visible = reading.fullSpectrum - reading.infraRed;
    reading.lux = tsl.calculateLux(reading.fullSpectrum, reading.infraRed);

    return reading;
}

void luminosityDebugWriteSerialReadingValues(void) {
  struct LuminosityReading reading = LuminosityReading();

  Serial.print(F("[ ")); Serial.print(reading.dateTime.timestamp()); Serial.print(F(" ] "));
  Serial.print(F("IR: ")); Serial.print(reading.infraRed);  Serial.print(F("  "));
  Serial.print(F("Full: ")); Serial.print(reading.infraRed); Serial.print(F("  "));
  Serial.print(F("Visible: ")); Serial.print(reading.visible); Serial.print(F("  "));
  Serial.print(F("Lux: ")); Serial.println(reading.lux, 6);
}

void luminosityDebugWriteSerialSensorDetails(void) {
    sensor_t sensor;
    tsl2591Gain_t gain;

    tsl.getSensor(&sensor);

    Serial.println(F("------------------------------------"));
    Serial.print  (F("Sensor:       ")); Serial.println(sensor.name);
    Serial.print  (F("Driver Ver:   ")); Serial.println(sensor.version);
    Serial.print  (F("Unique ID:    ")); Serial.println(sensor.sensor_id);
    Serial.print  (F("Max Value:    ")); Serial.print(sensor.max_value); Serial.println(F(" lux"));
    Serial.print  (F("Min Value:    ")); Serial.print(sensor.min_value); Serial.println(F(" lux"));
    Serial.print  (F("Resolution:   ")); Serial.print(sensor.resolution, 4); Serial.println(F(" lux"));
    Serial.print  (F("Gain:         "));

    switch(gain = tsl.getGain()) {
        case TSL2591_GAIN_LOW:
            Serial.println(F("1x (Low)"));
            break;
        case TSL2591_GAIN_MED:
            Serial.println(F("25x (Medium)"));
            break;
        case TSL2591_GAIN_HIGH:
            Serial.println(F("428x (High)"));
            break;
        case TSL2591_GAIN_MAX:
            Serial.println(F("9876x (Max)"));
            break;
    }

    Serial.print(F("Timing:       "));
    Serial.print((tsl.getTiming() + 1) * 100, DEC);
    Serial.println(F(" ms"));
    Serial.println(F("------------------------------------"));
    Serial.println(F(""));

    delay(500);
}