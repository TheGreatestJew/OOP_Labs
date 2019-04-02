#ifndef B2_HPP
#define B2_HPP

#include <iostream>

class B2 {
private:
    int m_value;

public:
    B2(int value = 0);
    virtual ~B2() = default;

    virtual void show() const;
};

B2::B2(int value)
    : m_value(value)
{
}

void B2::show() const
{
    std::cout << "B2.m_value = " << m_value << ";";
}

#endif // B2_HPP
