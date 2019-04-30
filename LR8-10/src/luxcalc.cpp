#include "luxcalc.hpp"

int LuxCalc::getCost(Estate* value)
{
    auto coff = 0.1;
    auto currencyCoff = 100.0;
    return static_cast<int>(value->getArea() * coff * currencyCoff * value->getMonths() / 6.0);
}
