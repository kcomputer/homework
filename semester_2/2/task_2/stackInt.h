#pragma once


class StackInt
{
public:
    virtual void push(int val) = 0;
    virtual int top() = 0;
    virtual int pop() = 0;
	virtual void remove() = 0;
	virtual bool isEmpty() = 0;
    virtual int length() = 0;
};
