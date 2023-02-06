
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

class SimpleCounter {
#if OUT_COUNTS_STAT
    private:
        unsigned int _count { 0 };
#endif

    public:
        SimpleCounter() = default;

#if OUT_COUNTS_STAT
        unsigned int getCount()  { return _count; }
        void         increment() { _count += 1; }
        void         reset()     { _count = 0; }
#else
        unsigned int getCount()  { return 0; }
        void         increment() { }
        void         reset()     { }
#endif
};
