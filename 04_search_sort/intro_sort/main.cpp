#include <random>
#include <iostream>
using namespace std;

void fill_array_random(int arr[], int n, int a, int b)
{
    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type> dist(a, b);

    for (int i = 0; i < n; ++i)
    {
        arr[i] = dist(rng);
    }
}

/*
    Функция печати массива в виде {a, b, c, d, e, f}, где буквы обозначают элементы массива
    Если show_index равен true, то функция выводит массив с индексами: {0: a, 1: b, 2: c, 3: d, 4: e, 5: f}
*/
void print_array(int arr[], int n, bool show_index = false)
{
    cout << "{";
    for (int i = 0; i < n; ++i)
    {
        if (show_index) {
            cout << i << ": ";
        }
        cout << arr[i];

        if (i + 1 != n) {
            std::cout << ", "; // в последнем элементе ',' не ставится
        }
    }
    cout << "}" << endl;
}

int main()
{
    int arr[10];
    int n = sizeof(arr) / sizeof(arr[0]);
    fill_array_random(arr, n, 0, 100);
    print_array(arr, n);
    return 0;
}
