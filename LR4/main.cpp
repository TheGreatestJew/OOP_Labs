#include "righttriangle.hpp"
#include <iostream>

using namespace std;

int main()
{
    cout << "Проверка Angle: \n\n";

    cout << "\tangle=Angle(400)\n";
    auto angle = Angle(400);
    cout << "\t\tangle.angle() = " << angle.angle() << "\n";
    cout << "\t\tangle.toRadians() = " << angle.toRadians() << "\n\n";

    cout << "\tfirst=Angle(-90); second = Angle(135)\n";
    auto first = Angle(-90);
    auto second = Angle(135);
    cout << "\t\tfirst.angle() = " << first.angle() << "\n";
    cout << "\t\tsecond.angle() = " << second.angle() << "\n";
    cout << "\t\t(first + second).angle() = " << (first + second).angle() << "\n";
    cout << "\t\t(first - second).angle() = " << (first - second).angle() << "\n";
    cout << "\t\t(second - first).angle() = " << (second - first).angle() << "\n\n";

    cout << "Проверка RightTriangle: \n\n";

    cout << "\ttriangle = RightTriangle(45, 6);(градусы, длинна)\n";
    auto triangle = RightTriangle(45, 6);
    cout << "\ttriangle.angle() = " << triangle.angle() << "\n";
    cout << "\ttriangle.length() = " << triangle.length() << "\n";
    cout << "\ttriangle.area() = " << triangle.area() << "\n";

    return 0;
}
