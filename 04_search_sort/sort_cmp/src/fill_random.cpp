#include "sort.h"

void fill_array_random(int arr[], int n, int a, int b)
{
    random_device dev;
    mt19937 rng(dev());
    uniform_int_distribution<mt19937::result_type> dist(a,b);
    
    for(int i=0; i<n; i++)
    {
        arr[i] = dist(rng);
    }
}