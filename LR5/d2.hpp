#ifndef D2_HPP
#define D2_HPP

#include "d1.hpp"

class D2 : private D1 {
private:
    int m_value;

public:
    D2(int value = 0, int d1 = 0, int b1 = 0, int b2 = 0);
    ~D2() override;

    void show() const override;
};

D2::D2(int value, int d1, int b1, int b2)
    : D1(d1, b1, b2)
    , m_value(value)
{
    std::cout << "D2()\n";
}

D2::~D2()
{
    std::cout << "~D2()\n";
}

void D2::show() const
{
    D1::show();
    std::cout << "\n";
    std::cout << "D2.m_value = " << m_value << ";";
}

#endif // D2_HPP
