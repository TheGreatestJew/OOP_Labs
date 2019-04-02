#ifndef INVALIDPOSEXCEPTION_HPP
#define INVALIDPOSEXCEPTION_HPP

#include <stdexcept>

class InvalidPosException : public std::exception {

public:
    InvalidPosException() = default;

    const char* what() const noexcept override;
};

const char* InvalidPosException::what() const noexcept
{
    return "Неверная позиция элемента.";
}

#endif // INVALIDPOSEXCEPTION_HPP
