#include "time.hpp"
#include <iostream>

Time::Time()
{
    m_hour = 0;
    m_minutes = 0;
    m_second = 0;
}

Time::Time(TimeValue hour, TimeValue minute, TimeValue second)
    : Time()
{
    addHour(hour);
    addMinutes(minute);
    addSeconds(second);
}

Time::Time(const Time& other)
    : Time()
{
    m_hour = other.m_hour;
    m_minutes = other.m_minutes;
    m_second = other.m_second;
}

Time::~Time()
{
    std::string str;
    str << *this;
    std::cout << "Время " << str << " уничтожено.\n";
}

Time Time::operator+(TimeValue minutes) const
{
    return *this + Time(0, minutes, 0);
}

Time Time::operator+(Time other) const
{
    Time out = Time(*this);

    out.addHour(other.m_hour);
    out.addMinutes(other.m_minutes);
    out.addSeconds(other.m_second);

    return out;
}

Time Time::operator-(const Time& other) const
{
    return *this + (-other);
}

Time Time::operator-() const
{
    Time out;
    out.m_hour = -m_hour;
    out.m_minutes = -m_minutes;
    out.m_second = -m_second;
    return out;
}

bool Time::negative() const
{
    if (m_hour < 0)
        return true;
    if (m_hour == 0 && m_minutes < 0)
        return true;
    if (m_hour == 0 && m_minutes == 0 && m_second < 0)
        return true;
    return false;
}

void Time::addHour(TimeValue hour)
{
    m_hour += hour;
}

void Time::addMinutes(TimeValue minutes)
{
    m_minutes += minutes % 60;
    addHour(minutes / 60);
}

void Time::addSeconds(TimeValue seconds)
{
    m_second += seconds % 60;
    addMinutes(seconds / 60);
}

std::string& operator<<(std::string& left, const Time& right)
{
    left.clear();
    if (right.negative())
        left += "-";
    auto hour = right.m_hour;
    if (hour < 0) //-1 час - 0 на отрицательных часах
        hour++;
    left += std::to_string(abs(hour)) + ":" + std::to_string(abs(right.m_minutes)) + ":" + std::to_string(abs(right.m_second));
    return left;
}

Time& operator>>(const std::string& left, Time& right)
{
    size_t pos = 0;
    bool neg = false;

    if (left[0] == '-') {
        pos++;
        neg = true;
    }
    std::string hour;

    for (/**/; pos < left.size(); pos++) {
        if (left[pos] == ':')
            break;
        if (left[pos] == '-')
            throw std::invalid_argument("Wrong str");
        hour += left[pos];
    }

    std::string minutes;
    for (pos = pos + 1; pos < left.size(); pos++) {
        if (left[pos] == ':')
            break;
        if (left[pos] == '-')
            throw std::invalid_argument("Wrong str");
        minutes += left[pos];
    }

    std::string seconds;
    for (pos = pos + 1; pos < left.size(); pos++) {
        if (left[pos] == '-')
            throw std::invalid_argument("Wrong str");
        seconds += left[pos];
    }

    right.m_hour = 0; //Пусть кидает исключение
    right.m_minutes = 0;
    right.m_second = 0;

    right.addHour((neg) ? -std::stoi(hour) : std::stoi(hour));
    right.addMinutes((neg) ? -std::stoi(minutes) : std::stoi(minutes));
    right.addSeconds((neg) ? -std::stoi(seconds) : std::stoi(seconds));

    return right;
}
