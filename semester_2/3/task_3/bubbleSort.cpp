#include "bubbleSort.h"
#include "sort.h"



void BubbleSort::makeSort(int **array, int n, int m)
{
    for (int k = 0; k < m - 1; ++k)
    {
        for (int q = k+1; q < m; ++q)
        {
            if (array[0][k] > array[0][q])
            {
                Sort::swapColumns(array, k, q, n);
            }
        }
    }
}

