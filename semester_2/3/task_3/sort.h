#ifndef SORT_H
#define SORT_H

//! Interface for sorter.
/*! Virtual sorter. */

class Sort
{
public:
    //! Sort array by first column elements.
    /*!
     \param array is an 2d array.
     \param n number of lines of 2d array.
     \param m number of columns of 2d array.
    */
    virtual void makeSort(int **array, int n, int m) = 0;
    //! Swap to columns.
    /*!
     \param array is an 2d array.
     \param n number of lines of 2d array.
     \param m number of columns of 2d array.
    */
    static void swapColumns(int **array, int a, int b, int n);

};






#endif // SORT_H

