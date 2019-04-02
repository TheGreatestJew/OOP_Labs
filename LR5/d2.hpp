#ifndef D2_HPP
#define D2_HPP

#include "d1.hpp"

class D2 : private D1 {
private:
    int m_value;

public:
    D2(int value = 0, D1 d1 = D1());

    void show() const override;
};

D2::D2(int value, D1 d1)
    : D1(d1)
    , m_value(value)
{
}

void D2::show() const
{
    D1::show();
    std::cout << "\n";
    std::cout << "D2.m_value = " << m_value << ";";
}

#endif // D2_HPP
