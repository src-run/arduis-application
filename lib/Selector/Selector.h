
/*
 * This file is part of the `src-run/arduis-application` project.
 *
 * (c) Rob Frawley 2nd <rmf@src.run>
 *
 * For the full copyright and license information, please view the LICENSE.md
 * file that was distributed with this source code.
 */

#ifndef _ARDUIS_HR_SELECTOR
#define _ARDUIS_HR_SELECTOR

#include <Arduino.h>
#include <Wire.h>
#include <SparkFun_Qwiic_Twist_Arduino_Library.h>

extern TWIST selector;

void selectorInitialize(int colorR = 0, int colorG = 0, int colorB = 0, bool fastClock = true);

#endif
