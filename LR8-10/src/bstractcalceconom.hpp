#ifndef BSTRACTCALCECONOM_HPP
#define BSTRACTCALCECONOM_HPP

#include "bstractcalc.hpp"

class bstractCalcEconom : public bstractCalc {
private:
    const double coff = 0.5;
    const double currencyCoff = 100.0;

public:
    bstractCalcEconom(Estate* state);

    int getCost() const override;
};

#endif // BSTRACTCALCECONOM_HPP
