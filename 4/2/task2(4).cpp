#include <iostream>
using namespace std;

int main()
{
	cout << "Enter N - size of 2d array.\n";
	int size = 0;
	cin >> size;
	int array [100][100];
	cout << "And now enter 2d array, this program will print it spirally.\n";
	for (int i = 1; i <= size; ++i)
	{
		for (int j = 1; j <= size; ++j)
		{
			cin >> array[i][j];
		}
	}
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
	return 0;
}