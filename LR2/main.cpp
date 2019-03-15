#include "cyl.h"
#include <cmath>
#include <iostream>
#include <string>

using namespace std;

float inputFloat(const char* msg)
{
    cin.clear();
    cin.ignore(cin.rdbuf()->in_avail());
    cin.sync();

    cout << msg;

    while (true) {
        std::string tmpNumber;
        getline(cin, tmpNumber);
        if (tmpNumber.empty()) {
            continue;
        }
        try {
            float out = stof(tmpNumber);
            return out;
        } catch (const std::exception& e) {
            (void)e;
            cout << "Неверный ввод! Повторите: ";
            continue;
        }
    }
}

int main()
{
    cout << "Использование конструктора по умолчанию:\n";
    cyl def = cyl();
    cout << "Высота равна " << def.getHeight() << "\n"
         << "Радиус равен " << def.getRadius() << "\n";
    cout << "Обьем равен " << def.Volume() << "\n"
         << "Площадь равна " << def.Area() << "\n";

    cout << "\n\n";

    cout << "Использование конструктора с установкой значений\n";
    cout << "Введите параметры циллиндра\n(Параметры берутся по модулю):\n";
    float r = inputFloat("Введите радиус: ");
    float h = inputFloat("Введите высоту: ");
    cyl c = cyl(r, h);
    cout << "Высота равна " << c.getHeight() << "\n"
         << "Радиус равен " << c.getRadius() << "\n";
    cout << "Обьем равен " << c.Volume() << "\n"
         << "Площадь равна " << c.Area() << "\n";

    cout << "\n\n";

    cout << "Использование конструктора копирования. Копируется цилиндр, заданный пользователем.\n";
    cyl copy = cyl(c);
    cout << "Высота равна " << copy.getHeight() << "\n"
         << "Радиус равен " << copy.getRadius() << "\n";
    cout << "Обьем равен " << copy.Volume() << "\n"
         << "Площадь равна " << copy.Area() << "\n";
    return 0;
}
