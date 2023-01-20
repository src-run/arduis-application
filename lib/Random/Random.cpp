
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

void setRandomEntr(unsigned int low, unsigned int lim, bool inc)
{
    lim = max(1, lim);
    low = max(0, min(lim, low));

    for (byte i = 0; i < random8(low, lim); i++) {
        const unsigned long seed = (inc ? getRandomSeed() : 1) + getRandomEntr();

        random16_set_seed(seed);
        srandom(seed);
        srand(seed);

        inc = true;
    }
}
