#include "calcfactorycottage.hpp"
#include "bstractcalccottage.hpp"

bstractCalc* CalcFactoryCottage::FactoryMethod(Estate* state)
{
    return new bstractCalcCottage(state);
}
