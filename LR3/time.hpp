#ifndef TIME_HPP
#define TIME_HPP

#include <string>

/*
Разработать класс «Время».
Определить в нем конструкторы и деструктор,
перегрузить операцию добавления к времени заданного количества минут,
операцию вычитания двух моментов времени,
операцию преобразования в символьную строку и метод получения момента времени из строки
*/

class Time;

//Тип использованый для хранения времени
typedef unsigned TimeValue;

/* Операция преобразования момента времени в строку.
 * Пример: str << time;*/
std::string& operator<<(std::string& left, const Time& right);

/* Операция преобразования строки в момент времени.
 * Пример: str >> time;*/
Time& operator>>(const std::string& left, Time& right);

/* Сравнение двух точек времени
 * */
bool operator>(const Time& left, const Time& right);

class Time {
private:
    TimeValue m_hour; ///< Часы, отрицательные значения смещены на 1 в сторону нуля
    TimeValue m_minutes; ///< Минуты
    TimeValue m_second; ///< Секунды

    bool m_neg; ///< находиться ли время в отрицательном зоне

public:
    //Конструктор по умолчанию. Значения 0:0:0
    Time();
    //Конструктор, устанавливающий значения и нормализующая их
    Time(TimeValue hour, TimeValue minutes, TimeValue second);
    //Конструктор копирования
    Time(const Time& other);

    //Деструктор. Выводит факт своего вызова
    ~Time();

    //Добавляет minutes минут к времени
    Time operator+(unsigned minutes) const;
    //Вычитание двух моментов времени
    Time operator-(const Time& other) const;
    //Унарный минус
    Time operator-() const;

    friend std::string& operator<<(std::string& left, const Time& right);
    friend Time& operator>>(const std::string& left, Time& right);
    friend bool operator>(const Time& left, const Time& right);

    //Проверяет находиться ли время в отрицательном зоне
    bool negative() const;
    bool isZero() const;

private:
    void fixTime();

    void add(TimeValue h, TimeValue m, TimeValue s);
    void minus(TimeValue h, TimeValue m, TimeValue s);
};

#endif // TIME_HPP
