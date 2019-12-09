
/*
 * This file is part of the `src-run/arduis-application` project.
 *
 * (c) Rob Frawley 2nd <rmf@src.run>
 *
 * For the full copyright and license information, please view the LICENSE.md
 * file that was distributed with this source code.
 */

#include "Selector.h"

TWIST selector;

void selectorInitialize(int colorR, int colorG, int colorB, bool fastClock) {
    Serial.print("[SLT] Initializing DEV-15083 switcher device on I2C bus ... ");

    if(!selector.begin()) {
        Serial.println("[FAIL] (halting due to missing device)");
        while(1);
    }

    Serial.println("[OKAY] (found device at 0x3F I2C address)");

    if (fastClock) {
        Wire.setClock(400000);
        Serial.println("[SLT] Configuring I2C wire bus ... [OKAY] (speed set to 400kHz)");
    }

    selector.setColor(colorR, colorG, colorB);
    Serial.print("[SLT] Configuring colors ... [OKAY] (set RGB to ");
    Serial.print(colorR, DEC);
    Serial.print(',');
    Serial.print(colorG, DEC);
    Serial.print(',');
    Serial.print(colorB, DEC);
    Serial.println(')');

    selector.setLimit(40);
    selector.connectBlue(20);
    selector.connectRed(-20);
}
