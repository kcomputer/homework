#pragma once

//! Interface for stack.
/*! Virtual stack. */
class StackInt
{
public:


    //! Add integer to stack.
    /*!
     /param val is an integer argument.
    */
    virtual void push(int val) = 0;


    //! Return top element of stack.
    virtual int top() = 0;


     //! Return top element of stack and remove it.
    virtual int pop() = 0;


     //! Remove top element of stack.
	virtual void remove() = 0;


     //! Check if stack is empty.
	virtual bool isEmpty() = 0;


     //! Return length of stack.
    virtual int length() = 0;
};
