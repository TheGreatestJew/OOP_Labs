#ifndef B1_HPP
#define B1_HPP

#include <iostream>

class B1 {
private:
    int m_value;

public:
    B1(int value = 0);
    virtual ~B1() = default;

    virtual void show() const;
};

B1::B1(int value)
    : m_value(value)
{
}

void B1::show() const
{
    std::cout << "B1.m_value = " << m_value << ";";
}

#endif // B1_HPP
