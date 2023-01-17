
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

void EffectFadingManager::toColor()
{
    while(isEnabled() && runFadeToColorStep()) {
        runPatternsStep(false);
    }

    FastLED.setBrightness(_levelMaximum);
    FastLED.delay(_levelEndWait);
}

bool EffectFadingManager::runFadeToColorStep()
{
    if (_levelCurrent < _levelMaximum) {
        _levelCurrent = _levelCurrent + _levelChgStep;
    }

    FastLED.setBrightness(_levelCurrent <= _levelMaximum ? _levelCurrent : _levelMaximum);
    FastLED.delay(_levelChgWait);

    return _levelCurrent < _levelMaximum;
}

void EffectFadingManager::toBlack()
{
    while(isEnabled() && runFadeToBlackStep()) {
        runPatternsStep(false);
    }

    FastLED.setBrightness(_levelMinimum);
    FastLED.delay(_levelEndWait);
}

bool EffectFadingManager::runFadeToBlackStep()
{
    if (_levelCurrent > _levelMinimum) {
        _levelCurrent = _levelCurrent - _levelChgStep;
    }

    FastLED.setBrightness(_levelCurrent >= _levelMinimum ? _levelCurrent : _levelMinimum);
    FastLED.delay(_levelChgWait);

    return _levelCurrent > _levelMinimum;
}
