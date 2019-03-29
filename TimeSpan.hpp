#ifndef TBQ_TIMESPAN_HPP
#define TBQ_TIMESPAN_HPP

#ifndef TBQ_TIMESPAN_TICKSPERSEC
// Example is targeted at Arduino using "micros()" to seed,
//   this gives us a 1us tick rate.
// For use with other libraries simply define the tickrate
//   before including the header

#define TBQ_TIMESPAN_TICKSPERSEC 1000000
#endif

namespace TBQ
{
    class TimeSpan
    {
    public:
        typedef long long Tick;

        TimeSpan(); //Initalises to 0

        TimeSpan(Tick ticks);

        TimeSpan(
            long days,
            char hours,
            char mins,
            char secs,
            short millis = 0,
            short micros = 0,
            short nanos = 0
            );

        TimeSpan(const TimeSpan& copy) = default;
        TimeSpan(TimeSpan&& move) = default;
        virtual ~TimeSpan() = default;

        TimeSpan& operator=(const TimeSpan& copy) = default;
        TimeSpan& operator=(TimeSpan&& move) = default;

        TimeSpan& operator=(Tick fromTicks);

        TimeSpan& operator+=(const TimeSpan& timeSpan);
        TimeSpan& operator-=(const TimeSpan& timeSpan);
        TimeSpan operator+(const TimeSpan& timeSpan);
        TimeSpan operator-(const TimeSpan& timeSpan);

        bool operator==(const TimeSpan& timeSpan);
        bool operator!=(const TimeSpan& timeSpan);
        bool operator<(const TimeSpan& timeSpan);
        bool operator<=(const TimeSpan& timeSpan);
        bool operator>(const TimeSpan& timeSpan);
        bool operator>=(const TimeSpan& timeSpan);

        bool operator==(Tick ticks);
        bool operator!=(Tick ticks);
        bool operator<(Tick ticks);
        bool operator<=(Tick ticks);
        bool operator>(Tick ticks);
        bool operator>=(Tick ticks);

        Tick Ticks();

        long GetDays();
        char GetHours();
        char GetMinutes();
        char GetSeconds();
        short GetMillis();
        short GetMicros();
        short GetPicos();

        double TotalDays();
        double TotalHours();
        double TotalMinutes();
        double TotalSeconds();
        double TotalMillis();
        double TotalMicros();
        double TotalPicos();
    
    private:
        Tick ticks;
    };
}

#endif
