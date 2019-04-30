#include "estate.hpp"

Estate::Estate(QObject* parent)
    : QObject(parent)
    , age(0)
    , area(0.0)
    , residents(0)
    , months(6)
    , type(ECONOM)
    , owner("Unknown")
{
}

Estate::Estate(int age, double area, int residents, int months, Estate::EstateType type, QString owner, QObject* parent)
    : Estate(parent)
{
    this->age = age;
    this->area = area;
    this->residents = residents;
    this->months = months;
    this->type = type;
    this->owner = owner;
}

int Estate::getAge() const
{
    return age;
}

double Estate::getArea() const
{
    return area;
}

int Estate::getResidents() const
{
    return residents;
}

int Estate::getMonths() const
{
    return months;
}

Estate::EstateType Estate::getType() const
{
    return type;
}

QString Estate::getOwner() const
{
    return owner;
}
