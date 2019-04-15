#ifndef APP_HPP
#define APP_HPP

#include <vector>

class App {
private:
    std::vector<double> m_values;

public:
    App(); ///< Запускает приложение
    App(const App&) = delete;
    ~App() = default;

private:
    void generateVector(unsigned size); ///< Генерирует вектор со случайными значениями от -50 до 50 размером size
    void divideVectorOn2(); ///< Делит элементы вектора на 2
    void swapElements(); ///< Меняет 2 первых и 2 последних элементов зеркально
    void changeTo0IfLess10(); ///< Меняет элемент на 0, если он меньше 10

    void print(); ///< Выводит вектор в консоль
};

#endif // APP_HPP