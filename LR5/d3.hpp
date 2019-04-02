#ifndef D3_HPP
#define D3_HPP

#include "b3.hpp"
#include "d2.hpp"

class D3 : public D2, private B3 {
private:
    int m_value;

public:
    D3(int value, D2 d2, B3 b3);

    void show() const override;
};

D3::D3(int value, D2 d2, B3 b3)
    : D2(d2)
    , B3(b3)
    , m_value(value)
{
}

void D3::show() const
{
    D2::show();
    std::cout << "\n";
    B3::show();
    std::cout << "\n";
    std::cout << "D3.m_value = " << m_value << ";";
}

#endif // D3_HPP
