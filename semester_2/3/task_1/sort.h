#ifndef SORT_H
#define SORT_H

//! Virtual sorter interface.

class Sort
{
public:

    //! Sorts elements of an array
    virtual void makeSort(int *array, int length) = 0;

    //! Swap two elements.
    static    void swap(int& a, int& b)
    {
        int i = a;
        a = b;
        b = i;
    }
};






#endif // SORT_H

