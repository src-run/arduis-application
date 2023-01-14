
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

struct PowerCalculatedBrightness {
    const unsigned int pixels;
    const double       inputA;
    const byte         inputV;
    const byte         levelMaximum;
    const byte         levelRequest;
};
