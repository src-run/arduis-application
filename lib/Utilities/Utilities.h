
/*
 * This file is part of the `src-run/arduis-application` project.
 *
 * (c) Rob Frawley 2nd <rmf@src.run>
 *
 * For the full copyright and license information, please view the LICENSE.md
 * file that was distributed with this source code.
 */

#ifndef _ARDUIS_HR_UTILITES
#define _ARDUIS_HR_UTILITES

#include <Arduino.h>
#include <FastLED.h>

#define ARRAY_SIZE(A) (*(&A + 1) - A)
//#define ARRAY_SIZE(A) ((int)(sizeof(A) / sizeof((A)[0])))

#define PIN_MODE_UNKNOWN      0xff
#define PIN_MODE_INPUT        INPUT
#define PIN_MODE_INPUT_PULLUP INPUT_PULLUP
#define PIN_MODE_OUTPUT       OUTPUT

enum StringPadDirection {
    lft = -1,
    all =  0,
    rgt =  1,
};

byte         cstrByte(const long i);
unsigned int cstrUInt(const long i);

byte         randByte();
byte         randByte(byte lim);
byte         randByte(byte min, byte lim);

unsigned int randUInt();
unsigned int randUInt(unsigned int lim);
unsigned int randUInt(unsigned int min, unsigned int lim);

unsigned int setRandomEntr(byte min, byte max);
unsigned int setRandomEntr(byte max = 8);
unsigned int addRandomEntr(byte min, byte max);
unsigned int addRandomEntr(byte max = 8);

void         addRandomEntrEveryNCalls(byte n = 20);

unsigned int getRandomSeed();
unsigned int getRandomIndx(unsigned int size);

bool lt(int x, unsigned int y);
bool lt(unsigned int x, int y);
bool lt(unsigned int x, unsigned int y);
bool lt(int x, int y);

byte getPinMode(byte pin);

bool setPinMode(byte pin, byte act);
bool setPinModeOutput(byte pin);
bool setPinModeOutput(byte pin, byte out);
bool setPinModeInput(byte pin);
bool setPinModeInputPullup(byte pin);

bool isPinMode(byte pin, byte act);
bool isPinModeOutput(byte pin);
bool isPinModeInput(byte pin);
bool isPinModeInputPullup(byte pin);

const String strQuote(const String value, const String quote = "\"");
const String strPadsChar(const String value, int padSize = -1, const String padChar = " ", const StringPadDirection padWhat = StringPadDirection::lft);
const String strPadsCharLft(const String value, int padSize = -1, const String padChar = " ");
const String strPadsCharRgt(const String value, int padSize = -1, const String padChar = " ");

const unsigned int changeIntBase(unsigned int val, unsigned int curBase = 100, unsigned int newBase = 100);
const unsigned int fracToPercent(unsigned int val);
const unsigned int miliToSeconds(unsigned int val);

#endif
