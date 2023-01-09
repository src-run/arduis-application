
/*
 * This file is part of the `src-run/arduis-application` project.
 *
 * (c) Rob Frawley 2nd <rmf@src.run>
 *
 * For the full copyright and license information, please view the LICENSE.md
 * file that was distributed with this source code.
 */

#pragma once

#include "Common.h"
#include "ActionDetail.h"
#include "ActionTimers.h"
#include "ActionGlints.h"
#include "PatternsActionRunner.h"

struct PatternsAction {
    const ActionDetail        detail;
    const ActionRunnerPattern runner;
    const ActionTimers        timers;
    const ActionGlints        glints;
};
