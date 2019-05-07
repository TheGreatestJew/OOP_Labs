#include "bstractcalccottage.hpp"

bstractCalcCottage::bstractCalcCottage(Estate* state)
    : bstractCalc(state)
{
}

int bstractCalcCottage::getCost() const
{
    return static_cast<int>(m_state->getArea() * coff * currencyCoff * m_state->getMonths() / 6.0 - ageCoff * m_state->getAge());
}
