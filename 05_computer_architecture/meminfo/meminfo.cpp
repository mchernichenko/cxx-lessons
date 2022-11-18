#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

void show_meminfo()
{
  char parameter[20];
  int value;
  char unit[3];
  int total, free, avail; // под значения параметров
  const int PALKI_TOTAL = 10;

  ifstream in("/proc/meminfo", ios_base::in); // чтение файла /proc/meminfo в режиме чтения
  if (in.is_open())
  {
    in >> parameter >> total >> unit; // чтение 1-й строки файла: MemTotal: 12985584 kB
    in >> parameter >> free >> unit;  // чтение 2-й строки файла: MemFree: 8349188 kB
    in >> parameter >> avail >> unit; // чтение 3-й строки файла: MemAvailable: 10886396 kB
  }
  else
  {
    exit(1);
  }

  double busy_percent = (total - avail) / total * 100; // % заятого места
  int palki_count = round(busy_percent / PALKI_TOTAL);  // расчёт кол-ва палок. при 100% должно быть 10 палок

  // Красивый вывод, например, |||||||...  70%
  for (int i = 0; i != palki_count; ++i) {
     cout << "|";
  }
   
  for (int i = 0; i != PALKI_TOTAL - palki_count; ++i) {
    cout << ".";
  }
    
  cout << " " << busy_percent << "%" << endl;
}

int main()
{
  show_meminfo();
  return 0;
}