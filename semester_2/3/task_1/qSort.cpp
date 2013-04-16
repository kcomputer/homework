#include "qSort.h"
#include "sort.h"






void qSortHelper (int *array, int low, int high)
{
    int i = low;
    int j = high;
    int x = array[(low+high)/2];
    do
    {
        while(array[i] < x)
            ++i;
        while(array[j] > x)
            --j;
        if(i <= j)
        {
            Sort::swap(array[i], array[j]);
        }
        i++;
        j--;
    }
    while(i < j);
    if(low < j)
        qSortHelper(array, low, j);
    if(i < high)
        qSortHelper(array, i, high);

}

void QSort :: makeSort(int *array, int length)
{
    qSortHelper(array, 0, length - 1);
}
