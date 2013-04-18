#include "PointerList.h"
#include <stdio.h>
PointerList::PointerList()
{
    next = NULL;
    value = 0;
}

PointerList::~PointerList()
{
    delete next;
}

void PointerList::add(int val)
{
    PointerList* temp = new PointerList;
    temp->value = val;
    if (!next)
        next = temp;
    else
    {
        temp->next = next;
        next = temp;
    }
}

void PointerList::remove(int val)
{
    PointerList* temp = next;
    while(temp->next && temp->next->value != val)
        temp = temp->next;
    if (temp->next && temp->next->value == val)
    {
        PointerList* tmp = temp->next;
        temp->next = temp->next->next;
        tmp->next = NULL;
        delete tmp;
    }
}

bool PointerList::isIn(int val)
{
    PointerList* temp = next;
    while (temp)
    {
        if (temp->value == val)
            return true;
        temp = temp->next;
    }
    return false;
}

int PointerList::length()
{
    int length = 0;
    PointerList* temp = next;
    while (temp)
    {
        length++;
        temp = temp->next;
    }
    return length;
}
