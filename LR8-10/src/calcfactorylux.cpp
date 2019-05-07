#include "calcfactorylux.hpp"
#include "bstractcalclux.hpp"

bstractCalc* CalcFactoryLux::FactoryMethod(Estate* state)
{
    return new bstractCalcLux(state);
}
