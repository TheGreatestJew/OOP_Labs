#ifndef CALCFACTORY_HPP
#define CALCFACTORY_HPP

#include "bstractcalc.hpp"

class CalcFactory {
public:
    CalcFactory() = default;
    virtual ~CalcFactory() = default;

    virtual bstractCalc* FactoryMethod(Estate* state) = 0;
};

#endif // CALCFACTORY_HPP
