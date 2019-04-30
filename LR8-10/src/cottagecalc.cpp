#include "cottagecalc.hpp"

int CottageCalc::getCost(Estate* value)
{
    auto coff = 0.05;
    auto currencyCoff = 100.0;
    auto ageCoff = 3;
    return static_cast<int>(value->getArea() * coff * currencyCoff * value->getMonths() / 6.0 - ageCoff * value->getAge());
}
