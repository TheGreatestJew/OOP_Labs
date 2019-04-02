#include "d3.hpp"
#include <cstring>
#include <iomanip>

int main()
{
    std::cout << "obj = D3(19, 20, 9, 8, 7, 10)"
              << "\n";
    D3 obj = D3(19, 20, 9, 8, 7, 10);

    std::cout << "\n";

    std::cout << "obj.show() : \n";
    obj.show();
    std::cout << "\n\n";
    std::cout << "~D():\n";
    return 0;
}
