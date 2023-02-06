
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
    String                     jsonTxt { getI2CDeviceListJsonText() };
    DynamicJsonDocument        jsonDoc { jsonTxt.length() };
    const DeserializationError jsonErr { deserializeJson(jsonDoc, jsonTxt) };

    if (jsonErr) {
        Serial.print(F("!!! ERROR - JSON deserialization failure ("));
        Serial.print(jsonErr.f_str());
        Serial.println(F(")"));
    }

    return jsonDoc;
}

String getI2CDeviceListJsonText()
{
    const String jsonTxt = SYS_WIRE_D_VERB ? F(STR(ARDUIS_I2C_DEVICE_LIST__JSON_TEXT)) : F("[]");

    Serial.println(jsonTxt);

    return jsonTxt.startsWith("\"") && jsonTxt.endsWith("\"")
        ? jsonTxt.substring(1, jsonTxt.length() - 1)
        : jsonTxt;
}

String getI2CFoundDesc(const I2CDeviceInfo& deviceInfo)
{
    String                 returnList { };
    static const JsonArray deviceList { getI2CDeviceListJson().as<JsonArray>() };

    if (deviceList.isNull() || deviceList.size() == 0) {
        return F("");
    }

    for(JsonVariant device : deviceList) {
        addI2CDevicesMatchingAddressList(returnList, device, deviceInfo);
    }

    return returnList.length() > 0
        ? String(F(" [")) + returnList + String(F("]"))
        : returnList;
}

void addI2CDevicesMatchingAddressList(String& deviceStr, const JsonVariant& device, const I2CDeviceInfo& deviceInfo)
{
    if (!device.containsKey(F("addressList"))) {
        return;
    }

    JsonArray addressList { device[F("addressList")].as<JsonArray>() };

    for(JsonVariant addressValue : addressList) {
        if (deviceInfo.address == strtoul((addressValue.as<String>()).c_str(), NULL, 16)) {
            addI2CDeviceStr(deviceStr, device);
        }
    }
}

void addI2CDeviceStr(String& deviceStr, const JsonVariant& device)
{
    if (!device.containsKey(F("deviceIdent"))) {
        return;
    }

    if (deviceStr.length() > 0) {
        deviceStr += String(F(", "));
    }

    deviceStr += String(device["deviceIdent"].as<String>());

    if (device.containsKey(F("deviceAbout"))) {
        deviceStr += String(F(" (")) + String(device["deviceAbout"].as<String>()) + String(F(")"));
    }
}
