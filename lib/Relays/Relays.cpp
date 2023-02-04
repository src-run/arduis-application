
/*
 * This file is part of the `src-run/arduis-application` project.
 *
 * (c) Rob Frawley 2nd <rmf@src.run>
 *
 * For the full copyright and license information, please view the LICENSE.md
 * file that was distributed with this source code.
 */

#include "Relays.h"

Relay pwrRelay { LED_RELAY1_PIN, false };
Relay ledRelay { LED_RELAY2_PIN, false };

void setupRelays()
{
    pwrRelay.begin();
    ledRelay.begin();

    pwrRelay.turnOn();
    FastLED.delay(500);
    ledRelay.turnOn();
}
