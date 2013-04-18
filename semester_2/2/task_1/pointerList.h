#pragma once
#include "list.h"

//! List on pointers.

class PointerList : public List
{
public:
    PointerList();
    void add(int val);
    void remove(int val);
    bool isIn(int val);
    int length();
    ~PointerList();
private:
    PointerList* next;
    int  value;
};

