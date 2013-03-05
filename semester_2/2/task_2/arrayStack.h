#pragma once
#include "stack.h"


class ArrayStack : public Stack
{
public:
    ArrayStack();
    void push(char val);
	char top();
	char pop();
	bool isEmpty(); 
    void remove();
    int length();
    ~ArrayStack();
private:
   static const int size = 1000;
   int lengthi;
   char buff[size];
};




