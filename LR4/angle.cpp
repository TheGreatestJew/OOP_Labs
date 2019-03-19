#include "angle.hpp"

double Angle::angle() const
{
    return m_angle;
}

void Angle::setAngle(double angle)
{
    m_angle = angle;
    normalize();
}

void Angle::normalize()
{
    m_angle = m_angle - ceil(m_angle / 360.0) * 360.0; // % operation but for double
    if (m_angle < 0.0) {
        m_angle += 360.0;
    }
}

Angle::Angle()
    : m_angle(0.0)
{
}

Angle::Angle(double angle)
    : m_angle(angle)
{
    normalize();
}

double Angle::toRadians() const
{
    return m_angle * M_PI / 180.0;
}

Angle Angle::operator+(const Angle& other) const
{
    Angle out = *this;
    out.m_angle += other.m_angle;
    out.normalize();
    return out;
}

Angle Angle::operator-(const Angle& other) const
{
    Angle out = *this;
    out.m_angle -= other.m_angle;
    out.normalize();
    return out;
}
