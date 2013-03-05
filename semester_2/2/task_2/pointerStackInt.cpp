#include "pointerStackInt.h"
#include <stdio.h>
PointerStackInt::PointerStackInt()
{
    next = NULL;
    value = 0;
}

PointerStackInt::~PointerStackInt()
{
    delete next;
}

void PointerStackInt::push(int val)
{
    PointerStackInt* temp = new PointerStackInt();
    temp->value = val;
    if (!next)
        next = temp;
    else
    {
        temp->next = next;
        next = temp;
    }
}

int PointerStackInt::pop()
{
   int toReturn = 0;
   if (next)
	{
		toReturn = next->value;
		PointerStackInt* temp = next;
		next = temp->next;
		temp->next = NULL;
		delete temp;
	}
   return toReturn;
}

int PointerStackInt::top()
{
   return next->value;
}

void PointerStackInt::remove()
{
	if (next)
	{
		PointerStackInt* temp = next;
		temp->next = temp->next->next;
        temp->next = NULL;
		delete temp;
	}
}

bool PointerStackInt:: isEmpty() 
{
	return next;
}


int PointerStackInt::length()
{
    int length = 0;
    PointerStackInt* temp = next;
    while (temp)
    {
        length++;
        temp = temp->next;
    }
    return length;
}