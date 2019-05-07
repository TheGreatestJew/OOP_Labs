#ifndef CALCFACTORYLUX_HPP
#define CALCFACTORYLUX_HPP

#include "calcfactory.hpp"

class CalcFactoryLux : public CalcFactory {
public:
    CalcFactoryLux() = default;

    bstractCalc* FactoryMethod(Estate* state) override;
};

#endif // CALCFACTORYLUX_HPP
