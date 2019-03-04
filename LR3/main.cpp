#include "time.hpp"
#include <iostream>

using namespace std;

int main()
{
    std::string str;
    {
        cout << "Работа оператор прибавления минут к времени: \n";
        Time first(0, 5, 300);
        str << first;
        cout << "Исходные значения времени: " << str << "\n";
        first = first + 5;
        str << first;
        cout << "Добавляются 5 минут: " << str << "\n";
        first = first + 65;
        str << first;
        cout << "Добавляются 65 минут: " << str << "\n";
        first = first + (-120);
        str << first;
        cout << "Убавляется 120 минут: " << str << "\n";
        cout << "\n\n";
    }
    {
        cout << "Работа оператора вычитания: \n";
        cout << "Исходные данные: 1:20:30 и 0:50:10\n";
        Time first(1, 20, 30), second(0, 50, 10);

        Time timed = first - second;
        str << timed;
        cout << "Вычитание первого из второго: " << str << "\n";
        timed = second - first;
        str << timed;
        cout << "Вычитание второго из первого: " << str << "\n";
        cout << "\n\n";
    }
    {

        Time tmp;
        std::string("-0:20:10") >> tmp;
        str << tmp;
        cout << "Преобразование строки \"-0:20:10\" в Time : " << str << "\n";

        std::string("25:20:4000") >> tmp;
        str << tmp;
        cout << "Преобразование строки \"25:20:4000\" в Time : " << str << "\n";

        cout << "Преобразование строки \"Время\" в Time : ";
        try {
            std::string("Время") >> tmp;
            str << tmp;
            cout << str << "\n";
        } catch (...) {
            cout << "Ошибка!\n";
        }

        cout << "Преобразование строки \"-25:-20:4000\" в Time : ";
        try {
            std::string("-25:-20:4000") >> tmp;
            str << tmp;
            cout << str << "\n";
        } catch (...) {
            cout << "Ошибка!\n";
        }
    }
    return 0;
}
