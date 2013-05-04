#include "calculationTree.h"


Operation::Operation (string& s)
{
    if (s.begin() != s.end())
    {
        operation = s[1];
        s.erase(0, 2);
        left = build(s);
        right = build(s);
        while (s[0] == ' ')
            s.erase(0, 1);
        s.erase(0, 1);
    }
}


Operation::~Operation ()
{
    delete left;
    delete right;
}


CalcTree* Operation::build(string& s)
{
    while (s[0] == ' ')
        s.erase(0, 1);
    if (s.begin() != s.end())
    {
        CalcTree* tmp = 0;
        if (s[0] == '(')
                tmp = new Operation(s);
        else
                tmp = new Leaf(s);
        return tmp;
    }
    return NULL;
}


int Operation::result()
{
    switch (operation)
    {
        case '+':
            return left->result() + right->result();
            break;
        case '-':
            return left->result() - right->result();
            break;
        case '*':
            return left->result() * right->result();
            break;
        case '/':
            return left->result() / right->result();
            break;
    }
}

void Operation::print()
{
    cout << '(' << operation;
    left->print();
    right->print();
    cout << ')';
}
