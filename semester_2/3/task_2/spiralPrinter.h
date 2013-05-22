#ifndef SPIRALPRINTER_H
#define SPIRALPRINTER_H
#include "abstractSpiralPrinter.h"


class SpiralPrinter : public AbstractSpiralPrinter
{
public:
    void printer(int ** array, int size);
    virtual void print(int element) = 0;
};

#endif // SPIRALPRINTER_H
