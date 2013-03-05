#pragma once
#include "stackInt.h"

class PointerStackInt : public StackInt
{
public:
    PointerStackInt();
    void push(int val);
	int top();
	int pop();
    void remove();
    int length();
	bool isEmpty();
    ~PointerStackInt();
private:
    PointerStackInt* next;
    int value;
};

