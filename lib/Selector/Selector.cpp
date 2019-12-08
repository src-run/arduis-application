
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
    if(selector.begin() == false) {
        Serial.println("Twist does not appear to be connected. Please check wiring. Freezing...");
        while(1);
    }

    if (fastClock) {
        Wire.setClock(400000);
    }

    selector.setColor(colorR, colorG, colorB);
    selector.setLimit(40);
}
