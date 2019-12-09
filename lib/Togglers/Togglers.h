
/*
 * This file is part of the `src-run/arduis-application` project.
 *
 * (c) Rob Frawley 2nd <rmf@src.run>
 *
 * For the full copyright and license information, please view the LICENSE.md
 * file that was distributed with this source code.
 */

#ifndef _ARDUIS_HR_TOGGLERS
#define _ARDUIS_HR_TOGGLERS

#include <Arduino.h>
#include <EasyButton.h>

#ifndef BTN_TOGLR_PIN
    #define BTN_TOGLR_PIN A0
#endif

#ifndef BTN_TOGLR_MODE_SELECT_PRESSES
    #define BTN_TOGLR_MODE_SELECT_PRESSES 2
#endif

#ifndef BTN_TOGLR_MODE_SELECT_TIMEOUT
    #define BTN_TOGLR_MODE_SELECT_TIMEOUT 2250
#endif

#ifndef BTN_TOGLR_TURNOFF_LED_MS
    #define BTN_TOGLR_TURNOFF_LED_MS 2500
#endif

extern EasyButton toggler;

void initializeToggler(void);

#endif
