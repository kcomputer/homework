#pragma once


class List
{
public:
    virtual void add(int val) = 0;
    virtual void remove(int val) = 0;
    virtual bool isIn(int val) = 0;
    virtual int length() = 0;
};
