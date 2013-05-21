#ifndef SORT_H
#define SORT_H


#include "comparer.h"

template <class T>
class Sort
{
public:
    //! Sort elements of an array
    void makeSort(T *array, int length, Comparer<T> compare);

    //! Swap two elements
    void swap(T& a, T& b);
};

template <class T>
void Sort<T>::swap(T& a, T& b)
   {
       T temp = a;
       a = b;
       b = temp;
   }

template <class T>
void Sort<T>::makeSort(T *array, int length, Comparer<T> compare)
{
    for (int k = 0; k < length - 1; ++k)
    {
        for (int q = k+1; q < length; ++q)
        {
            if (compare(array[k],array[q]))
            {
                Sort::swap (array[k], array[q]);
            }
        }
    }
}
#endif // SORT_H
