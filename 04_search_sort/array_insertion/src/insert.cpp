/*
    Вставка значения 'value' в позицию 'position' массива arr 
    Например, после вставки x=4 в позицию p=1 в массив {1,5,8} будет {1,4,5,8}  
*/
void insert(int arr[], int size, int value, int position, int new_arr[])
{
    for (int i = 0; i <= size; i++)
    {
        if (i == position)
        {
            new_arr[i] = value;
        }
        if (i < position)
        {
            new_arr[i] = arr[i];
        }
        if (i > position)
        {
            new_arr[i] = arr[i - 1];
        }
    }
}
