#include <iostream>
#include "spiralPrinter.h"
#include "consoleSpiralPrinter.h"
using namespace std;

void SpiralPrinter :: printer(int** array, int size)
{
    int currentI = size /2;
    int currentJ = size /2;
    int currentBounds = 3;
    print(array[size / 2 + 1][size / 2 + 1]);
    while (currentBounds <= size)
    {
        for (int i = 1; i < currentBounds; ++i)
        {
            ++currentI;
            print(array [currentI][currentJ]);
        }
        for (int i = 1; i < currentBounds; ++i)
    {
        ++currentJ;
        print(array [currentI][currentJ]);
    }
    for (int i = 1; i < currentBounds; ++i)
    {
        --currentI;
        print(array [currentI][currentJ]);
    }
    for (int i = 1; i < currentBounds; ++i)
    {
        --currentJ;
        print(array [currentI][currentJ]);
    }
    --currentJ;
    --currentI;
    currentBounds = currentBounds + 2;
    }
}

