#ifndef ABSTRACTSPIRALPRINTER_H
#define ABSTRACTSPIRALPRINTER_H

#include "sstream"
using namespace std;

class AbstractSpiralPrinter
{
public:
    virtual void printer(int ** array, int size) = 0;
    virtual void print(int element) = 0;
    static stringstream outString;

};


#endif // ABSTRACTSPIRALPRINTER_H
