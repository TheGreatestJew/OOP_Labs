#include <iostream>
#include <string>

using namespace std;

class ChessCoord {
private:
    int m_x = 0;
    int m_y = 0;

public:
    bool SetCoord(int x, int y)
    {
        //размер доски 8
        if (x < 1 || x > 8 || y < 1 || y > 8) {
            return false;
        }

        m_x = x;
        m_y = y;

        return true;
    }
    int x() { return m_x; }
    int y() { return m_y; }

    bool isWhite()
    {
        //Если оба поля четные или нечетные, то черное
        if (m_x % 2 == m_y % 2)
            return false;
        return true;
    }
};

int inputInt(const char* msg)
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
            int out = stoi(tmpNumber);
            return out;
        } catch (const std::exception& e) {
            cout << "Неверный ввод!\n";
            continue;
        }
    }
}

int main()
{
    ChessCoord coords;
    bool invalid = true;
    cout << "Введите координаты шахматной доски:\n";

    while (invalid) {
        int x = inputInt("Координата X: ");
        int y = inputInt("Координаты Y: ");

        if (coords.SetCoord(x, y)) {
            invalid = false;
        } else {
            cout << "Координаты вне сетки поля.\n";
        }
    }

    cout << "Поле (" << coords.x() << ", " << coords.y() << ") ";
    cout << ((coords.isWhite()) ? "белое" : "черное");
    cout << "\n";

    return 0;
}
