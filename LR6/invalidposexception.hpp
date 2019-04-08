#ifndef INVALIDPOSEXCEPTION_HPP
#define INVALIDPOSEXCEPTION_HPP

#include <stdexcept>
#include <string>

class InvalidPosException : public std::exception {
	std::string m_msg;
public:
    InvalidPosException(unsigned pos, unsigned size);

    const char* what() const noexcept override;
};

InvalidPosException::InvalidPosException(unsigned pos, unsigned size) : m_msg("")
{
	m_msg += "Попытка получить доступ к ";
	m_msg += std::to_string(pos) + " элементу в массиве размером ";
	m_msg += std::to_string(size) + " элементов";
}

const char* InvalidPosException::what() const noexcept
{
    return m_msg.c_str();
}

#endif // INVALIDPOSEXCEPTION_HPP
