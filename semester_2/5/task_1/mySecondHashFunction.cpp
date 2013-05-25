#include "mySecondHashFunction.h"


MySecondHashFunction :: MySecondHashFunction(const int length)
{
    arrayLength = length;
    degree = 1;
}

int MySecondHashFunction :: hash(string key)
{
    int j = 0;
    string::iterator i = key.end();
    i--;
    while (i >= key.end())
    {
        j += realFunction( *i, j);
        i++;
    }
    degree = 1;
    j %= arrayLength;
    return j;
}


int MySecondHashFunction :: realFunction (char ch, int j)
{
    j = ((int (ch)) * degree) % arrayLength;
    degree *= 11;
    return j;
}

