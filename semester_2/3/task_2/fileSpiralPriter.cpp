#include <iostream>
//#include <fstream>
#include "fstream"
#include "spiralPrinter.h"
#include "fileSpiralPrinter.h"
using namespace std;

void FileSpiralPrinter :: print(int** array, int size)
{
  ofstream myfile;
  myfile.open ("output.txt");
  int currentI = size /2;
  int currentJ = size /2;
  int currentBounds = 3;
  myfile << array[size / 2 + 1][size / 2 + 1] << "  ";
  while (currentBounds <= size)
  {
      for (int i = 1; i < currentBounds; ++i)
      {
          ++currentI;
          myfile << array [currentI][currentJ] << "  ";
      }
      for (int i = 1; i < currentBounds; ++i)
      {
          ++currentJ;
          myfile << array [currentI][currentJ] << "  ";
      }
      for (int i = 1; i < currentBounds; ++i)
      {
          --currentI;
          myfile << array [currentI][currentJ] << "  ";
      }
      for (int i = 1; i < currentBounds; ++i)
      {
          --currentJ;
          myfile << array [currentI][currentJ] << "  ";
      }
      --currentJ;
      --currentI;
      currentBounds = currentBounds + 2;
  }
  myfile.close();
}

