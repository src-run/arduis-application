
/*
 * This file is part of the `src-run/arduis-application` project.
 *
 * (c) Rob Frawley 2nd <rmf@src.run>
 *
 * For the full copyright and license information, please view the LICENSE.md
 * file that was distributed with this source code.
 */

#ifndef _ARDUIS_HR_DATETIME
#define _ARDUIS_HR_DATETIME

#include <Arduino.h>
#include <RTClib.h>

extern const char daysOfTheWeek[7][12];
extern RTC_DS3231 rtc;

String rtcFormatDateTimeText(String dateTimeFormat = "YYYY-MM-DD hh:mm:ss", bool appendNewline = false);
String rtcFormatDateTimeLine(String startLineText = "", String closeLineText = "", String dateTimeFormat = "YYYY-MM-DD hh:mm:ss", bool appendNewline = false);
void initializeRtcInstance();
void initializeRtcDateTime();
void initializeRtc();

#endif
