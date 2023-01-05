
/*
 * This file is part of the `src-run/arduis-application` project.
 *
 * (c) Rob Frawley 2nd <rmf@src.run>
 *
 * For the full copyright and license information, please view the LICENSE.md
 * file that was distributed with this source code.
 */

#ifndef _ARDUIS_HR_CONFIG
#define _ARDUIS_HR_CONFIG

#include <Arduino.h>
#include <FastLED.h>

#define OUT_SERIAL_BAUD   19200UL

#define LED_RELAY_PIN     33

#define LED_GRP_LEN       50
#define LED_GRP_NUM       5

//#define LED_INDV_GROUPS_SEC 5
//#define LED_INDV_GROUPS_LEN 50
//#define LED_COMP_STRING_LEN LED_INDV_GROUPS_SEC * LED_INDV_GROUPS_LEN

#define LED_STR_NUM       LED_GRP_LEN * LED_GRP_NUM
#define LED_STR_PIN       6
#define LED_STR_BRT       80
#define LED_STR_CTL       WS2811
#define LED_STR_ORD       RGB
#define LED_STR_FPS       60
#define LED_STR_SEC_CYCLE 120000UL
#define LED_STR_PAL_CYCLE LED_STR_SEC_CYCLE / 3
#define LED_STR_SEC_COLOR 20

#define LED_PWR_MAX_VOLTS 5
#define LED_PWR_MAX_MAMPS 60000

#define LED_PTN_STEP_MILI 1000 / LED_STR_FPS
#define LED_PTN_NEXT_MILI 0
#define LED_PTN_FADE_MILI LED_PTN_STEP_MILI
#define LED_PTN_FADE_STEP LED_STR_BRT / 6
#define LED_PTN_FADE_ENBL ((bool)true)
#define LED_PTN_STEP_RAND ((bool)false)
#define LED_PTN_CPAL_RAND ((bool)true)

#define LED_PTN_TWIK_RAND 10
#define LED_PTN_TWIK_MAXL 100
#define LED_PTN_TWIK_MINL 0

#endif
