#include "time.hpp"
#include <iostream>

using namespace std;

int main()
{
    std::string str;
    //Проверка прибавления минут
    {
        cout << "Работа оператор прибавления минут к времени: \n";
        cout << "В конструктор поступают значения: 0 часов, 5 минут и 300 секунд. \n";
        Time first(0, 5, 300);
        str << first;
        cout << "Значения времени нормализовано и записано ниже.\n";
        cout << "Исходные значения времени: " << str << "\n";
        cout << "Прибавляется 65 минут: \n";
        first = first + 65;
        str << first;
        cout << "Результат : " << str << "\n\n";
        cout << "Прибавляется 7 минут: \n";
        first = first + 7;
        str << first;
        cout << "Результат : " << str << "\n\n";
    }
    cout << "\n---------------------------------------------------\n";
    //Проверка работы вычитания
    {
        cout << "Работа оператора вычитания: \n";
        cout << "Исходные данные: 1:20:30 и 0:50:10\n";
        Time first(1, 20, 30), second(0, 50, 10);

        cout << "Производится вычитание: \n";
        cout << "Вычитание из первого второе:\n";
        Time timed = first - second;
        str << timed;
        cout << "Результат : " << str << "\n\n";

        cout << "Вычитание из второго первое:\n";
        timed = second - first;
        str << timed;
        cout << "Результат : " << str << "\n\n";

        cout << "Вычитание из результата первое:\n";
        timed = timed - first;
        str << timed;
        cout << "Результат : " << str << "\n\n";

        cout << "Вычитание из результата обратное второму числу:\n";
        timed = timed - (-second);
        str << timed;
        cout << "Результат : " << str << "\n\n";
    }
    cout << "\n---------------------------------------------------\n";
    //Проверка преобразования
    {

        Time tmp;
        std::string("-0:20:10") >> tmp;
        str << tmp;
        cout << "Преобразование строки \"-0:20:10\" в Time : " << str << "\n";

        std::string("25:90:3600") >> tmp;
        str << tmp;
        cout << "Преобразование строки \"25:90:3600\" в Time (с нормализацией значений) : " << str << "\n";

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
        cout << "Удаляется объект 0:0:0 из-за достижения конца составного блока операторов\n";
    }
    return 0;
}
