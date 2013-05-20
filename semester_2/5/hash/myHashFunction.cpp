#include "myHashFunction.h"



MyHashFunction :: MyHashFunction(const int length)
{
    arrayLength = length;
    degree = 1;
}

int MyHashFunction :: hash(string key)
{
    int j = 0;
    string::iterator i = key.begin();
    while (i < key.end())
    {
        j += realFunction( *i, j);
        i++;
    }
    degree = 1;
    j %= arrayLength;
    return j;
}


int MyHashFunction :: realFunction (char ch, int j)
{
    j = ((int (ch)) * degree) % arrayLength;
    degree *= 11;
    return j;
}
