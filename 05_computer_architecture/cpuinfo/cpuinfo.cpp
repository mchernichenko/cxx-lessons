#include <chrono>
#include <fstream>
#include <iostream>
#include <thread>

/*
   Чтение строки из /proc/stat, имеющей формат: cpu  669992823 69963647 341652106 64211934534 34415383 0 8102966 0 0 0
   Итого 10 числовых параметров
   Числа обозначают общее время, проведённое процессором в разных состояниях. 
   Четвёртое число обозначает время процессора без вычислений (состояние IDLE).
*/
void get_cpuinfo(unsigned long long int fields[])
{
  char line[3];
  std::ifstream in("/proc/stat", std::ios_base::in);
  in >> line;
  for (int i = 0; i != 10; ++i)
  {
    if (in.is_open())
    {
      in >> fields[i];
    }
    else
    {
      exit(0);
    }
  }
}

/*
  Расчёт загрузки процессора в % по данным из /proc/stat
  Алгоритм: т.к. в /proc/stat общее время с начала работы, то текущую нагрузку вычисляем за определённый промежутов времени, например, за последнюю секунду
  Итого, каждую секунду снимаем показатели параметров и вычисляем: (время загрузки без простоя за последнюю сек.)/(общее время за последнюю сек.) * 100
*/  

int main()
{
  unsigned long long int fields[10], total_tick, total_tick_old, idle, idle_old,
      del_total_tick, del_idle;
  double percent_usage;

  get_cpuinfo(fields);

  total_tick = 0;
  for (int i = 0; i < 10; i++)
  {
    total_tick += fields[i];
  }
  idle = fields[3];  // Четвёртое число обозначает время процессора без вычислений 

  while (true)
  {
    std::chrono::milliseconds timespan(1000); 
    std::this_thread::sleep_for(timespan);  // секундная задержка

    total_tick_old = total_tick;
    idle_old = idle;

    get_cpuinfo(fields);

    total_tick = 0;
    for (int i = 0; i < 10; i++)
    {
      total_tick += fields[i];
    }
    idle = fields[3];

    del_total_tick = total_tick - total_tick_old;
    del_idle = idle - idle_old;

    percent_usage = ((del_total_tick - del_idle) / del_total_tick) * 100;
    printf("Общаа загрузка CPU: %3.2lf%%\n", percent_usage);  // вывод загрузки процессора в % по данным из /proc/stat 
  }

  return 0;
}