#include "arrayStack.h"

ArrayStack::ArrayStack()
{
    lengthi = 0;
}

void swap(char* am, char* bm)
{
    char im = *am;
    *am = *bm;
    *bm = im;
}

void ArrayStack::push(char val)
{
    if (length() < size)
    {
		buff[length()] = val;
        lengthi++;
    }
}

char ArrayStack::pop()
{
	char temp = buff[length()-1];
	lengthi--;
	return temp;
}

char ArrayStack::top()
{
	return buff[length()-1];
}

void ArrayStack::remove()
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

bool ArrayStack::isEmpty() 
{
	return length();
}

int ArrayStack::length()
{
    return lengthi;
}