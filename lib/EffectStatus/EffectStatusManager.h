
/*
 * This file is part of the `src-run/arduis-application` project.
 *
 * (c) Rob Frawley 2nd <rmf@src.run>
 *
 * For the full copyright and license information, please view the LICENSE.md
 * file that was distributed with this source code.
 */

#pragma once

#include "CommonArduino.h"

class EffectStatusManager {
    private:
        bool _initRunning { false };
        bool _mainRunning { false };

    public:
        EffectStatusManager() = default;

        void setInitIsRunning();
        void setMainIsRunning();
        bool isInitRunning();
        bool isMainRunning();
        bool isRunning();
};
