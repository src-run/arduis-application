
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
#include "Math.h"

#define SYS_OB_LED_ENBL   ((bool)true)

#define SYS_RANDOM_SMIN   100U
#define SYS_RANDOM_SMAX   999U

#define OUT_SERIAL_BAUD   115200UL

#define OUT_COUNTS_STAT   true
#define OUT_TIMERS_STAT   true
#define OUT_MINPWR_STAT   false
#define SYS_WIRE_D_STAT   false
#define SYS_WIRE_D_VERB   false

#ifdef _VARIANT_ARDUINO_DUE_X_
#define SYS_WIRE_OBJECT   Wire1
#else
#define SYS_WIRE_OBJECT   Wire
#endif

#define LED_RELAY1_PIN    32U
#define LED_RELAY2_PIN    33U

#define LED_STR_NUM       50U * 6U
#ifdef _VARIANT_ARDUINO_DUE_X_
#define LED_STR_PIN       3U
#else
#define LED_STR_PIN       2U
#endif
#define LED_STR_BRT       25U
#define LED_STR_CTL       WS2811
#define LED_STR_ORD       RGB
#define LED_STR_CRCT      TypicalLEDStrip
#define LED_STR_FPS       60

#define LED_PTN_SEC_CYCLE 180
#define LED_PAL_SEC_CYCLE 80
#define LED_STR_MIL_COLOR 10

#define LED_PWR_MTR_PIN   36
#define LED_PWR_MTR_VOLTS 5
#define LED_PWR_MTR_MADC  1024
#define LED_PWR_MTR_MVPA  40

#define LED_PWR_MAX_VOLTS LED_PWR_MTR_VOLTS
#define LED_PWR_MAX_MAMPS 60000

#define LED_PTN_LOOP_MILI

#define LED_PTN_SKIP_ENBL ((bool)false)

#define LED_PTN_GLNT_ENBL ((bool)true)

#define LED_FDR_IS_ACTIVE ((bool)true)
#define LED_FDR_LEVEL_BEG 0
#define LED_FDR_LEVEL_MIN 0
#define LED_FDR_LEVEL_MAX LED_STR_BRT
#define LED_FDR_STEPS_CHG LED_STR_BRT / 10
#define LED_FDR_WAITS_CHG 0

#define LED_PTN_RAND_ENTR 40
#define LED_PTN_RAND_INIT ((bool)false)
#define LED_PTN_RAND_NEXT ((bool)false)
#define LED_PTN_RAND_SEQL ((bool)false)

#define LED_PAL_RAND_ENTR 40
#define LED_PAL_RAND_INIT ((bool)true)
#define LED_PAL_RAND_NEXT ((bool)true)
#define LED_PAL_RAND_SEQL ((bool)true)

#define LED_PAL_FACT_BASE 5
#define LED_PAL_FACT_MINS 1

#define LED_PTN_TWIK_RAND 20
#define LED_PTN_TWIK_MAXL 111
#define LED_PTN_TWIK_MINL 0

#ifndef ARDUIS_I2C_DEVICE_LIST__SIZE_STRS
#define ARDUIS_I2C_DEVICE_LIST__SIZE_STRS 0
#endif

#ifndef ARDUIS_I2C_DEVICE_LIST__SIZE_ARRS
#define ARDUIS_I2C_DEVICE_LIST__SIZE_ARRS 0
#endif

#ifndef ARDUIS_I2C_DEVICE_LIST__SIZE_OBJS
#define ARDUIS_I2C_DEVICE_LIST__SIZE_OBJS 0
#endif

#ifndef ARDUIS_I2C_DEVICE_LIST__JSON_TEXT
#define ARDUIS_I2C_DEVICE_LIST__JSON_TEXT "[]"
#endif
