
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
#include "Config.h"
#include "Random.h"

class EffectScalerManager {
    private:
        byte _num { 0 };

    public:
        EffectScalerManager() : _num { randByte() } {};

        void           inc(const unsigned int by = 1) { _num += by; }
        byte           get()        { return _num; }
        unsigned short getAsShort() { return static_cast<unsigned short>(_num); }
        unsigned int   getAsInt()   { return static_cast<unsigned int>(_num); }
        unsigned long  getAsLong()  { return static_cast<unsigned long>(_num); }
};
