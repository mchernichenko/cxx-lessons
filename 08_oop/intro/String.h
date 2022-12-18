// Можно реализовать функции-члены непосредственно внутри определения самого класса, однако, детали реализации принято писать в отдельном cpp
// https://radioprog.ru/post/1227
// Перегрузка операторов ввода/вывода (operator<<) https://radioprog.ru/post/1240

#include <iostream>

// Описание класса String
class String
{
    // поля (данные) класса
private:
    unsigned int m_length; // длина строки
    char *m_str;           // указатель на строку

    // методы по работе данными класса
public:
    String();                  // конструктор по умолчанию
    String(const char *str);   // конструктор
    unsigned int get_length(); // получить длину строки
    const char *ptr_str();     // получить указатель на строку

    // операции над строками
    char operator[](unsigned int pos); // оператор индекса, возврат символа на позиции
    String operator+(String &str);     // конкатенация строк
    // friend std::ostream &operator<<(std::ostream &out, String &str); // операция вывода строки в std::cout

    ~String(); // деструктор
};

// перегружаем оператор << как обычную функцию. Доступ к полям только через геттеры
std::ostream &operator<<(std::ostream &out, String &str);