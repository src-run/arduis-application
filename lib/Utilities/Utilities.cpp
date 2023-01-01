
/*
 * This file is part of the `src-run/arduis-application` project.
 *
 * (c) Rob Frawley 2nd <rmf@src.run>
 *
 * For the full copyright and license information, please view the LICENSE.md
 * file that was distributed with this source code.
 */

#include "Utilities.h"

uint8_t minInt8(int16_t i) {
    return i >= 0 ? i : 0;
}

uint8_t maxInt8(int16_t i) {
    return i <= 255 ? i : 255;
}

uint8_t useInt8(int16_t i) {
    return i <= 255 ? (i >= 0 ? i : 0) : 255;
}

void setRandom16Seed(uint8_t iterations)
{
    for (uint8_t i = 0; i < random8(iterations); i++) {
        random16_set_seed(analogRead(LED_BUILTIN) * analogRead(LED_BUILTIN) * analogRead(LED_BUILTIN));
    }
}
