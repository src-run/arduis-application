
/*
 * This file is part of the `src-run/arduis-application` project.
 *
 * (c) Rob Frawley 2nd <rmf@src.run>
 *
 * For the full copyright and license information, please view the LICENSE.md
 * file that was distributed with this source code.
 */

#pragma once

#include "CommonArduino.h"
#include "CommonFastLED.h"
#include "CommonACS712.h"
#include "Config.h"
#include "Strand.h"
#include "PowerCalculatedBrightness.h"

extern const ACS712 ledPowerMeter;

void checkMinPwr(byte levelRequest = LED_STR_BRT);

extern void outPwrLimitInfo(const PowerCalculatedBrightness&);
