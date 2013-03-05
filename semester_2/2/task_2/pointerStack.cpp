#include "pointerStack.h"
#include <stdio.h>
PointerStack::PointerStack()
{
    next = NULL;
    value = 0;
}

PointerStack::~PointerStack()
{
    delete next;
}

void PointerStack::push(char val)
{
    PointerStack* temp = new PointerStack;
    temp->value = val;
    if (!next)
        next = temp;
    else
    {
        temp->next = next;
        next = temp;
    }
}

char PointerStack::pop()
{
   int toReturn = 0;
   if (next)
	{
		toReturn = next->value;
		PointerStack* temp = next;
		next = temp->next;
		temp->next = NULL;
		delete temp;
	}
   return toReturn;
}

char PointerStack::top()
{
   return next->value;
}

void PointerStack::remove()
{
	if (next)
	{
		PointerStack* temp = next;
		temp->next = temp->next->next;
        temp->next = NULL;
		delete temp;
	}
}

bool PointerStack:: isEmpty() 
{
	return next;
}


int PointerStack::length()
{
    int length = 0;
    PointerStack* temp = next;
    while (temp)
    {
        length++;
        temp = temp->next;
    }
    return length;
}