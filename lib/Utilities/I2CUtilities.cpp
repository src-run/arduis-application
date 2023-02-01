
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
    static const String               jsonRaw { getI2CDeviceListJsonText() };
    static const size_t               jsonLen { (jsonRaw.length() + (jsonRaw.length() / 4)) };
    static DynamicJsonDocument        jsonDoc { jsonLen };
    static const DeserializationError jsonErr { deserializeJson(jsonDoc, jsonRaw) };

    if (jsonErr) {
        Serial.print(F("!!! ERROR - JSON deserialization failure ("));
        Serial.print(jsonErr.f_str());
        Serial.println(F(")"));

        Serial.print(F("!!! ERROR - JSON minimized raw txt block ("));
        Serial.print(jsonRaw);
        Serial.print(F(")["));
        Serial.print(jsonLen, DEC);
        Serial.println(F("]"));
    }

    return jsonDoc;
}

String getI2CDeviceListJsonText()
{
    const String txt { ([]() -> String {
        return SYS_WIRE_D_VERB ? F(STR(ARDUIS_I2C_DEVICE_LIST_JSON)) : F("[]");
    })() };

    if (txt.startsWith("\"") && txt.endsWith("\"")) {
        return txt.substring(1, txt.length() - 1);
    }

    return txt;
}

String getI2CFoundDesc(const I2CDeviceInfo& deviceInfo)
{
    static DynamicJsonDocument deviceMain { getI2CDeviceListJson() };
    static JsonArray           deviceList { deviceMain.as<JsonArray>() };
    String                     returnList {};

    if (deviceList.isNull() || deviceList.size() == 0) {
        return F(" [Unknown Device]");
    }

    for(JsonVariant device : deviceList) {
        addI2CDevicesMatchingAddressList(returnList, device, deviceInfo);
        addI2CDevicesMatchingAddressSets(returnList, device, deviceInfo);
    }

    if (returnList.length() > 0) {
        returnList = String(F(" [")) + returnList + String(F("]"));
    }

    return returnList;
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

void addI2CDevicesMatchingAddressSets(String& deviceStr, const JsonVariant& device, const I2CDeviceInfo& deviceInfo)
{
    if (!device.containsKey(F("addressSets"))) {
        return;
    }

    JsonArray addressList { device[F("addressSets")].as<JsonArray>() };

    for(JsonVariant addressRange : addressList) {
        if (!addressRange.containsKey(F("beg")) || addressRange[F("beg")].isNull() ||
            !addressRange.containsKey(F("end")) || addressRange[F("end")].isNull()) {
            continue;
        }

        if (deviceInfo.address >= strtoul((addressRange[F("beg")].as<String>()).c_str(), NULL, 16) &&
            deviceInfo.address <= strtoul((addressRange[F("end")].as<String>()).c_str(), NULL, 16)) {
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
