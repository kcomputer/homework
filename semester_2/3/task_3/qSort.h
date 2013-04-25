#ifndef QSORT_H
#define QSORT_H
#include "sort.h"

//! Interface for quick sort.

class QuickSort : public Sort
{
public:
    void makeSort(int **array, int n, int m);
};

#endif // QSORT_H
