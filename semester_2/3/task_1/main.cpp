#include "sort.h"
#include "bubbleSort.h"
#include "heapSort.h"
#include "qSort.h"
#include <iostream>

using namespace std;
int main()
{
    cout << "Please enter the length of an array:\n";
    int length = 0;
    cin >> length;
    cout << "And now enter the array to sort:\n";
    int *array = new int[length + 1];
    for (int i = 0; i < length; ++i)
    {
        cin >> array[i];
    }
    cout << "Choose the way what it will be sorted:\n";
    cout << "1 - Quick Sort.\n";
    cout << "2 - Bubble Sort.\n";
    cout << "3 - Heap Sort.\n";
    int kindaSort = 0;
    cin >> kindaSort;
    Sort *sorter = NULL;
    switch (kindaSort)
    {
    case 1:
        sorter = new QSort();
        sorter->makeSort(array, length);
        break;
    case 2:
       sorter = new BubbleSort();
       sorter->makeSort(array, length);
       break;
    case 3:
        sorter = new HeapSort();
        sorter->makeSort(array, length);
        break;
    }
    for (int i = 0; i < length; ++i)
    {
        cout << array[i] << "  ";
    }
    delete (array);
    return 0;
}
