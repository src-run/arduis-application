
/*
 * This file is part of the `src-run/arduis-application` project.
 *
 * (c) Rob Frawley 2nd <rmf@src.run>
 *
 * For the full copyright and license information, please view the LICENSE.md
 * file that was distributed with this source code.
 */

#include "main.h"

void setup()
{
    while (!Serial);
    Serial.begin(9600);

    Serial.println("\n[STP] Configuring application environment ...");

    initializeRtc();
    initializeSelector();
    initializeStrands();
    initializeLuminosity();
    initializeToggler();
    luminosityDebugWriteSerialSensorDetails();
    luminosityDebugWriteSerialReadingValues();
}

void loop()
{
  
    toggler.read();

    //ledChainPatternItems[ledChainPatternIndex]();
    //strandsDisplay();

    //EVERY_N_MILLISECONDS(LED_STRDS_SEC_COLOR) {
    //    ledChainBaseColorHue++;
    //}

    //EVERY_N_MILLISECONDS(LED_STRDS_SEC_CYCLE) {
    //    incrementSelectedPattern();
    //}

    delay(100);
}
