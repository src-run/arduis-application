
/*
 * This file is part of the `src-run/arduis-application` project.
 *
 * (c) Rob Frawley 2nd <rmf@src.run>
 *
 * For the full copyright and license information, please view the LICENSE.md
 * file that was distributed with this source code.
 */

#include "Switch.h"

Relay ledSwitch { LED_RELAY_PIN, false };

void setupSwitch()
{
    ledSwitch.begin();
    ledSwitch.turnOn();
}
