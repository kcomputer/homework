#ifndef BUBBLESORT_H
#define BUBBLESORT_H
#include "sort.h"


//! Interface for bubble sort.


class BubbleSort : public Sort

{
public :
    void makeSort(int **array, int n, int m);
};

#endif // BUBBLESORT_H
