#include "d3.hpp"
#include <iomanip>

template <class T>
void test(T obj, const char* name)
{
    std::cout << "--- " << name << " ---\n";
    obj.show();
    std::cout << "\n"
              << std::setfill('-') << std::setw(int(strlen(name)) + 9) << "\n\n";
}

int main()
{
    test(B1(10), "B1(10)");
    test(B2(12), "B2(12)");
    test(B3(14), "B3(14)");

    test(D1(12, 13, 14), "D1(12, 13, 14)");
    test(D2(20, D1(9, 8, 7)), "D2(20, D1(9, 8, 7))");
    test(D3(19, D2(20, D1(9, 8, 7)), 10), "D3(19, D2(20, D1(9, 8, 7))");
    return 0;
}
