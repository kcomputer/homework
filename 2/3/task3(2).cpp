#include "stdafx.h"
#include <iostream>
using namespace std;
void printArray (int a[], int first, int last)
{
	for (int i = first; i < last; ++i)
	{
		cout << a[i] << "  ";
	}
	cout << endl;
};
void selectivePrint(int a[], int summ)
{
	int currentSumm = 0;
	int i = 0;
	while (currentSumm != summ)
	{
		currentSumm = currentSumm + a[i];
		if ((currentSumm != summ) && (a[i + 1] > a[i]))
		{
			return;
		}
		++i;
	}
	printArray(a, 0, i);
};
void printSums (int a[], int index, int summ)
{
	int currentMax = a[index];
	for (int i = 1; i < currentMax; ++i)
	{
		--a[index];
		a[index + 1] = i;
		selectivePrint (a, summ);
		printSums (a, index + 1, summ);
	}
}
int _tmain(int argc, _TCHAR* argv[])
{
	cout << "Enter integer n to print its sums\n";
	int n = 0;
	cin >> n;
	int array[200];
	for (int i = 1; i <= n;++i)
	{
		array[i] = 0;
	}
	int index = 0;
	array[index] = n;
	printSums (array, index, n);
	return 0;
}