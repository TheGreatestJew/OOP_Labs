#ifndef CYL_H
#define CYL_H

#include <iostream>

class cyl {
private:
    float radius;
    float height;

public:
    cyl();
    cyl(float radius, float height);
    cyl(const cyl& other);

    ~cyl();

    float Volume() const;
    float Area() const;
    float getRadius() const;
    void setRadius(float value);
    float getHeight() const;
    void setHeight(float value);
};

#endif // CYL_H
