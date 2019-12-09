
/*
 * This file is part of the `src-run/arduis-application` project.
 *
 * (c) Rob Frawley 2nd <rmf@src.run>
 *
 * For the full copyright and license information, please view the LICENSE.md
 * file that was distributed with this source code.
 */

#ifndef _ARDUIS_HR_MAIN
#define _ARDUIS_HR_MAIN

#define LED_RELAY_PIN 33

#define LED_STRDS_LEN 250
#define LED_STRDS_PIN 6
#define LED_STRDS_BRT 25
#define LED_STRDS_CTL WS2812B
#define LED_STRDS_ORD GRB
#define LED_STRDS_FPS 240
#define LED_STRDS_SEC_CYCLE 20000
#define LED_STRDS_SEC_COLOR 10

#include <Arduino.h>
#include <FastLED.h>

#include "DateTime.h"
#include "Luminosity.h"
#include "Switcher.h"
#include "Togglers.h"
#include "Selector.h"
#include "Palettes.h"
#include "Patterns.h"
#include "Strands.h"

#endif
