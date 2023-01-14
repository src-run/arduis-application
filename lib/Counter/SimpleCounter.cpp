
/*
 * This file is part of the `src-run/arduis-application` project.
 *
 * (c) Rob Frawley 2nd <rmf@src.run>
 *
 * For the full copyright and license information, please view the LICENSE.md
 * file that was distributed with this source code.
 */

#include "SimpleCounter.h"

unsigned long SimpleCounter::getCount()
{
    return _count;
}

void SimpleCounter::increment(unsigned long amount)
{
    _count += amount;
}

void SimpleCounter::reset()
{
    _count = 0;
}
