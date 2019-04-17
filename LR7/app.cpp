#include "app.hpp"
#include "input.hpp"
#include <climits>
#include <iomanip>
#include <iostream>
#include <random>
#include <utility>

App::App()
{
    auto size = inputValue<long long>("Введите размер массива: ", 0, UINT_MAX);

    generateVector(static_cast<unsigned>(size));
    std::cout << "Массив сгенерирован : \n";
    print();

    std::cout << "Делим все элементы на 2 : \n";
    divideVectorOn2();
    print();

    std::cout << "Зеркально меняем два первых и последних элемента : \n";
    try {
        swapElements();
        print();
    } catch (const std::exception& e) {
        std::cout << "Исключение : " << e.what() << "\n";
    }

    std::cout << "Меняем элемент на 0, если он меньше 10 : \n";
    changeTo0IfLess10();
    print();
}

void App::generateVector(unsigned size)
{
    m_values.clear();

    std::random_device device;
    std::uniform_real_distribution<double> dist(-50, 50);

    for (unsigned pos = 0; pos < size; pos++) {
        m_values.push_back(dist(device));
    }
}

void App::divideVectorOn2()
{
    for (auto& val : m_values) {
        val /= 2;
    }
}

void App::swapElements()
{
    auto size = m_values.size();

    if (size < 4)
        throw std::runtime_error("Невозможно поменять местами 4 элемента, если их нет.");

    std::swap(m_values[0], m_values[size - 1]);
    std::swap(m_values[1], m_values[size - 2]);
}

void App::changeTo0IfLess10()
{
    for (auto& val : m_values) {
        if (val < 10)
            val = 0;
    }
}

void App::print()
{
    if (m_values.empty()) {
        std::cout << "Пусто\n";
        return;
    }

    for (unsigned pos = 0; pos < m_values.size() - 1; pos++) {
        std::cout << std::setw(6) << std::setprecision(3) << std::right << m_values[pos] << ", ";
    }
    std::cout << std::setw(6) << std::setprecision(3) << std::right << m_values[m_values.size() - 1];

    std::cout << "\n";
}
