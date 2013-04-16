#include <iostream>
#include "spiralPrinter.h"
#include "fileSpiralPrinter.h"
#include "consoleSpiralPrinter.h"


using namespace std;

int main()
{
    cout << "Enter N - size of 2d array.\n";
    int size = 0;
    cin >> size;


    int **array = new int *[size + 1];

    for (int i = 0; i <= size; i++)
    {
      array[i] = new int [size + 1];
    }
    cout << "And now enter 2d array:\n";
    for (int i = 1; i <= size; ++i)
    {
        for (int j = 1; j <= size; ++j)
        {
            cin >> array[i][j];
        }
    }


    cout << "Where do you want it to be printed?\n";
    cout << "1 - File.\n";
    cout << "2 - Console.\n";
    int kindaOut = 0;
    cin >> kindaOut;


    SpiralPrinter *spiral = NULL;
    switch (kindaOut)
    {
    case 1:
        spiral = new FileSpiralPrinter();
        spiral->print(array, size);
        break;
    case 2:
        spiral = new ConsoleSpiralPrinter();
        spiral->print(array, size);
        break;
    }


    for (int i = 0; i <= size; i++)
    {
        delete []array[i];
    }
    delete []array;


    return 0;
}
