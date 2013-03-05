#pragma once
#include "stack.h"

class PointerStack : public Stack
{
public:
    PointerStack();
    void push(char val);
	char top();
	char pop();
    void remove();
    int length();
	bool isEmpty();
    ~PointerStack();
private:
    PointerStack* next;
    char value;
};

