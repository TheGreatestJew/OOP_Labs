#include "economcalc.hpp"

int EconomCalc::getCost(Estate* value)
{
    auto coff = 0.06;
    auto currencyCoff = 100.0;

    return static_cast<int>(value->getResidents() * coff * currencyCoff * value->getMonths() / 6.0);
}
