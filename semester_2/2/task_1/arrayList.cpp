#include "arrayList.h"

ArrayList::ArrayList()
{
    lengthi = 0;
}

void swap(int* am, int* bm)
{
    int im = *am;
    *am = *bm;
    *bm = im;
}

void ArrayList::add(int val)
{
    if (length() < size)
    {
        buff[length()] = val;
        lengthi++;
    }
}

void ArrayList::remove(int val)
{
    int i = 0;
    while (i < length() && val != buff[i])
    {
        i++;
    }
    if (i == length())
        return;
    while (i < length())
    {
        swap (&buff[i], &buff[i+1]);
        i++;
    }
    lengthi--;
}

bool ArrayList::isIn(int val)
{
    for (int i = 0; i < length(); i++)
        if (buff[i] == val)
            return true;
    return false;
}

int ArrayList::length()
{
    return lengthi;
}
