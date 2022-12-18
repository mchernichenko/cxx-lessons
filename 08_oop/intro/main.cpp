#include <iostream>
#include "String.h"

int main()
{
    String s1("Hello");
    String s2("World");
    String s3 = s1 + s2;
    std::cout << s3 << std::endl; // проверка работы перегрузки оператора <<

    s3.ptr_str(); 
    for (int i = 0; i < s3.get_length(); i++)
        std::cout << s3[i]; // проверка работы перегрузки оператора []
    std::cout << std::endl;

    return 0;
}
