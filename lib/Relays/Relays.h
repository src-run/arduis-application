
/*
 * This file is part of the `src-run/arduis-application` project.
 *
 * (c) Rob Frawley 2nd <rmf@src.run>
 *
 * For the full copyright and license information, please view the LICENSE.md
 * file that was distributed with this source code.
 */

#ifndef _ARDUIS_HR_RELAY
#define _ARDUIS_HR_RELAY

#include <Arduino.h>
#include <Relay.h>

#include "Config.h"
#include "Utilities.h"

extern Relay ledRelay;

void initializeRelays();

#endif
