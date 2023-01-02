
/*
 * This file is part of the `src-run/arduis-application` project.
 *
 * (c) Rob Frawley 2nd <rmf@src.run>
 *
 * For the full copyright and license information, please view the LICENSE.md
 * file that was distributed with this source code.
 */

#include <Relays.h>

Relay::Relay(byte pin)
{
	setPin(pin);
}

byte Relay::getPin()
{
	return _pin;
}

bool Relay::setPin(byte pin)
{
    if (_beg && _pin != pin && isPinModeOutput(_pin)) {
        setPinModeInput(_pin);
    }

    _pin = pin;
    _beg = true;

    return setPinModeOutput(_pin);
}

bool Relay::isEnabled()
{
    return _beg && 1 == digitalRead(_pin);
}

bool Relay::isDisabled()
{
    return !_beg || 0 == digitalRead(_pin);
}

bool Relay::enable()
{
    Serial.println(String("Relay::enable() -> ") + String(_pin));
    digitalWrite(_pin, true);
    Serial.println(String("Relay::enable() -> ") + String(digitalRead(_pin)));

    return isEnabled();
}

bool Relay::disable()
{
    Serial.println(String("Relay::disable() -> ") + String(_pin));
    digitalWrite(_pin, false);
    Serial.println(String("Relay::disable() -> ") + String(digitalRead(_pin)));

    return isDisabled();
}
