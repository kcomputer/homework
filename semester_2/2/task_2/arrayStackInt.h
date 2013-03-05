#pragma once
#include "stackInt.h"


class ArrayStackInt : public StackInt
{
public:
    ArrayStackInt();
    void push(int val);
	int top();
	int pop();
	bool isEmpty(); 
    void remove();
    int length();
    ~ArrayStackInt();
private:
   static const int size = 1000;
   int lengthi;
   int buff[size];
};




