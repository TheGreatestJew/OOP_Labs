#include "bstractcalctownhouse.hpp"

bstractCalcTownHouse::bstractCalcTownHouse(Estate* state)
    : bstractCalc(state)
{
}

int bstractCalcTownHouse::getCost() const
{
    return static_cast<int>(m_state->getArea() * coff * currencyCoff * m_state->getMonths() / 6.0);
}
