#ifndef NOZEROSEXCEPTION_HPP
#define NOZEROSEXCEPTION_HPP

#include <stdexcept>

class NoZerosException : public std::exception
{
public:
	NoZerosException() = default;

	const char* what() const noexcept override;
};

const char* NoZerosException::what() const noexcept
{
	return "Нет нулевых элементов";
};

#endif // !NOZEROSEXCEPTION_HPP

