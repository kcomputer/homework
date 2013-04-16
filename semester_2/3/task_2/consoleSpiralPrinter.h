#ifndef CONSOLESPIRALPRINTER_H
#define CONSOLESPIRALPRINTER_H
#include "spiralPrinter.h"


class ConsoleSpiralPrinter : public SpiralPrinter
{
public:
    void print(int ** array, int size);
};


#endif // CONSOLESPIRALPRINTER_H
