#ifndef CALCFACTORYTOWNHOUSE_HPP
#define CALCFACTORYTOWNHOUSE_HPP

#include "calcfactory.hpp"

class CalcFactoryTownHouse : public CalcFactory {
public:
    CalcFactoryTownHouse() = default;

    bstractCalc* FactoryMethod(Estate* state) override;
};

#endif // CALCFACTORYTOWNHOUSE_HPP
