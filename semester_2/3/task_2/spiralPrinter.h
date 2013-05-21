#ifndef SPIRALPRINTER_H
#define SPIRALPRINTER_H
#include "abstractSpiralPrinter.h"


class SpiralPrinter : public AbstractSpiralPrinter
{
public:
    void printer(int ** array, int size);
    void print(int element);

};

#endif // SPIRALPRINTER_H
