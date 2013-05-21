#include <iostream>
#include "fstream"
#include "spiralPrinter.h"
#include "fileSpiralPrinter.h"
using namespace std;



void FileSpiralPrinter::print(int element)
{
    myfile << element << " ";
}


void FileSpiralPrinter::openFile()
{
    myfile.open ("output.txt");
}


