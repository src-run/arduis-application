
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
#include "CommonSparkfunTwist.h"
#include "Config.h"
#include "PatternsList.h"
#include "SelectVersion.h"

class SelectManager {
    private:
        byte         _address;
        TWIST        _twister;
        bool         _started { false };
        unsigned int _elapsedSinceLastTwist { 0 };
        unsigned int _elapsedSinceLastClick { 0 };

    public:
        SelectManager(const byte address = 0x3F) : _address { address } {};
        void begins();

        bool         setLimit(unsigned int limit);
        unsigned int getLimit();
        bool         hasLimit();

        bool setTwistCount(unsigned int count);
        int  getTwistCount();
        bool hasTwistCount();
        int  getTwistDiffs();

        bool hasClick();
        bool hasPress();

        bool setColor(byte r, byte g, byte b);
        bool setColor(CRGB c);
        CRGB getColor();

        unsigned int getTimeSinceLastTwist(bool clear = true);
        unsigned int getTimeSinceLastClick(bool clear = true);

        SelectVersion getVersion();

        void writeDebugInfo();

    protected:
        unsigned int getVersionRaw();
};
