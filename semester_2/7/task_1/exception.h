#ifndef EXEPTION_H
#define EXEPTION_H
#include <stdexcept>
#include <iostream>
using namespace std;

class Test
{
public:
    Test()
    {
        cout << "Constructor";
    }
    ~Test()
    {
        cout << "Destructor";
    }
    void callExeption()
    {
        throw invalid_argument("zzz");
    }
};

#endif // EXEPTION_H
