#ifndef ARRAYEMPTYEXCEPTION_HPP
#define ARRAYEMPTYEXCEPTION_HPP

#include <stdexcept>

class ArrayEmptyException : public std::exception {
public:
    ArrayEmptyException() = default;

    const char* what() const noexcept override;
};

const char* ArrayEmptyException::what() const noexcept
{
    return "Попытка работать с пустым массивом";
}

#endif // ARRAYEMPTYEXCEPTION_HPP
