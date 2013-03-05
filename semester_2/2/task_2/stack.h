#pragma once


class Stack
{
public:
    virtual void push(char val) = 0;
    virtual char top() = 0;
    virtual char pop() = 0;
	virtual void remove() = 0;
	virtual bool isEmpty() = 0;
    virtual int length() = 0;
};
