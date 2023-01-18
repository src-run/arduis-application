
/*
 * This file is part of the `src-run/arduis-application` project.
 *
 * (c) Rob Frawley 2nd <rmf@src.run>
 *
 * For the full copyright and license information, please view the LICENSE.md
 * file that was distributed with this source code.
 */

#include "Temper.h"

TemperManager SystemTemper { };

void setupTemper()
{
    const unsigned long begMillis = millis();
    SystemTemper.update();
    const unsigned int  difMillis = cstrUInt(millis() - begMillis);

    const String tempsFormat { F("=== SHT4x Temperatures   : %.02f°C (%.02f°F)") };
    char         tempsBuffer [ tempsFormat.length() - 5 + 5 - 5 + 5 + 1 ];

    sprintf(
        tempsBuffer,
        tempsFormat.c_str(),
        SystemTemper.getTemperatureAsC(),
        SystemTemper.getTemperatureAsF()
    );

    Serial.println(tempsBuffer);

    const String humidFormat { F("=== SHT4x Humidity       : %.02f%% rH") };
    char         humidBuffer [ humidFormat.length() - 5 + 5 + 1 ];

    sprintf(
        humidBuffer,
        humidFormat.c_str(),
        SystemTemper.getHumidity()
    );

    Serial.println(humidBuffer);

    const String milliFormat { F("=== SHT4x Timer / Serial : %ums (%.02fs) / %u") };
    char         milliBuffer [ milliFormat.length() + 30 + 1 ];

    sprintf(
        milliBuffer,
        milliFormat.c_str(),
        difMillis,
        (float)difMillis / (float)1000,
        SystemTemper.getSerial()
    );

    Serial.println(milliBuffer);
}
