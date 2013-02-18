#include <iostream>
using namespace std;

void swap(int &a, int &b)
{
	int x = a;
	a = b;
	b = x;
}

int main()
{
	cout << "Enter elements to sort, enter CTRL+Z if you finish:\n";
	int arrayToSort[200];
	int temp = 0;
	int i = 0;
	while (!cin.eof())
	{
		++i;
		cin >> arrayToSort[i];
	}
	--i;
	for (int k = 1; k <= i-1; ++k)
	{
		for (int q = k+1; q <= i; ++q)
		{
			if (arrayToSort[k] < arrayToSort[q])
			{
				swap (arrayToSort[k], arrayToSort[q]);
			}
		}
	}
	cout << "Sorted array:\n";
	for (int q = 1; q <= i; ++q)
	{ 
		cout << arrayToSort[q] << "  ";
	}
	return 0;
}