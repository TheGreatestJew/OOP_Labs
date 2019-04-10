//Здесь утлиты для запроса чисел у пользователя

#include <iostream>
#include <sstream>
#include <string>

//Эта функция пытется преобразовать строку в определенный тип
template <typename T>
bool convert_to(const std::string& str, T& value)
{
    T output = T();
    std::stringstream SS(str);
    SS >> output;

    //Если значение получить не удалось или удалось не полностью
    if (SS.fail() || !SS.eof()) {
        return false;
    }
    value = output;
    return true;
}

//Эта функция запрашивает у пользователя строку и пытается её преобразовать к указанному типу
template <typename T>
T inputValue(const char* messageToUser)
{
    T output;
    std::string gettedFromUser;
    while (true) {
        std::cout << messageToUser;
        std::getline(std::cin, gettedFromUser);
        if (convert_to<T>(gettedFromUser, output)) {
            break;
        }
        std::cout << "Ввод неверен. Повторите попытку." << std::endl;
    }
    return output;
}

//Запрашивает значение с ограничением значений
template <typename T>
T inputValue(const char* messageToUser, T minValue, T maxValue)
{
    T output;
    while (true) {
        output = inputValue<T>(messageToUser);
        //Если вне ОДЗ
        if (output < minValue || maxValue < output) {
            std::cout << "Число должно быть от " << minValue << " до " << maxValue << std::endl;
            continue;
        }
        break;
    }

    return output;
}

//Запрашивает массив значений
template <typename T>
T* inputArray(const char* messageToUser, unsigned size)
{
    std::cout << messageToUser << std::endl;
    T* output = new T[size];
    for (unsigned i = 0; i < size; i++) {
        char messageToInput[64];
        std::sprintf(messageToInput, "Введите элемент %u: ", static_cast<unsigned>(i));
        output[i] = inputValue<T>(messageToInput);
    }
    return output;
}
