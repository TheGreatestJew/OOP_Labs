#ifndef RIGHTTRIANGLE_HPP
#define RIGHTTRIANGLE_HPP

#include "angle.hpp"

class RightTriangle : private Angle {
private:
    double m_length; ///< Длина катета, лежащий рядом с углом m_angle

public:
    RightTriangle();
    RightTriangle(double angle, double length);
    RightTriangle(const RightTriangle& other) = default;
    ~RightTriangle() = default;

    virtual double angle() const;
    virtual void setAngle(double angle);
    double length() const;
    void setLength(double length);

    double area() const;
};

#endif // RIGHTTRIANGLE_HPP
