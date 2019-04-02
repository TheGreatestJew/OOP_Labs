#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <cstddef>

typedef float TypeData;

class Array {
private:
    TypeData* m_array;
    size_t m_size;

public:
    Array();
    Array(TypeData* array, size_t size);
    Array(const Array& other) = delete;
    ~Array();

    void pushBack(TypeData data);

    TypeData& operator[](size_t pos) const;
    size_t size() const { return m_size; }

    void print() const;

    TypeData searchMinElement() const;
    TypeData sum() const;
    void zeroFirst();

    Array& operator=(Array&& other);

private:
    void resize(size_t new_size);
};

#endif // ARRAY_HPP
