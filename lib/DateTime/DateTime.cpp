
/*
 * This file is part of the `src-run/arduis-application` project.
 *
 * (c) Rob Frawley 2nd <rmf@src.run>
 *
 * For the full copyright and license information, please view the LICENSE.md
 * file that was distributed with this source code.
 */

#include "DateTime.h"

const char daysOfTheWeek[7][12] = {
    "Sunday",
    "Monday",
    "Tuesday",
    "Wednesday",
    "Thursday",
    "Friday",
    "Saturday"
};

RTC_DS3231 rtc;

String rtcFormatDateTimeText(String dateTimeFormat, bool appendNewline) {
    char dateTimeFormatBuffer[100];

    dateTimeFormat.toCharArray(dateTimeFormatBuffer, 100);
    String dateTime = String(rtc.now().toString(dateTimeFormatBuffer));

    if (dateTime.indexOf("DW")) {
        dateTime.replace("DW", daysOfTheWeek[rtc.now().dayOfTheWeek()]);
    }

    if (appendNewline) {
        dateTime = dateTime + "\n";
    }

    return dateTime;
}

String rtcFormatDateTimeLine(String startLineText, String closeLineText, String dateTimeFormat, bool appendNewLine) {
    return String(startLineText + rtcFormatDateTimeText(dateTimeFormat, appendNewLine) + closeLineText);
}

void rtcInitializeInstance() {
    Serial.print("[RTC] Initializing DC3231 device on I2C bus ... ");

    if (!rtc.begin()) {
        Serial.println("[FAIL] (halting due to missing device)");
        while (1);
    }

    Serial.println("[OKAY] (found device at 0x68 I2C address)");
}

void rtcInitializeDateTime() {
    if (rtc.lostPower()) {
        rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
        Serial.println("[RTC] Device is unconfigured (check and/or replace its battery) ...");
        Serial.println(rtcFormatDateTimeLine("[RTC] Assigning the current datetime to the device ... [OKAY] (datetime set to \"", "\")"));
    } else {
        Serial.println(rtcFormatDateTimeLine("[RTC] Determined that device was previously configured ... (datetime set to \"", "\")"));
    }
}

void rtcInitialize() {
    rtcInitializeInstance();
    rtcInitializeDateTime();
}
