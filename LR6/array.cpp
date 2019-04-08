#include "array.hpp"
#include "arrayemptyexception.hpp"
#include "invalidposexception.hpp"
#include "noelementsbetweenpos.hpp"
#include "noposelementsexception.hpp"
#include <iostream>

Array::Array()
    : m_array(nullptr)
    , m_size(0)
{
}

Array::Array(TypeData* array, size_t size)
    : Array()
{
    for (size_t pos = 0; pos < size; pos++) {
        pushBack(array[pos]);
    }
}

Array::~Array()
{
    m_size = 0;
    if (m_array)
        delete[] m_array;
    m_array = nullptr;
}

void Array::resize(size_t new_size)
{
    if (new_size == 0) {
        if (m_array)
            delete[] m_array;
        m_array = nullptr;
        m_size = 0;
        return;
    }

    TypeData* arr = new TypeData[new_size];
    if (m_size > new_size) {
        for (size_t pos = 0; pos < new_size; pos++) {
            arr[pos] = m_array[pos];
        }
    } else {
        for (size_t pos = 0; pos < m_size; pos++) {
            arr[pos] = m_array[pos];
        }
    }

    delete[] m_array;
    m_array = arr;
    m_size = new_size;
}

void Array::pushBack(TypeData data)
{
    resize(m_size + 1);
    m_array[m_size - 1] = data;
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

    for (size_t pos = 0; pos < m_size; pos++) {
        std::cout << m_array[pos] << " ";
    }

    std::cout << "\n";
}

TypeData Array::searchMinElement() const
{
    if (m_size == 0)
        throw ArrayEmptyException();

    TypeData curMin = m_array[0];
    for (size_t pos = 1; pos < m_size; pos++) {
        if (m_array[pos] < curMin)
            curMin = m_array[pos];
    }

    return curMin;
}

TypeData Array::sum() const
{
    if (m_size == 0)
        throw ArrayEmptyException();

    size_t posFirst = 0;
    for (posFirst = 0; posFirst < m_size; posFirst++) {
        if (0 < m_array[posFirst])
            break;
    }
    if (posFirst == m_size) {
        throw NoPosElementsException();
    }

    size_t posScnd = m_size - 1;
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
    for (size_t pos = posFirst + 1; pos < posScnd; pos++) {
        out += m_array[pos];
    }

    return out;
}

void Array::zeroFirst()
{
    size_t lastZero = 0;
    for (size_t pos = 0; pos < m_size; pos++) {
        if (m_array[pos] == 0) {
            std::swap(m_array[lastZero], m_array[pos]);
            lastZero++;
        }
    }
}

Array& Array::operator=(Array&& other)
{
    std::swap(m_array, other.m_array);
    std::swap(m_size, other.m_size);
    return *this;
}
