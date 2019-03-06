#include "time.hpp"
#include <iostream>

Time::Time()
{
    m_hour = 0;
    m_minutes = 0;
    m_second = 0;
    m_neg = false;
}

Time::Time(TimeValue hour, TimeValue minute, TimeValue second)
    : Time()
{
    m_hour = hour;
    m_minutes = minute;
    m_second = second;

    fixTime();
}

Time::Time(const Time& other)
    : Time()
{
    m_hour = other.m_hour;
    m_minutes = other.m_minutes;
    m_second = other.m_second;
    m_neg = other.m_neg;

    fixTime();
}

Time::~Time()
{
    //Нечего удалять.
}

Time Time::operator+(unsigned minutes) const
{
    Time time(*this);

    time.add(0, minutes, 0);

    return time;
}

Time Time::operator-(const Time& other) const
{
    Time out = Time(*this);

    if (other.negative()) {
        out.add(other.m_hour, other.m_minutes, other.m_second);
    } else {
        out.minus(other.m_hour, other.m_minutes, other.m_second);
    }

    return out;
}

Time Time::operator-() const
{
    Time t = Time(*this);
    t.m_neg = !t.m_neg;
    return t;
}

bool Time::negative() const
{
    return m_neg;
}

bool Time::isZero() const
{
    return m_hour == 0 && m_minutes == 0 && m_second == 0;
}

void Time::fixTime()
{
    m_minutes += m_second / 60;
    m_second %= 60;

    m_hour += m_minutes / 60;
    m_minutes %= 60;
}

void Time::add(TimeValue h, TimeValue m, TimeValue s)
{
    if (negative()) {
        if (-(*this) > Time(h, m, s)) {
            m_hour -= h;
            if (m_minutes > m)
                m_minutes -= m;
            else {
                m_minutes = 60 - (m - m_minutes);
                m_hour -= 1;
            }
            if (m_second > s)
                m_second -= s;
            else {
                m_second = 60 - (s - m_second);
                m_minutes -= 1;
            }

            fixTime();
        } else {
            m_neg = false;
            m_hour = h - m_hour;
            if (m > m_minutes)
                m_minutes = m - m_minutes;
            else {
                m_minutes = 60 - (m_minutes - m);
                m_hour--;
            }
            if (m > m_second)
                m_second = s - m_second;
            else {
                m_second = 60 - (m_second - s);
                m_minutes--;
            }
            fixTime();
        }
    } else {
        m_hour += h;
        m_minutes += m;
        m_second += s;
        fixTime();
    }
}

void Time::minus(TimeValue h, TimeValue m, TimeValue s)
{
    if (negative()) {
        m_hour += h;
        m_minutes += m;
        m_second += s;
        fixTime();
    } else {
        if (*this > Time(h, m, s)) {
            m_hour -= h;
            if (m_minutes > m)
                m_minutes -= m;
            else {
                m_minutes = 60 - (m - m_minutes);
                m_hour -= 1;
            }
            if (m_second > s)
                m_second -= s;
            else {
                m_second = 60 - (s - m_second);
                m_minutes -= 1;
            }
            fixTime();
        } else {
            m_neg = true;
            m_hour = (h - m_hour);
            if (m > m_minutes)
                m_minutes = m - m_minutes;
            else {
                m_minutes = 60 - (m_minutes - m);
                m_hour--;
            }
            if (m > m_second)
                m_second = s - m_second;
            else {
                m_second = 60 - (m_second - s);
                m_minutes--;
            }
            fixTime();
        }
    }
}

std::string& operator<<(std::string& left, const Time& right)
{
    left.clear();
    if (right.negative())
        left += "-";
    auto hour = right.m_hour;

    left += std::to_string(hour) + ":" + std::to_string(right.m_minutes) + ":" + std::to_string(right.m_second);

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

    right.m_neg = neg;
    right.m_hour = static_cast<TimeValue>(std::stoul(hour));
    right.m_minutes = static_cast<TimeValue>(std::stoul(minutes));
    right.m_second = static_cast<TimeValue>(std::stoul(seconds));

    right.fixTime();

    return right;
}

bool operator>(const Time& left, const Time& right)
{
    if (left.negative() && !right.negative())
        return false;
    else if (!left.negative() && right.negative())
        return true;

    if (left.negative()) {
        if (left.m_hour < right.m_hour)
            return true;
        if (left.m_hour == right.m_hour && left.m_minutes < right.m_minutes) {
            return true;
        }

        else if (left.m_hour == right.m_hour && left.m_minutes == right.m_minutes && left.m_second < right.m_second) {
            return true;
        }
        return false;
    } else {
        if (left.m_hour > right.m_hour)
            return true;
        if (left.m_hour == right.m_hour && left.m_minutes > right.m_minutes) {
            return true;
        }

        else if (left.m_hour == right.m_hour && left.m_minutes == right.m_minutes && left.m_second > right.m_second) {
            return true;
        }
        return false;
    }
}
