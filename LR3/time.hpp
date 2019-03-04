#ifndef TIME_HPP
#define TIME_HPP

#include <string>

class Time;
typedef int TimeValue;

std::string& operator<<(std::string& left, const Time& right);
Time& operator>>(const std::string& left, Time& right);

class Time {
private:
    TimeValue m_hour;
    TimeValue m_minutes;
    TimeValue m_second;

public:
    Time();
    Time(TimeValue hour, TimeValue minutes, TimeValue second);
    Time(const Time& other);

    ~Time();

    Time operator+(TimeValue minutes) const;
    Time operator+(Time other) const;
    Time operator-(const Time& other) const;
    Time operator-() const;

    friend std::string& operator<<(std::string& left, const Time& right);
    friend Time& operator>>(const std::string& left, Time& right);

    bool negative() const;

private:
    void addHour(TimeValue hour);
    void addMinutes(TimeValue minutes);
    void addSeconds(TimeValue seconds);
};

#endif // TIME_HPP
