#include <omp.h>
#include <chrono>
#include "sort.h"

using namespace std;

int main()
{
 // long size[] = {10, 100, 1000, 1000000, 1000000000, 1000000000000}; // массив размеров массивов {1e01,1e02,1e03,1e06,1e019,1e12}
  long size[] = {10, 100, 1000, 100000};

  for (int i = 0; i != 5; ++i)
  {
    auto n = size[i];
    int arr1[n], arr2[n]; // создаём массивы размера из size[]

    fill_array_random(arr1, n, 0, 10000); // наполняем массив рандомными значениями
    for (int i = 0; i < n; i++)
    { // создаём arr2 как  копию массива arr1
      arr2[i] = arr1[i];
    }

    auto begin = chrono::high_resolution_clock::now(); // chrono::steady_clock::now();
    selection_sort(arr1, n);
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double, milli> elapsed_ms_ss = end - begin; // chrono::duration_cast<chrono::nanoseconds>(end - begin);

    begin = chrono::high_resolution_clock::now();
    quick_sort(arr2, 0, n - 1);
    end = chrono::high_resolution_clock::now();
    chrono::duration<double, milli> elapsed_ms_qs = end - begin;

    // Вывод в формате 1e01: xx (ss), xx (qs), где xx — время, ss — selection sort, qs — quick sort
    cout << n << ": " << elapsed_ms_ss.count() << " (ss), "
                     << elapsed_ms_qs.count() << " (qs)" << endl;
  }
  return 0;
}