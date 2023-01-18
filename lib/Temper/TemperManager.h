
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
#include "CommonAdafruitSHT4x.h"
#include "Config.h"
#include "Utilities.h"

class TemperManager {
    private:
        bool              _inited  { false };
        const byte        _address { 0x44 };

        Adafruit_SHT4x    _sensor;
        sht4x_precision_t _sensorPreciseMode;
        sht4x_heater_t    _sensorHeatingMode;

        sensors_event_t   _temper;
        sensors_event_t   _humids;

    public:
        TemperManager(const bool runUpdate = false) : TemperManager(SHT4X_MED_PRECISION, SHT4X_NO_HEATER, runUpdate) {};
        TemperManager(sht4x_precision_t preciseMode, sht4x_heater_t heatingMode, const bool runUpdate = false);

        void begins();
        void update();

        void setPreciseMode(sht4x_precision_t preciseMode);
        void setHeadingMode(sht4x_heater_t    heatingMode);

        sensors_event_t getTemperatureEvent();
        sensors_event_t getHumidityEvent();
        float getTemperatureAsC();
        float getTemperatureAsF();
        float getHumidity();

        unsigned int getSerialNumber();

        sensor_t& getTemperatureSensor();
        sensor_t& getHumiditySensor();

        void writeDebugInfo();

    protected:
        void writeDebugInfoTemps();
        void writeDebugInfoHumid();
};
