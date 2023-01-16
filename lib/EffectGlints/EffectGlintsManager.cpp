
/*
 * This file is part of the `src-run/arduis-application` project.
 *
 * (c) Rob Frawley 2nd <rmf@src.run>
 *
 * For the full copyright and license information, please view the LICENSE.md
 * file that was distributed with this source code.
 */

#include"EffectGlintsManager.h"

void EffectGlintsManager::setChance(const byte chance, const byte base)
{
    _chance = constrain(chance * 255 / max(1, base), 0, 255);
    _random = randByte();
    _result = 0 != _chance && (
        (255 == _chance) || (_random <= _chance)
    );
}

byte EffectGlintsManager::getChance()
{
    return _chance;
}

byte EffectGlintsManager::getChancePercent()
{
    return byteToPerc(_chance);
}

byte EffectGlintsManager::getRandom()
{
    return _random;
}

byte EffectGlintsManager::getRandomPercent()
{
    return byteToPerc(_random);
}

bool EffectGlintsManager::isEnabled()
{
    return _enable && _result;
}
