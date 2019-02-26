#include "cyl.h"

#include <cmath>
float cyl::getHeight() const
{
    return height;
}

void cyl::setHeight(float value)
{
    height = std::abs(value);
}

cyl::cyl()
{
    setRadius(0);
    setHeight(0);
}

cyl::cyl(float radius, float height)
{
    setRadius(radius);
    setHeight(height);
}

cyl::cyl(const cyl& other)
{
    setRadius(other.radius);
    setHeight(other.height);
}

cyl::~cyl()
{
    std::cout << "Деструктор вызван: " << this << "!\n";
}

float cyl::Volume() const { return float(M_PI) * radius * radius * height; }

float cyl::Area() const
{
    return 2 * (float(M_PI) * radius * radius) + ///< площадь двух кругов в основании
        (2 * float(M_PI) * radius * height); ///< площадь боковой стороны
}

float cyl::getRadius() const
{
    return radius;
}

void cyl::setRadius(float value)
{
    radius = std::abs(value);
}
