#include <cassert>

// подсчёт количева символов в строке
unsigned int length(const char *str)
{
    if (str == nullptr)
    {
        return 0;
    }

    int length = 0;
    for (int i = 0; str[i] != '\0'; i++) // Признаком конца строки является нулевой символ \0
    {
        length++;
    }

    return length;

    // с использованием арифметки указателей
    //const char* c = str;
    //while(*c != '\0')
    //    ++c;        // двигаем указатель на следующий char
    //return c - str;  // разница между указателями и будет количество char`ом, т.е. символов
}

int main()
{
    assert(length("a") == 1);
    assert(length("ab") == 2);
    assert(length("") == 0);
    assert(length("hello world") == 11);
    assert(length(nullptr) == 0);
    return 0;
}