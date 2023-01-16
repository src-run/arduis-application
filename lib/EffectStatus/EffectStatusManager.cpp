
/*
 * This file is part of the `src-run/arduis-application` project.
 *
 * (c) Rob Frawley 2nd <rmf@src.run>
 *
 * For the full copyright and license information, please view the LICENSE.md
 * file that was distributed with this source code.
 */

#include "EffectStatusManager.h"

void EffectStatusManager::setInitIsRunning()
{
    _initRunning = true;
    _mainRunning = false;
}

void EffectStatusManager::setMainIsRunning()
{
    _initRunning = false;
    _mainRunning = true;
}

bool EffectStatusManager::isInitRunning()
{
    return _initRunning;
}

bool EffectStatusManager::isMainRunning()
{
    return _mainRunning;
}


bool EffectStatusManager::isRunning()
{
    return _initRunning || _mainRunning;
}
