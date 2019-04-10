#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <cstddef>

typedef float TypeData;

class Array {
private:
    TypeData* m_array;
    unsigned m_size;

public:
    Array();
    Array(const Array& other) = delete;
    ~Array();

    TypeData& operator[](unsigned pos) const;
    unsigned size() const { return m_size; }

    void print() const;

    TypeData searchMinElement() const;
    TypeData sum() const;
    void zeroFirst();
};

#endif // ARRAY_HPP
