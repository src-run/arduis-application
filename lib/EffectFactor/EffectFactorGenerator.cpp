
/*
 * This file is part of the `src-run/arduis-application` project.
 *
 * (c) Rob Frawley 2nd <rmf@src.run>
 *
 * For the full copyright and license information, please view the LICENSE.md
 * file that was distributed with this source code.
 */

#include "EffectFactorGenerator.h"

void EffectFactorGenerator::refresh()
{
    const byte random = (randByte() * _resultBase / 255);

    _factor = constrain(random, _resultMins, _resultBase);
}

byte EffectFactorGenerator::resolve()
{
    return _factor;
}
