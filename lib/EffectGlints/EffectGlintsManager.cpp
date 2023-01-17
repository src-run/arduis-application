
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
    _chance = cstrByte(chance * 255 / max(1, base));
    _result = _chance != 0 && (_chance == 100 || getWeightedResult());

    addResultsHistory();
}

bool EffectGlintsManager::isEnabled()
{
    return _enable && _result;
}

int EffectGlintsManager::getWeight()
{
    int weight { 0 };

    for (byte i = 0; i < ARRAY_SIZE(_resultHistoryList); i++) {
        weight += _resultHistoryList[i] ? 10 : -10;
    }

    return weight;
}

bool EffectGlintsManager::getWeightedResult()
{
    return randByte() >= cstrByte(_chance + getWeight());
}

void EffectGlintsManager::addResultsHistory()
{
    _resultHistoryList[_resultHistoryPosn] = _result;
    _resultHistoryPosn = (_resultHistoryPosn + 1) % ARRAY_SIZE(_resultHistoryList);
}
