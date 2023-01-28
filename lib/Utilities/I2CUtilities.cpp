
/*
 * This file is part of the `src-run/arduis-application` project.
 *
 * (c) Rob Frawley 2nd <rmf@src.run>
 *
 * For the full copyright and license information, please view the LICENSE.md
 * file that was distributed with this source code.
 */

#include "I2CUtilities.h"

DynamicJsonDocument getI2CDeviceListJson()
{
    const String               jsonRaw { getI2CDeviceListJsonText() };
    DynamicJsonDocument        jsonObj { (jsonRaw.length() + (jsonRaw.length() / 2)) };
    const DeserializationError jsonErr { deserializeJson(jsonObj, jsonRaw) };

    if (jsonErr) {
        Serial.print(F("!!! Failure - deserializeJson() error: "));
        Serial.println(jsonErr.f_str());
    }

    return jsonObj;
}

String getI2CDeviceListJsonText()
{
    if (!SYS_WIRE_D_VERB) {
        return F("[]");
    }

    String txt { F(STR(ARDUIS_I2C_DEVICE_LIST_JSON)) };

    return txt.substring(0, 1) == "\"" && txt.substring(txt.length() - 1, txt.length()) == "\""
        ? txt.substring(1, txt.length() - 1)
        : txt;
}

String getI2CFoundDesc(const I2CDeviceInfo& deviceInfo)
{
    String              returnList {};
    DynamicJsonDocument deviceMain { getI2CDeviceListJson() };
    JsonArray           deviceList { deviceMain.as<JsonArray>() };

    if (deviceList.isNull() || deviceList.size() == 0) {
        return F("(Unknown Device)");
    }

    for(JsonVariant device : deviceList) {
        if (!device.containsKey(F("addressList"))) {
            continue;
        }

        JsonVariant addressList { device[F("addressList")] };

        for(JsonVariant address : addressList.as<JsonArray>()) {
            if (deviceInfo.address == strtoul((address.as<String>()).c_str(), NULL, 16)) {
                addI2CDeviceStr(returnList, device);
            }
        }
    }

    if (returnList.length() > 0) {
        returnList = String(F("[")) + returnList + String(F("]"));
    }

    return returnList;
}

void addI2CDeviceStr(String& deviceStr, const JsonVariant& device)
{
    if (!device.containsKey(F("deviceIdent"))) {
        return;
    }

    if (deviceStr.length() > 0) {
        deviceStr += String(", ");
    }

    deviceStr += String(device["deviceIdent"].as<String>());

    if (device.containsKey(F("deviceAbout"))) {
        deviceStr += String(F(" (")) + String(device["deviceAbout"].as<String>()) + String(F(")"));
    }
}
