#ifndef FILESPIRALPRINTER_H
#define FILESPIRALPRINTER_H
#include "spiralPrinter.h"
#include <iostream>
#include <fstream>
using namespace std;


class FileSpiralPrinter : public SpiralPrinter
{
public:
    void print(int element);
private:
    ofstream myfile;
    void openFile();
};

#endif // FILESPIRALPRINTER_H
