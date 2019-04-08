#ifndef NOELEMENTSBETWEENPOS_HPP
#define NOELEMENTSBETWEENPOS_HPP

#include <stdexcept>
#include <string>
#include "array.hpp"

class NoElementsBetweenPos : public std::exception {
	std::string m_msg;
public:
    NoElementsBetweenPos(TypeData element1, TypeData element2);

    const char* what() const noexcept override;
};

inline NoElementsBetweenPos::NoElementsBetweenPos(TypeData element1, TypeData element2) : m_msg("")
{
	m_msg += "Нет элементов между ";
	m_msg += std::to_string(element1) + " и " + std::to_string(element2);
	m_msg += " для суммирования";
}

const char* NoElementsBetweenPos::what() const noexcept
{
    return m_msg.c_str();
}

#endif // NOELEMENTSBETWEENPOS_HPP
