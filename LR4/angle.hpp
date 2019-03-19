#ifndef ANGLE_HPP
#define ANGLE_HPP

#include <cmath>

#ifndef M_PI
#define M_PI 3.141592653589793238462643
#endif

class Angle {
protected:
    double m_angle;

public:
    Angle();
    Angle(double angle);
    Angle(const Angle& other) = default;
    virtual ~Angle() = default;

    double toRadians() const;

    Angle operator+(const Angle& other) const;
    Angle operator-(const Angle& other) const;

    virtual double angle() const;
    virtual void setAngle(double angle);

private:
    void normalize();
};

#endif // ANGLE_HPP
