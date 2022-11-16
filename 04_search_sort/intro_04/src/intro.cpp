#include <iostream>
#include <chrono>
#include "search.h"
using namespace std;

int main()
{
    int arr[] = {-996, -960, -944, -887, -865, -860, -846, -831, -790, -785, -700, -691, -662, -662, -647,
                 -640, -587, -532, -524, -519, -501, -497, -475, -471, -461, -457, -452, -442, -441, -416,
                 -412, -411, -390, -389, -358, -341, -306, -257, -253, -252, -248, -208, -143, -134, -82,
                 -79, -11, 21, 26, 48, 68, 69, 72, 93, 95, 99, 115, 120, 156, 164, 181, 200, 231, 252, 288,
                 304, 336, 343, 364, 402, 419, 486, 546, 584, 595, 596, 606, 627, 636, 666, 666, 683, 701,
                 740, 766, 780, 782, 794, 802, 829, 832, 837, 858, 875, 881, 882, 883, 883, 947, 959};
    int x = 120;
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Линейный поиск элемента " << x << endl;
    auto begin = chrono::steady_clock::now(); //Текущее время перед выполнением функции
    int result = linear_search(arr, n, x);
    auto end = chrono::steady_clock::now(); //Текущее время после выполнения функции
    if (result == -1)
    {
        cout << "Элемент не найден " << endl;
    }
    else
    {
        cout << "Элемент найден в индексе " << result << endl;
    }
    auto elapsed_ms = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin); //Потраченное время на выполнение функции
    cout << "Время выполнения линейного пойска " << elapsed_ms.count() << " nanoc\n";        //Вывод потраченного времени

    cout << "Бинарный поиск элемента " << x << endl;
    begin = chrono::steady_clock::now();
    result = binary_search(arr, 0, n - 1, x);
    end = chrono::steady_clock::now();
    if (result == -1)
    {
        cout << "Элемент не найден " << endl;
    }
    else
    {
        cout << "Элемент найден в индексе " << result << endl;
    }
    elapsed_ms = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin); 
    cout << "Время выполнения линейного пойска " << elapsed_ms.count() << " nanoc\n";
    return 0;
}