#include "righttriangle.hpp"
#include <stdexcept>

RightTriangle::RightTriangle()
    : Angle()
{
    setLength(1);
}

RightTriangle::RightTriangle(double angle, double length)
    : RightTriangle()
{
    setAngle(angle);
    setLength(length);
}

double RightTriangle::angle() const
{
    return Angle::angle();
}

void RightTriangle::setAngle(double angle)
{
    if (angle < 0.0 || 90.0 < angle)
        throw std::runtime_error("Invalid angle");

    Angle::setAngle(angle);
}

double RightTriangle::length() const
{
    return m_length;
}

void RightTriangle::setLength(double length)
{
    m_length = length;
}

double RightTriangle::area() const
{
    return tan(toRadians()) * m_length * m_length / 2.0;
}
