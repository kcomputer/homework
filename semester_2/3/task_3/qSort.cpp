#include "qSort.h"
#include "sort.h"






void qSortHelper (int **array, int low, int high, int n)
{
    int i = low;
    int j = high;
    int x = array[0][(low+high)/2];
    do
    {
        while(array[0][i] < x)
            ++i;
        while(array[0][j] > x)
            --j;
        if(i <= j)
        {
            Sort::swapColumns(array, i, j, n);
        }
        i++;
        j--;
    }
    while(i < j);
    if(low < j)
        qSortHelper(array, low, j, n);
    if(i < high)
        qSortHelper(array, i, high, n);

}

void QuickSort :: makeSort(int **array, int n, int m)
{
    qSortHelper(array, 0, m - 1, n);
}
