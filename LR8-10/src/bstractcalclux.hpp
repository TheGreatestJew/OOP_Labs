#ifndef BSTRACTCALCLUX_HPP
#define BSTRACTCALCLUX_HPP

#include "bstractcalc.hpp"

class bstractCalcLux : public bstractCalc {
private:
    const double coff = 0.1;
    const double currencyCoff = 100.0;

public:
    bstractCalcLux(Estate* state);

    int getCost() const override;
};

#endif // BSTRACTCALCLUX_HPP
