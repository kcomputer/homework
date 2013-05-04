#ifndef CALCULATIONTREE_H
#define CALCULATIONTREE_H

#include "iostream"
#include <string>

using namespace std;

//! Calculator Tree Interface

class CalcTree
{
public:
    //! Calculates expression
    /*!
      \return result.
    */
    virtual int result () = 0;

    //! Prints expression.
    virtual void print() = 0;

    virtual ~CalcTree() {}
};

//! Leaf Class

class Leaf : public CalcTree
{
public:
    Leaf(string& s)
    {
        val = s[0] - '0';
        s.erase(0, 1);
    }
    int result ()
    {
        return val;
    }
    void print ()
    {
        cout << ' ' << val;
    }

private:
    int val;
};

//! Operation class.

class Operation : public CalcTree
{
public:
    Operation (string& s);
    ~Operation ();
    int result ();
    void print ();

    //! Builds a Calculator Subtree

    CalcTree* build(string& s);

private:
    char operation;
    CalcTree* left;
    CalcTree* right;
};

#endif // CALCULATIONTREE_H
