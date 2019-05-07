#ifndef CALCFACTORYECONOM_HPP
#define CALCFACTORYECONOM_HPP

#include "calcfactory.hpp"

class CalcFactoryEconom : public CalcFactory {
public:
    CalcFactoryEconom() = default;

    bstractCalc* FactoryMethod(Estate* state) override;
};

#endif // CALCFACTORYECONOM_HPP
