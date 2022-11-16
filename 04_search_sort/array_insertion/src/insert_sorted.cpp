#include "func.h"

/* 
    Вставка значение 'x' в упорядоченный массив 'arr' так, чтобы не нарушить порядок 
*/
void insert_sorted(int arr[], int size, int x, int new_arr[])
{
    insert(arr, size, x, search_position(arr, size, x), new_arr);
}