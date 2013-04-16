#include "bubbleSort.h"
#include "sort.h"



void BubbleSort::makeSort(int *array, int length)
{
    for (int k = 0; k < length - 1; ++k)
    {
        for (int q = k+1; q < length; ++q)
        {
            if (array[k] > array[q])
            {
                Sort::swap (array[k], array[q]);
            }
        }
    }
}

