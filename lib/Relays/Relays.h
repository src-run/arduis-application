
/*
 * This file is part of the `src-run/arduis-application` project.
 *
 * (c) Rob Frawley 2nd <rmf@src.run>
 *
 * For the full copyright and license information, please view the LICENSE.md
 * file that was distributed with this source code.
 */

#ifndef _ARDUIS_HR_RELAY
#define _ARDUIS_HR_RELAY

#include <Arduino.h>
#include <Config.h>
#include <Utilities.h>

class Relay
{
    protected:
        byte _pin;
        bool _beg = false;

    public:
        Relay(byte pin);

        byte getPin();
        bool setPin(byte pin);

        bool isEnabled();
        bool isDisabled();
        bool enable();
        bool disable();
};

#endif
