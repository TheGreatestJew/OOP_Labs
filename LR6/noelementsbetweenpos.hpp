#ifndef NOELEMENTSBETWEENPOS_HPP
#define NOELEMENTSBETWEENPOS_HPP

#include <stdexcept>

class NoElementsBetweenPos : public std::exception {
public:
    NoElementsBetweenPos() = default;

    const char* what() const noexcept override;
};

const char* NoElementsBetweenPos::what() const noexcept
{
    return "Нет элементов между положительными элементами.";
}

#endif // NOELEMENTSBETWEENPOS_HPP
