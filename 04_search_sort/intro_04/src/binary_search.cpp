int binary_search(int arr[], int l, int r, int x)
{
    if (r >= l)
    {
        int mid = l + (r - l) / 2;

        // Проверяем
        if (arr[mid] == x)
            return mid;

        // Идём в левую часть
        if (arr[mid] > x)
            return binary_search(arr, l, mid - 1, x);

        // Идём в правую часть
        return binary_search(arr, mid + 1, r, x);
    }

    return -1;
}