#include "array.hpp"
#include "arrayemptyexception.hpp"
#include "invalidposexception.hpp"
#include "noelementsbetweenpos.hpp"
#include "noposelementsexception.hpp"
#include "nozerosexception.hpp"
#include "input.hpp"
#include <iostream>
#include <limits>

Array::Array()
    : m_array(nullptr)
    , m_size(0)
{
	auto size = inputValue<long long>("Введите размер массива: ", 0, UINT_MAX);
	m_size = static_cast<unsigned>(size);
	m_array = inputArray<TypeData>("Введите значения массива: ", m_size);
}

Array::~Array()
{
    m_size = 0;
    if (m_array)
        delete[] m_array;
    m_array = nullptr;
}

TypeData& Array::operator[](size_t pos) const
{
    if (m_size <= pos)
        throw InvalidPosException();

    return m_array[pos];
}

void Array::print() const
{
    std::cout << "Массив: ";
    if (m_size == 0) {
        std::cout << " пуст\n";
        return;
    }

    for (unsigned pos = 0; pos < m_size; pos++) {
        std::cout << m_array[pos] << " ";
    }

    std::cout << "\n";
}

TypeData Array::searchMinElement() const
{
    if (m_size == 0)
        throw ArrayEmptyException();

    TypeData curMin = m_array[0];
    for (unsigned pos = 1; pos < m_size; pos++) {
        if (m_array[pos] < curMin)
            curMin = m_array[pos];
    }

    return curMin;
}

TypeData Array::sum() const
{
    if (m_size == 0)
        throw ArrayEmptyException();

    unsigned posFirst = 0;
    for (posFirst = 0; posFirst < m_size; posFirst++) {
        if (0 < m_array[posFirst])
            break;
    }
    if (posFirst == m_size) {
        throw NoPosElementsException();
    }

    unsigned posScnd = m_size - 1;
    for (posScnd = m_size - 1; posScnd > 0; posScnd--) {
        if (0 < m_array[posScnd])
            break;
    }

    if (posScnd == 0)
        throw NoPosElementsException();

    if (posFirst == posScnd)
        throw NoPosElementsException();

    if (posFirst == posScnd - 1)
        throw NoElementsBetweenPos();

    TypeData out = 0;
    for (unsigned pos = posFirst + 1; pos < posScnd; pos++) {
        out += m_array[pos];
    }

    return out;
}

void Array::zeroFirst()
{
    unsigned lastZero = 0;
	bool foundedZeros = false;
    for (unsigned pos = 0; pos < m_size; pos++) {
        if (m_array[pos] == 0) {
			foundedZeros = true;
            std::swap(m_array[lastZero], m_array[pos]);
            lastZero++;
        }
    }

	if (!foundedZeros)
		throw NoZerosException();
}
