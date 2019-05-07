#include "bstractcalclux.hpp"

bstractCalcLux::bstractCalcLux(Estate* state)
    : bstractCalc(state)
{
}

int bstractCalcLux::getCost() const
{
    return static_cast<int>(m_state->getArea() * coff * currencyCoff * m_state->getMonths() / 6.0);
}
