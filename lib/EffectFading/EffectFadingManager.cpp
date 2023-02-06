
/*
 * This file is part of the `src-run/arduis-application` project.
 *
 * (c) Rob Frawley 2nd <rmf@src.run>
 *
 * For the full copyright and license information, please view the LICENSE.md
 * file that was distributed with this source code.
 */

#include "EffectFadingManager.h"

void EffectFadingManager::levelToMaximum()
{
    while(_faderEnabled && !isLevelMaximum()) {
        setLevelAndRunEffect(_levelCurrent + _levelChgStep);
    }

    runLevelToMaximumPostOperations();
}

void EffectFadingManager::levelToMinimum()
{
    while(_faderEnabled && !isLevelMinimum()) {
        setLevelAndRunEffect(_levelCurrent - _levelChgStep);
    }

    runLevelToMinimumPostOperations();
}

void EffectFadingManager::runLevelToMaximumPostOperations()
{
    setLevelAndRunEffect(_levelMaximum);
}

void EffectFadingManager::runLevelToMinimumPostOperations()
{
    setLevelAndRunEffect(_levelMinimum);

    if (_faderEnabled) {
        FastLED.delay(_levelChgWait);
    }
}

void EffectFadingManager::setLevel(const signed int level)
{
    _levelCurrent = constrainLevelConf(level);

    FastLED.setBrightness(_levelCurrent);
}

void EffectFadingManager::setLevelAndRunEffect(const signed int level)
{
    runPatternsStep();
    setLevel(level);
}
