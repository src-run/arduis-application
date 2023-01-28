
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
    if (!_inited && !_sensor.begin(&SYS_WIRE_OBJECT)) {
        writeI2cDevFailureAndDelayForever("SHT45", _address);
    }

    _inited = true;

    writeDebugInfo();
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

unsigned int TemperManager::getSerialNumber()
{
    return _sensor.readSerial();
}

sensor_t& TemperManager::getTemperatureSensor()
{
    static sensor_t sensor;

    _sensor.getTemperatureSensor()->getSensor(&sensor);

    return sensor;
}

sensor_t& TemperManager::getHumiditySensor()
{
    static sensor_t sensor;

    _sensor.getHumiditySensor()->getSensor(&sensor);

    return sensor;
}

void TemperManager::writeDebugInfo()
{
    writeDebugInfoTemps();
    writeDebugInfoHumid();
}

void TemperManager::writeDebugInfoTemps()
{
    const String sensorTempsDevName { getTemperatureSensor().name };
    const long   sensorTempsDevVers { getTemperatureSensor().version };
    const long   sensorTempsDevIden { getTemperatureSensor().sensor_id };

    const String devNameTempsFormat { F("=== SHT45 - Name     (T) : %s") };
    char         devNameTempsBuffer [ devNameTempsFormat.length() + sensorTempsDevName.length() - 2 + 1 ];

    sprintf(
        devNameTempsBuffer,
        devNameTempsFormat.c_str(),
        sensorTempsDevName.c_str()
    );

    Serial.println(devNameTempsBuffer);

    const String devVersTempsFormat { F("=== SHT45 - Firmware (T) : %d") };
    char         devVersTempsBuffer [ devVersTempsFormat.length() + String(sensorTempsDevVers).length() - 2 + 1 ];

    sprintf(
        devVersTempsBuffer,
        devVersTempsFormat.c_str(),
        sensorTempsDevVers
    );

    Serial.println(devVersTempsBuffer);

    const String devIdenTempsFormat { F("=== SHT45 - DeviceID (T) : %d") };
    char         devIdenTempsBuffer [ devIdenTempsFormat.length() + String(sensorTempsDevIden).length() - 2 + 1 ];

    sprintf(
        devIdenTempsBuffer,
        devIdenTempsFormat.c_str(),
        sensorTempsDevIden
    );

    Serial.println(devIdenTempsBuffer);
}


void TemperManager::writeDebugInfoHumid()
{
    const String sensorHumidDevName { getHumiditySensor().name };
    const long   sensorHumidDevVers { getHumiditySensor().version };
    const long   sensorHumidDevIden { getHumiditySensor().sensor_id };

    const String devNameHumidFormat { F("=== SHT45 - Name     (H) : %s") };
    char         devNameHumidBuffer [ devNameHumidFormat.length() + sensorHumidDevName.length() - 2 + 1 ];

    sprintf(
        devNameHumidBuffer,
        devNameHumidFormat.c_str(),
        sensorHumidDevName.c_str()
    );

    Serial.println(devNameHumidBuffer);

    const String devVersHumidFormat { F("=== SHT45 - Firmware (H) : %d") };
    char         devVersHumidBuffer [ devVersHumidFormat.length() + String((long)sensorHumidDevVers).length() - 2 + 1 ];

    sprintf(
        devVersHumidBuffer,
        devVersHumidFormat.c_str(),
        sensorHumidDevVers
    );

    Serial.println(devVersHumidBuffer);

    const String devIdenHumidFormat { F("=== SHT45 - DeviceID (H) : %d") };
    char         devIdenHumidBuffer [ devIdenHumidFormat.length() + String(sensorHumidDevIden).length() - 2 + 1 ];

    sprintf(
        devIdenHumidBuffer,
        devIdenHumidFormat.c_str(),
        sensorHumidDevIden
    );

    Serial.println(devIdenHumidBuffer);
}
