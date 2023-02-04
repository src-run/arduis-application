
/*
 * This file is part of the `src-run/arduis-application` project.
 *
 * (c) Rob Frawley 2nd <rmf@src.run>
 *
 * For the full copyright and license information, please view the LICENSE.md
 * file that was distributed with this source code.
 */

#include "Temper.h"

TemperManager SystemTemper { };

void setupTemper()
{
    SystemTemper.begins();
}

void cycleTemper()
{
    debugTemper();
}

void debugTemper()
{
    SystemTemper.writeDebugSensorInfoCombs();
}
