#include "heapSort.h"
#include "sort.h"



void siftDown (int *a, int first, int last)
{
    int i = first;
    while (i <= last /2)
    {
        if (i * 2 == last)
        {
            if (a[i] < a[last])
            {
                Sort::swap (a[i], a[last]);
            }
                i = last;
        }
        else
        {
            if ((a[i] < a[i * 2]) && (a[i * 2] >= a[i * 2 + 1]))
            {
                Sort::swap (a[i], a[i * 2]);
                i = i * 2;
            }
            else
            {
                if  (((a[i] < a[i * 2]) && (a[i * 2] < a[i * 2 + 1])) || (a[i] < a[i * 2 + 1]) && (a[i * 2 + 1] > a[i * 2]))
                {
                    Sort::swap (a[i], a[i * 2 + 1]);
                    i = i * 2 + 1;
                }
                else
                {
                    i = last;
                }
            }
        }
    }
}
void heapSortHelper (int* a, int first, int last)
{
    for (int i = last / 2; i >= first; i--)
    {
        siftDown(a, i, last);
    }
    for (int i = last; i > first; i--)
    {
        Sort::swap (a[i], a[first]);
        siftDown (a, first, i - 1);
    }
}

void HeapSort :: makeSort(int *array, int length)
{
    for (int i = length; i >= 1; --i)
    {
        Sort::swap(array[i], array [i - 1]);
    }
    heapSortHelper(array, 1, length);
    for (int i = 0; i < length; ++i)
    {
        Sort::swap(array[i], array [i + 1]);
    }
}
