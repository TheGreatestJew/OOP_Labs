#include "array.hpp"
#include <iostream>

const size_t COUNT_OF_ELEMENTS = 15;

void testArray(Array& array)
{
    array.print();
    std::cout << "\tПытаемся получить доступ к 1000 элементу: ";
    try {
        std::cout << array[1000] << "\n";
    } catch (const std::exception& e) {
        std::cout << "Исключение: " << e.what() << "\n";
    }

    std::cout << "\tМинимальный элемент: ";
    try {
        std::cout << array.searchMinElement() << "\n";
    } catch (const std::exception& e) {
        std::cout << "Исключение: " << e.what() << "\n";
    }
    std::cout << "\tСумма от 1 положительного до последнего положительного: ";
    try {
        std::cout << array.sum() << "\n";
    } catch (const std::exception& e) {
        std::cout << "Исключение: " << e.what() << "\n";
    }
    std::cout << "\tУстановка нулевых элементов в начало : ";
    try {
        array.zeroFirst();
        array.print();
    } catch (const std::exception& e) {
        std::cout << "Исключение: " << e.what() << "\n";
    }
    std::cout << "\n\n";
}

int main()
{
    Array array;
    TypeData sourceArray[COUNT_OF_ELEMENTS] = { -1, -2, 0, -4, -5, -6, -7, 0, 1, 1, -1, -9, -3, -4, -5 };
    array = Array(sourceArray, COUNT_OF_ELEMENTS);
    testArray(array);

    return 0;
}
