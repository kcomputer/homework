#include "sort.h"


static void swap(int& a, int& b)
{
    int i = a;
    a = b;
    b = i;
}


void Sort::swapColumns(int **array, int a, int b, int n)
{
    for (int i = 0; i < n; ++i)
    {
        swap(array[i][a], array[i][b]);
    }
}
