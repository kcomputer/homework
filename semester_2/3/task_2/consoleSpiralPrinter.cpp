#include <iostream>
#include "spiralPrinter.h"
#include "consoleSpiralPrinter.h"
using namespace std;

void ConsoleSpiralPrinter :: print(int** array, int size)
{
    int currentI = size /2;
    int currentJ = size /2;
    int currentBounds = 3;
    cout << array[size / 2 + 1][size / 2 + 1] << "  ";
    while (currentBounds <= size)
    {
        for (int i = 1; i < currentBounds; ++i)
        {
            ++currentI;
            cout << array [currentI][currentJ] << "  ";
        }
        for (int i = 1; i < currentBounds; ++i)
    {
        ++currentJ;
        cout << array [currentI][currentJ] << "  ";
    }
    for (int i = 1; i < currentBounds; ++i)
    {
        --currentI;
        cout << array [currentI][currentJ] << "  ";
    }
    for (int i = 1; i < currentBounds; ++i)
    {
        --currentJ;
        cout << array [currentI][currentJ] << "  ";
    }
    --currentJ;
    --currentI;
    currentBounds = currentBounds + 2;
}
}
