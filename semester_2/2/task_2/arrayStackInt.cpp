#include "arrayStackInt.h"

ArrayStackInt::ArrayStackInt()
{
    lengthi = 0;
}

void swap(int* am, int* bm)
{
    char im = *am;
    *am = *bm;
    *bm = im;
}

void ArrayStackInt::push(int val)
{
    if (length() < size)
    {
		buff[length()] = val;
        lengthi++;
    }
}

int ArrayStackInt::pop()
{
	int temp = buff[length()-1];
	int i = 0;
	lengthi--;
	return temp;
}

int ArrayStackInt::top()
{
	return buff[length()-1];
}

void ArrayStackInt::remove()
{
    int i = 0;
    if (i == length())
        return;
    while (i < length())
    {
        swap (&buff[i], &buff[i+1]);
        i++;
    }
    lengthi--;
}

bool ArrayStackInt::isEmpty() 
{
	return length();
}

int ArrayStackInt::length()
{
    return lengthi;
}