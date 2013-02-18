#include <iostream>
using namespace std;
void QuickSort (int arrayToSort[],int leftBound, int rightBound)
{
	int i = leftBound;
	int j = rightBound;
	int midle = arrayToSort[(leftBound + rightBound) / 2];
	do
	{
		while (arrayToSort[i] < midle)
		{
			++i;
		}
		while (arrayToSort[j] > midle)
		{
			--j;
		}
		if (i <= j)
		{
			int temp = arrayToSort[i];
			arrayToSort[i] = arrayToSort[j];
			arrayToSort[j] = temp;
			++i;
			--j;
		}
	}
		while (i < j);
		if (leftBound < j) 
		{
			QuickSort(arrayToSort, leftBound, j);
		}
		if (rightBound > i) 
		{
			QuickSort(arrayToSort, i, rightBound);
		}
	}
int main()
{
	cout << "Please enter the length of array\n";
	int length = 0;
	cin >> length;
	cout << "And now enter array to sort\n";
	int array[100];
	for (int i = 1; i <= length; ++i)
	{
		cin >> array[i];
	}
	QuickSort (array, 1, length);
	for (int i = 1; i <= length;++i)
	{
		cout << array[i] << " ";
	}
	return 0;
}

