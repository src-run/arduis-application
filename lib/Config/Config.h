
/*
 * This file is part of the `src-run/arduis-application` project.
 *
 * (c) Rob Frawley 2nd <rmf@src.run>
 *
 * For the full copyright and license information, please view the LICENSE.md
 * file that was distributed with this source code.
 */

#pragma once

#include "CommonFastLED.h"

#define SYS_OB_LED_ENBL   ((bool)true)
#define SYS_RANDOM_SMIN   10
#define SYS_RANDOM_SMAX   40
#define SYS_RANDOM_CALL   120
#define OUT_SERIAL_BAUD   115200UL
#define OUT_COUNTS_STAT   ((bool)true)

#define LED_RELAY_PIN     33

#define LED_GRP_LEN       50
#define LED_GRP_NUM       5

#define LED_STR_NUM       LED_GRP_LEN * LED_GRP_NUM
#define LED_STR_PIN       6
#define LED_STR_BRT       80
#define LED_STR_CTL       WS2811
#define LED_STR_ORD       RGB
#define LED_STR_FPS       60
#define LED_PTN_SEC_CYCLE 120
#define LED_PAL_SEC_CYCLE 60
#define LED_STR_MIL_COLOR 20

#define LED_PWR_MAX_VOLTS 5
#define LED_PWR_MAX_MAMPS 60000

#define LED_PTN_WAIT_LOOP 1024 / LED_STR_FPS
#define LED_PTN_WAIT_NEXT 0

#define LED_PTN_SKIP_ENBL ((bool)true)

#define LED_PTN_GLNT_ENBL ((bool)true)

#define LED_PTN_FADE_ENBL ((bool)true)
#define LED_PTN_FADE_MILI LED_PTN_WAIT_LOOP
#define LED_PTN_FADE_STEP LED_STR_BRT / 6

#define LED_PTN_RAND_ENTR 20
#define LED_PTN_RAND_INIT ((bool)false)
#define LED_PTN_RAND_NEXT ((bool)true)
#define LED_PTN_RAND_SEQL ((bool)true)

#define LED_PAL_RAND_ENTR 20
#define LED_PAL_RAND_INIT ((bool)true)
#define LED_PAL_RAND_NEXT ((bool)true)
#define LED_PAL_RAND_SEQL ((bool)true)

#define LED_PTN_TWIK_RAND 20
#define LED_PTN_TWIK_MAXL 111
#define LED_PTN_TWIK_MINL 0
