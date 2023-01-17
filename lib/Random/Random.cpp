
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

void setRandomEntr(unsigned int min, unsigned int max, bool inc)
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
