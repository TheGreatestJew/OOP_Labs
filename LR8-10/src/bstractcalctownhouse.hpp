#ifndef BSTRACTCALCTOWNHOUSE_HPP
#define BSTRACTCALCTOWNHOUSE_HPP

#include "bstractcalc.hpp"

class bstractCalcTownHouse : public bstractCalc {
private:
    const double coff = 0.06;
    const double currencyCoff = 100.0;

public:
    bstractCalcTownHouse(Estate* state);

    int getCost() const override;
};

#endif // BSTRACTCALCTOWNHOUSE_HPP
