#include <iostream>
#include <cassert>
#include "func.h"
using namespace std;

int main()
{
    int arr[] = {1, 5, 8, 10, 15};
    int size = sizeof(arr) / sizeof(arr[0]);
    int new_arr[size + 1]; // т.к. добавляем один элемент

    // 1.
    insert(arr, size, 4, 1, new_arr);

    int arr_expected[] = {1, 4, 5, 8, 10, 15};

    for (int i = 0; i < 4; i++)
    {
        assert(arr_expected[i] == new_arr[i]);
    }

    // 2.
    assert(search_position(arr, size, 3) == 1);
    assert(search_position(arr, size, 16) == 5);
    assert(search_position(arr, size, 1) == 0);

    // 3.
    insert_sorted(arr, size, 7, new_arr);

    int arr_expected_1[] = {1, 5, 7, 8, 10, 15};

    size = sizeof(arr_expected_1) / sizeof(arr_expected_1[0]);
    for (int i = 0; i < size; i++)
    {
        assert(arr_expected_1[i] == new_arr[i]);
    }

    return 0;
}
