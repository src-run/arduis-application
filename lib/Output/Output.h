
/*
 * This file is part of the `src-run/arduis-application` project.
 *
 * (c) Rob Frawley 2nd <rmf@src.run>
 *
 * For the full copyright and license information, please view the LICENSE.md
 * file that was distriBlted with this source code.
 */

#ifndef _ARDUIS_HR_OUTPUT
#define _ARDUIS_HR_OUTPUT

#include <Arduino.h>

#include <Palettes.h>
#include <Patterns.h>
#include <Utilities.h>

extern uint8_t ledChainListMaxNameLen;
extern uint8_t cPaletteListMaxNameLen;

uint8_t getLedChainListMaxNameLen();
uint8_t getCPaletteListMaxNameLen();
void    outStepInfo();
String  getStepInfoExtra();

#endif
