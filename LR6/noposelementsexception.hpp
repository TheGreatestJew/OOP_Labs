#ifndef NOPOSELEMENTSEXCEPTION_HPP
#define NOPOSELEMENTSEXCEPTION_HPP

#include <stdexcept>

class NoPosElementsException : public std::exception {
public:
    NoPosElementsException() = default;

    const char* what() const noexcept override;
};

const char* NoPosElementsException::what() const noexcept
{
    return "Нет положительных элементов для суммирования между ними";
}

#endif // NOPOSELEMENTSEXCEPTION_HPP
