#ifndef CALCFACTORYCOTTAGE_HPP
#define CALCFACTORYCOTTAGE_HPP

#include "calcfactory.hpp"

class CalcFactoryCottage : public CalcFactory {
public:
    CalcFactoryCottage() = default;

    bstractCalc* FactoryMethod(Estate* state) override;
};

#endif // CALCFACTORYCOTTAGE_HPP
