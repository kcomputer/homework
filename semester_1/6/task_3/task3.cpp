#include <iostream>
using namespace std;
void quickSort (int arrayToSort[],int leftBound, int rightBound)
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
			quickSort(arrayToSort, leftBound, j);
		}
		if (rightBound > i) 
		{
			quickSort(arrayToSort, i, rightBound);
		}
}


int factorial(int n) 
{
      return !n ? 1 : n * factorial(n - 1);
}


int findMaxDecreasing(int arrayTransposition[],int n)
{
	int i = n;
	bool isLess = false;
	while ((!isLess) && (i > 1))
	{
		if (arrayTransposition[i-1] < arrayTransposition[i])
		{
			isLess = true;
		}
		--i;
	}
	return i + 1;
}


int findMin(int arrayTransposition[], int beginSequence, int n, int indexTwo)
{
	int i = beginSequence;
	int minElement = arrayTransposition[beginSequence];
	int indexMin = beginSequence;
	while (i <= n)
	{
		if ((arrayTransposition[i] < minElement) && (arrayTransposition[indexTwo] > minElement))
		{
			minElement = minElement;
			indexMin = i;
		}
		++i;
	}
	return indexMin;
}


void printArray(int arrayTransposition[], int n)
{
	for (int i = 1; i <= n; ++i)
	{
		cout << arrayTransposition[i] << "  ";
	}
	cout << endl;
}


int main()
{
	cout << "Please enter the n:\n";
	int n = 0;
	cin >> n;
	int *arrayTransposition = new int[n + 1];
	for (int i = 1; i <= n; ++i)
	{
		arrayTransposition[i] = i;
	}
	int beginSequence = 0;
	int indexOne = 0;
	int indexTwo = 0;
	printArray(arrayTransposition, n);
	for (int i = 1; i < factorial(n); ++i)
	{
		beginSequence = findMaxDecreasing(arrayTransposition, n);
		indexTwo = beginSequence - 1;
		indexOne = findMin(arrayTransposition, beginSequence, n, indexTwo);
		swap(arrayTransposition[indexOne], arrayTransposition[indexTwo]);
		quickSort(arrayTransposition, beginSequence, n);
		printArray(arrayTransposition, n);
	}
	delete[] arrayTransposition ;
	return 0;
}

