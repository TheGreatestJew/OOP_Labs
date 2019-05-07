#include "bstractcalceconom.hpp"

bstractCalcEconom::bstractCalcEconom(Estate* state)
    : bstractCalc(state)
{
}

int bstractCalcEconom::getCost() const
{
    return static_cast<int>(m_state->getResidents() * coff * currencyCoff * m_state->getMonths() / 6.0);
}
