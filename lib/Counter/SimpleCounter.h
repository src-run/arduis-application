
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

class SimpleCounter {
    private:
        unsigned long _count { 0 };

    public:
        SimpleCounter() = default;

        unsigned long getCount();
        void increment(unsigned long amount = 1);
        void reset();
};
