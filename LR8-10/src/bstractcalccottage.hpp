#ifndef BSTRACTCALCCOTTAGE_HPP
#define BSTRACTCALCCOTTAGE_HPP

#include "bstractcalc.hpp"

class bstractCalcCottage : public bstractCalc {
private:
    const double coff = 0.05;
    const double currencyCoff = 100.0;
    const double ageCoff = 3;

public:
    bstractCalcCottage(Estate* state);

    int getCost() const override;
};

#endif // BSTRACTCALCCOTTAGE_HPP
