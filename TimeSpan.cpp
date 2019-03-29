#include "TimeSpan.hpp"

namespace TBQ
{
    TimeSpan::TimeSpan() :
        ticks(0)
    {
        // Nothing to do
    }

    TimeSpan::TimeSpan(Tick ticks) :
        ticks(ticks)
    {
        // Nothing to do
    }

    TimeSpan::TimeSpan(
        long days,
        char hours,
        char mins,
        char secs,
        short millis,
        short micros,
        short nanos
    ) {
        Tick ticks = days;
        
        ticks *= 24;
        ticks += hours;

        ticks *= 60;
        ticks += mins;

        ticks *= 60;
        ticks += secs;

        ticks *= 1000;
        ticks += millis;

        ticks *= 1000;
        ticks += micros;

        ticks *= 1000;
        ticks += nanos;
        
        // Times ticks per sec, over nanos per sec
        ticks = (ticks * TBQ_TIMESPAN_TICKSPERSEC) / 1000000000;
        this->ticks = ticks;
    }

    TimeSpan&
    TimeSpan::operator=(Tick fromTicks)
    {
        ticks = fromTicks;
        return *this;
    }

    TimeSpan&
    TimeSpan::operator+=(const TimeSpan& timeSpan)
    {
        ticks += timeSpan.ticks;
        return *this;
    }

    TimeSpan&
    TimeSpan::operator-=(const TimeSpan& timeSpan)
    {
        ticks -= timeSpan.ticks;
        return *this;
    }

    TimeSpan
    TimeSpan::operator+(const TimeSpan& timeSpan)
    {
        return TimeSpan(ticks + timeSpan.ticks);
    }

    TimeSpan
    TimeSpan::operator-(const TimeSpan& timeSpan)
    {
        return TimeSpan(ticks - timeSpan.ticks);
    }

    bool
    TimeSpan::operator==(const TimeSpan& timeSpan)
    {
        return ticks == timeSpan.ticks;
    }

    bool
    TimeSpan::operator!=(const TimeSpan& timeSpan)
    {
        return ticks != timeSpan.ticks;
    }

    bool
    TimeSpan::operator<(const TimeSpan& timeSpan)
    {
        return ticks < timeSpan.ticks;
    }

    bool
    TimeSpan::operator<=(const TimeSpan& timeSpan)
    {
        return ticks <= timeSpan.ticks;
    }

    bool
    TimeSpan::operator>(const TimeSpan& timeSpan)
    {
        return ticks > timeSpan.ticks;
    }

    bool
    TimeSpan::operator>=(const TimeSpan& timeSpan)
    {
        return ticks >= timeSpan.ticks;
    }
}
