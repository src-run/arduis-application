
/*
 * This file is part of the `src-run/arduis-application` project.
 *
 * (c) Rob Frawley 2nd <rmf@src.run>
 *
 * For the full copyright and license information, please view the LICENSE.md
 * file that was distributed with this source code.
 */

#include "TemperManager.h"

TemperManager::TemperManager(sht4x_precision_t preciseMode, sht4x_heater_t heatingMode, const bool runUpdate)
{
    _sensorPreciseMode = preciseMode;
    _sensorHeatingMode = heatingMode;
    _sensor = Adafruit_SHT4x();

    if (runUpdate) {
        update();
    }
}

void TemperManager::update()
{
    if (!_inited) {
        begins();
    }

    _sensor.setPrecision(_sensorPreciseMode);
    _sensor.setHeater(_sensorHeatingMode);
    _sensor.getEvent(&_humids, &_temper);
}

void TemperManager::begins()
{
    if (_inited || _sensor.begin(&Wire)) {
        return;
    }

    _inited = true;

    Serial.println(F("!!! Couldn't find i2c device \"SHT4x\" at address \"0x44\" ..."));
    while(true) { delay(1); }
}

void TemperManager::setPreciseMode(sht4x_precision_t preciseMode)
{
    _sensorPreciseMode = preciseMode;
}

void TemperManager::setHeadingMode(sht4x_heater_t heatingMode)
{
    _sensorHeatingMode = heatingMode;
}

sensors_event_t TemperManager::getTemperatureEvent()
{
    return _temper;
}

sensors_event_t TemperManager::getHumidityEvent()
{
    return _humids;
}

float TemperManager::getTemperatureAsC()
{
    return _temper.temperature;
}

float TemperManager::getTemperatureAsF()
{
    return (_temper.temperature * (float)9 / (float)5) + (float)32;
}
float TemperManager::getHumidity()
{
    return _humids.relative_humidity;
}

unsigned long TemperManager::getSerial()
{
    return _sensor.readSerial();
}
