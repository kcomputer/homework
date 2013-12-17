#include "counter.h"

int Counter::count(int *array, int length)
{
    int valueToReturn = 0;
    for (int i = 0; i < length; i++)
    {
        if (array[i] == 0)
        {
            ++valueToReturn;
        }
    }

    return valueToReturn;
}
