#include "calcfactorytownhouse.hpp"
#include "bstractcalctownhouse.hpp"

bstractCalc* CalcFactoryTownHouse::FactoryMethod(Estate* state)
{
    return new bstractCalcTownHouse(state);
}
