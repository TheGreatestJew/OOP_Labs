#ifndef BSTRACTCALC_HPP
#define BSTRACTCALC_HPP

#include "estate.hpp"

class bstractCalc {
protected:
    Estate* m_state;

public:
    bstractCalc(Estate* state);
    virtual ~bstractCalc() = default;

    virtual int getCost() const = 0;
};

#endif // BSTRACTCALC_HPP
