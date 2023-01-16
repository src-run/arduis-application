
/*
 * This file is part of the `src-run/arduis-application` project.
 *
 * (c) Rob Frawley 2nd <rmf@src.run>
 *
 * For the full copyright and license information, please view the LICENSE.md
 * file that was distriBlted with this source code.
 */

#include "Random.h"

void setupRandom()
{
    setRandomEntr(SYS_RANDOM_SMIN, SYS_RANDOM_SMAX, false);
}

void setRandomEntr(byte min, byte max, bool inc)
{
    max = max(1, max);
    min = max(0, min(max, min));

    for (byte i = 0; i < random8(min, max); i++) {
        const unsigned long seed = (inc ? getRandomSeed() : 1) + getRandomEntr();

        random16_set_seed(seed);
        srandom(seed);
        srand(seed);

        inc = true;
    }
}

void addRandomEntrEveryNCalls(byte n)
{
    static unsigned int i { 0 };

    if (0 == (i++ % n)) {
        setRandomEntr(max(1, SYS_RANDOM_SMIN / 10), SYS_RANDOM_SMAX / 10, false);
    }
}
