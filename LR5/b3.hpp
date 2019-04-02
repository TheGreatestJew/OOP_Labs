#ifndef B3_HPP
#define B3_HPP

#include <iostream>

class B3 {
private:
    int m_value;

public:
    B3(int value = 0);
    virtual ~B3() = default;

    virtual void show() const;
};

B3::B3(int value)
    : m_value(value)
{
}

void B3::show() const
{
    std::cout << "B3.m_value = " << m_value << ";";
}

#endif // B3_HPP
