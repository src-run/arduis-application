
/*
 * This file is part of the `src-run/arduis-application` project.
 *
 * (c) Rob Frawley 2nd <rmf@src.run>
 *
 * For the full copyright and license information, please view the LICENSE.md
 * file that was distributed with this source code.
 */

#include "Togglers.h"

EasyButton toggler(BTN_TOGLR_PIN);

void handleTogglerModeSelectPress() {
    Serial.println("[BUT] Caught quick button press (for more than 20 milliseconds) ... changing dial input mode!");
}

void handleTogglerTurnOffLedPress() {
    Serial.println("[BUT] Caught extended button press (for more than 2000 milliseconds) ... turning off LEDs!");
}

void initializeToggler(void) {
    toggler.begin();
    toggler.onSequence(BTN_TOGLR_MODE_SELECT_PRESSES, BTN_TOGLR_MODE_SELECT_TIMEOUT, handleTogglerModeSelectPress);
    toggler.onPressedFor(BTN_TOGLR_TURNOFF_LED_MS, handleTogglerTurnOffLedPress);
}
