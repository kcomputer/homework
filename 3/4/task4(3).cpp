#include <iostream>
using namespace std;
void printFilter (int value, int currentDegree, bool wasThereFirst)
{
	if (abs(value) == 1)
	{
		if (value > 0)
		{
			if (!wasThereFirst)
			{
				cout << "x";
			}
			else
			{
				cout << "+x";
			}
		}
		else
		{
			cout << "-x";
		}
	}
	else
	{
		if (value > 0)
		{
			if (!wasThereFirst)
			{
				cout << value << "x";
			}
			else
			{
				cout << "+" << value << "x";
			}
		}
		else
		{
			cout << value << "x";
		}
	}
	if (currentDegree != 1)
	{
		int temp = 10 * currentDegree;
		while ((temp = temp / 10) != 0)
		{
			cout << " ";
		}
	}
}
int main()
{
	cout << "Enter maximum degree and coefficients.\n";
	int maxDegree = 0;
	cin >> maxDegree;
	int array[100];
	for (int i = 1; i <= 1 + maxDegree; ++i)
	{
		cin >> array[i];
	}
	int currentDegree = maxDegree;
	bool wasThereFirst = false;
	for (int i = 1; i < 1 + maxDegree; ++i)
	{
		if(array[i] != 0)
		{
			int temp = 10 * array[i];
			if (abs(array[i]) != 1)
			{
				while ((temp = temp / 10) != 0)
				{
					cout << " ";
				}	
			}
			if ((array[i] < 0) && (!wasThereFirst))
			{
				cout << " ";
			}
			if (currentDegree > 1)
			{
				cout << " " << currentDegree << " ";
			}
			 wasThereFirst = true;
		}
		--currentDegree;
	}
	cout << endl;
	wasThereFirst = false;
	currentDegree = maxDegree;
	for (int i = 1; i < 1 + maxDegree; ++i)
	{
		if (array[i] != 0)
		{
			printFilter(array[i], currentDegree, wasThereFirst);
			wasThereFirst = true;
		}
		--currentDegree;
	}
	if (array[maxDegree + 1] != 0)
	{
		if (array[maxDegree + 1] > 0)
		{
			cout << "+" << array[maxDegree + 1];
		}
		else
		{
			cout << array[maxDegree + 1];
		}
	}
	return 0;
}