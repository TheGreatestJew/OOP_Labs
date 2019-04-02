#include "righttriangle.hpp"
#include <stdexcept>

RightTriangle::RightTriangle()
    : Angle(45)
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
    if (angle <= 0.0 || 90.0 <= angle)
        throw std::runtime_error("Неправильный угол : должно быть 0 < angle < 90");

    Angle::setAngle(angle);
}

double RightTriangle::length() const
{
    return m_length;
}

void RightTriangle::setLength(double length)
{
    if (length <= 0)
        throw std::runtime_error("Неправильная длина катета : должно быть length > 0");
    m_length = length;
}

double RightTriangle::area() const
{
    return tan(toRadians()) * m_length * m_length / 2.0;
}
