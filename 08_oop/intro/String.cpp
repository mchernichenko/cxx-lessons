// Можно отделить часть «объявления» класса от его «реализации».
// Это делается путем определения функций-членов класса вне определения класса. 
// Для этого просто определите функции-члены класса, как если бы они были обычными функциями, 
// но добавив к функциям префикс из имени класса с помощью оператора разрешения области видимости (::)
// https://radioprog.ru/post/1227

#include <iostream>
#include <cstring>
#include "String.h"

// конструктор по умолчанию
String::String()
  {
    m_length = 0;
    m_str = new char[1];
    m_str[0] = '\0';
  }

  // конструктор
 String::String(const char *init)
  {
    m_length = strlen(init);
    m_str = new char[m_length + 1];
    strcpy(m_str, init);
  }

  // get длины
  unsigned int String::get_length()
  {
    return m_length;
  }

  // get указателя на строку
  const char *String::ptr_str()
  {
    return m_str;
  }

  // строки на позиции pos
  char String::operator[](unsigned int pos)
  {
    return m_str[pos];
  }

  // вывод в консоль
  std::ostream &operator<<(std::ostream &out, String &str)
  {
    out << str.ptr_str();
    return out;
  }

  // конкатенация строк
  String String::operator+(String &str)
  {
    auto newString = (char *)malloc(m_length + str.m_length); // Функция malloc() возвращает адрес на первый байт области памяти размером size байт, кото­рая была выделена из кучи
    int i, size = m_length + str.m_length;
    int thisLength = this->m_length, strLength = str.m_length;

    for (i = 0; i < thisLength; i++)
      newString[i] = str[i];

    for (int j = 0; j < strLength; i++, j++)
      newString[i] = str[j];

    newString[thisLength + strLength] = '\0';
    return newString;
  }

  // деструктор
 String::~String()
  {
    delete[] m_str;
  }
