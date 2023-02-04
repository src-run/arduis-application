
/*
 * This file is part of the `src-run/arduis-application` project.
 *
 * (c) Rob Frawley 2nd <rmf@src.run>
 *
 * For the full copyright and license information, please view the LICENSE.md
 * file that was distributed with this source code.
 */

#include "SelectManager.h"

void SelectManager::begins()
{
    if (!_started && !_twister.begin(SYS_WIRE_OBJECT, _address)) {
        writeI2cDevFailureAndDelayForever("Twist", _address);
    }

    _started = true;

    writeDebugInfo();

    setColor(CRGB { 10, 30, 30 });
    setLimit(patternSizeItems);
    setTwistCount(0);
}

bool SelectManager::setLimit(unsigned int limit)
{
    return _twister.setLimit(limit);
}

unsigned int SelectManager::getLimit()
{
    return _twister.getLimit();
}

bool SelectManager::hasLimit()
{
    return 0 != getLimit();
}

bool SelectManager::setTwistCount(unsigned int count)
{
    return _twister.setCount(count);
}

int SelectManager::getTwistCount()
{
    return _twister.getCount();
}

bool SelectManager::hasTwistCount()
{
    return _twister.isMoved();
}

int SelectManager::getTwistDiffs()
{
    return _twister.getDiff();
}

bool SelectManager::hasClick()
{
    return _twister.isClicked();
}

bool SelectManager::hasPress()
{
    return _twister.isPressed();
}

bool SelectManager::setColor(byte r, byte g, byte b)
{
    return _twister.setColor(r, g, b);
}

bool SelectManager::setColor(CRGB c)
{
    return _twister.setColor(c.r, c.g, c.b);
}

CRGB SelectManager::getColor()
{
    return {
        _twister.getRed(),
        _twister.getGreen(),
        _twister.getBlue(),
    };
}

unsigned int SelectManager::getTimeSinceLastTwist(bool clear)
{
    return _twister.timeSinceLastMovement(clear);
}

unsigned int SelectManager::getTimeSinceLastClick(bool clear)
{
    return _twister.timeSinceLastPress(clear);
}

SelectVersion SelectManager::getVersion()
{
    return {
        getVersionRaw() & 0xFF,
        getVersionRaw() >> 8,
    };
}

unsigned int SelectManager::getVersionRaw()
{
    return _twister.getVersion();
}

void SelectManager::writeDebugInfo()
{
    Serial.print(F("=== Twist - Firmware Ver : "));
    Serial.println(getVersion().getFormattedVersion());
}
