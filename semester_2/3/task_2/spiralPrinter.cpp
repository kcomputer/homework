#include "spiralPrinter.h"
#include "consoleSpiralPrinter.h"

void SpiralPrinter :: printer(int** array, int size)
{
    int currentI = size /2 - 1;
    int currentJ = size /2 - 1;
    int currentBounds = 2;
    print(array[size / 2][size / 2]);
    while (currentBounds <= size)
    {
        for (int i = 0; i < currentBounds; ++i)
        {
            ++currentI;
            print(array [currentI][currentJ]);
        }
        for (int i = 0; i < currentBounds; ++i)
    {
        ++currentJ;
        print(array [currentI][currentJ]);
    }
    for (int i = 0; i < currentBounds; ++i)
    {
        --currentI;
        print(array [currentI][currentJ]);
    }
    for (int i = 0; i < currentBounds; ++i)
    {
        --currentJ;
        print(array [currentI][currentJ]);
    }
    --currentJ;
    --currentI;
    currentBounds = currentBounds + 2;
    }
}
