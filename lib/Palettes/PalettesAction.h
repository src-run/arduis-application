
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
#include "PalettesActionRunner.h"

struct PalettesAction {
    const ActionDetail        detail;
    const ActionRunnerPalette runner;
    const ActionTimers        timers;
    const ActionGlints        glints;
};
