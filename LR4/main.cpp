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
    cout << "\ttriangle.area() = " << triangle.area() << "\n\n";

    try {
        cout << "\ttriangle.setAngle(0) : ";
        triangle.setAngle(0);
        cout << "\ttriangle.angle() = " << triangle.angle() << "\n";
    } catch (const std::exception& e) {
        cout << "Ошибка - " << e.what() << "\n";
    }

    try {
        cout << "\ttriangle.setAngle(90) : ";
        triangle.setAngle(90);
        cout << "\ttriangle.angle() = " << triangle.angle() << "\n";
    } catch (const std::exception& e) {
        cout << "Ошибка - " << e.what() << "\n";
    }

    try {
        cout << "\ttriangle.setAngle(135) : ";
        triangle.setAngle(135);
        cout << "\ttriangle.angle() = " << triangle.angle() << "\n";
    } catch (const std::exception& e) {
        cout << "Ошибка - " << e.what() << "\n";
    }

    try {
        cout << "\ttriangle.setLength(0) : ";
        triangle.setLength(0);
        cout << "\ttriangle.length() = " << triangle.length() << "\n";
    } catch (const std::exception& e) {
        cout << "Ошибка - " << e.what() << "\n";
    }

    try {
        cout << "\ttriangle.setLength(-10) : ";
        triangle.setLength(-10);
        cout << "\ttriangle.length() = " << triangle.length() << "\n";
    } catch (const std::exception& e) {
        cout << "Ошибка - " << e.what() << "\n";
    }

    return 0;
}
