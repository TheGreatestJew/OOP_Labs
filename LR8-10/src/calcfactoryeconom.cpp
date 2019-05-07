#include "calcfactoryeconom.hpp"
#include "bstractcalceconom.hpp"

bstractCalc* CalcFactoryEconom::FactoryMethod(Estate* state)
{
    return new bstractCalcEconom(state);
}
