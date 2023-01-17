
/*
 * This file is part of the `src-run/arduis-application` project.
 *
 * (c) Rob Frawley 2nd <rmf@src.run>
 *
 * For the full copyright and license information, please view the LICENSE.md
 * file that was distributed with this source code.
 */

#include "EffectFadingManager.h"

bool EffectFadingManager::isEnabled()
{
    return _faderEnabled;
}

void EffectFadingManager::fadeToLevelMaximum()
{
    while(isEnabled() && !isLevelMaximum() && loopToLevelMaximum()) {
        runPatternsStep(false);
    }

    setBrightness(_levelMaximum, _levelEndWait);
}

void EffectFadingManager::fadeToLevelMinimum()
{
    while(isEnabled() && !isLevelMinimum() && loopToLevelMinimum()) {
        runPatternsStep(false);
    }

    setBrightness(_levelMinimum, _levelEndWait);
}

bool EffectFadingManager::loopToLevelMaximum()
{
    _levelCurrent = constrain(
        _levelCurrent + _levelChgStep,
        _levelMinimum,
        _levelMaximum
    );

    setBrightness(_levelChgWait);

    return _levelCurrent < _levelMaximum;
}

bool EffectFadingManager::loopToLevelMinimum()
{
    _levelCurrent = constrain(
        _levelCurrent - _levelChgStep,
        _levelMinimum,
        _levelMaximum
    );

    setBrightness(_levelChgWait);

    return _levelCurrent > _levelMinimum;
}

bool EffectFadingManager::isLevelMaximum()
{
    return _levelCurrent >= _levelMaximum;
}

bool EffectFadingManager::isLevelMinimum()
{
    return _levelCurrent <= _levelMinimum;
}

void  EffectFadingManager::setBrightness(const byte waits)
{
    setBrightness(_levelCurrent, waits);
}

void  EffectFadingManager::setBrightness(const byte level, const byte waits)
{
    FastLED.setBrightness(level);
    FastLED.delay(waits);
}
