#include <cmath>
#include <iostream>

using namespace std;

class cyl {
private:
    float radius;
    float height;

public:
    cyl(float radius = 0, float height = 0)
    {
        this->radius = abs(radius);
        this->height = abs(height);
    }

    float Volume() const { return float(M_PI) * radius * radius * height; }
    float Area() const
    {
        return 2 * (float(M_PI) * radius * radius) + ///< площадь двух кругов в основании
            (2 * float(M_PI) * radius * height); ///< площадь боковой стороны
    }
};

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
            cout << "Неверный ввод!\n";
            continue;
        }
    }
}

int main()
{
    cout << "Введите параметры циллиндра\n(Параметры берутся по модулю):\n";
    float r = inputFloat("Введите радиус: ");
    float h = inputFloat("Введите высоту: ");
    cyl c = cyl(r, h);
    cout << "Обьем равен " << c.Volume() << "\n"
         << "Площадь равна " << c.Area() << "\n";

    return 0;
}
