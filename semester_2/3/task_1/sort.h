#ifndef SORT_H
#define SORT_H



class Sort
{
public:
    virtual void makeSort(int *array, int length) = 0;
    static    void swap(int& a, int& b)
    {
        int i = a;
        a = b;
        b = i;
    }
};






#endif // SORT_H

