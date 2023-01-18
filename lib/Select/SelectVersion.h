
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

struct SelectVersion {
    const unsigned int major;
    const unsigned int minor;

    String getFormattedVersion()
    {
        const String format { F("%d.%d") };
        char         buffer [ String(major).length() + String(minor).length() + 1 + 1 ];

        sprintf(buffer, format.c_str(), major, minor);

        return { buffer };
    }
};
