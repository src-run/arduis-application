
/*
 * This file is part of the `src-run/arduis-application` project.
 *
 * (c) Rob Frawley 2nd <rmf@src.run>
 *
 * For the full copyright and license information, please view the LICENSE.md
 * file that was distributed with this source code.
 */

#include "LoopTimeTrack.h"

void LoopTimeTrack::timerInit()
{
#if OUT_TIMERS_STAT
    if (_timerInitCount++ % _pollsFrequency == 0) {
        _timerBegMillis = millis();
        _timerActivated = true;
    }
#endif
}

void LoopTimeTrack::timerStop(const bool track, const bool write)
{
#if OUT_TIMERS_STAT
    if (_timerActivated && track) {
        _tracker.addValue(millis() - _timerBegMillis);
    }

    _timerActivated = false;

    if (write) {
        writeInfo(true);
    }
#endif
}

void LoopTimeTrack::writeInfo(const bool force)
{
#if OUT_TIMERS_STAT
    if ((!force && _tracker.getCount() != _tracker.getSize()) || _tracker.getCount() == 0) {
        return;
    }

    if (_tracker.getCount() > 2) {
        outLoopTimeInfo({
            _tracker.getAverage(),
            (unsigned int)_tracker.getMin(),
            (unsigned int)_tracker.getMax(),
            _tracker.getStandardDeviation(),
            _tracker.getStandardError(),
            _tracker.getCount(),
            _tracker.getSize(),
            _pollsFrequency
        });
    }

    _tracker.clear();
#endif
}
