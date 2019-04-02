#ifndef D1_HPP
#define D1_HPP

#include "b1.hpp"
#include "b2.hpp"
#include <iostream>

class D1 : public B1, private B2 {
private:
    int m_value;

public:
    D1(int d1_value = 0, B1 b1 = 0, B2 b2 = 0);

    void show() const override;
};

D1::D1(int d1_value, B1 b1, B2 b2)
    : B1(b1)
    , B2(b2)
    , m_value(d1_value)
{
}

void D1::show() const
{
    B1::show();
    std::cout << "\n";
    B2::show();
    std::cout << "\n";
    std::cout << "D1.m_value = " << m_value << ";";
}

#endif // D1_HPP
