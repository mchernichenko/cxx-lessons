## Задание
1. Создайте в своём репозитории `2022-polytech-%фамилия%` директорию `05_computer_architecture/meminfo`
2. Настройте cmake-проект
3. Соберите программу, которая представлена ниже (для linux систем, проверить работу можно по [ссылке](https://onlinegdb.com/yKoEPFsER))
```cpp
#include <iostream>
#include <fstream>

void show_meminfo()
{
    char parameter[20];
    int value;
    char unit[3];
    
    std::ifstream in("/proc/meminfo", std::ios_base::in);
    while(in.good())
    {
        in >> parameter >> value >> unit;
        std::cout << parameter << " " << value << unit << std::endl;
    }
}

int main()
{
  show_meminfo();
  return 0;
}
```
4. Прочитайте про работу с `ifstream`, `/proc` и `/proc/meminfo`
5. Измените программу так, чтобы она выводила размер занимаемой памяти в компьютере в ASCII-графике (пример ниже)
```
..........   0%
|||||.....  50%
|||||||...  70%
|||||||||| 100%
```
7. Отправьте решение на GitHub