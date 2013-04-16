#ifndef FILESPIRALPRINTER_H
#define FILESPIRALPRINTER_H
#include "spiralPrinter.h"


class FileSpiralPrinter : public SpiralPrinter
{
public:
    void print(int ** array, int size);
};

#endif // FILESPIRALPRINTER_H
