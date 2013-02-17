#include <iostream>
using namespace std;
void readArray (int a[], int first, int last)
{
	for (int i = first; i <= last; ++i)
	{
		cin >> a[i];
	}
};
void printArray (int a[], int first, int last)
{
	for (int i = first; i <= last; ++i)
	{
		cout << a[i]<< "  ";
	}
};
void swap (int * a, int * b)
{
	int temp = 0;
	temp = *a;
	*a = *b;
	*b = temp;
}
void siftDown (int a[], int first, int last)
{
	int i = first;
	while (i <= last /2)
	{
		if (i * 2 == last)
		{
			if (a[i] > a[last])
			{
				swap (&a[i], &a[last]);
			}
				i = last;
		}
		else
		{
			if ((a[i] > a[i * 2]) && (a[i * 2] <= a[i * 2 + 1]))
			{
				swap (&a[i], &a[i * 2]);
				i = i * 2;
			}
			else
			{
				if  (((a[i] > a[i * 2]) && (a[i * 2] > a[i * 2 + 1])) || (a[i] > a[i * 2 + 1]) && (a[i * 2 + 1] < a[i * 2]))
				{
					swap (&a[i], &a[i * 2 + 1]);
					i = i * 2 + 1;
				}
				else
				{
					i = last;
				}
			}
		}
	}
};
void heapSort (int a[], int first, int last)
{
	for (int i = last / 2; i >= first; i--)
	{
		siftDown(a, i, last); 
	}	printArray (a, first, last); cout << endl;
	for (int i = last; i > first; i--)
	{
		swap (&a[i], &a[first]);
		siftDown (a, first, i - 1);
		printArray (a, first, last); cout << endl;
	}
}
int main()
{
	cout << "Please enter an array's length\n";
	int length = 0;
	cin >> length;
	int array[200];
	int start = 1;
	readArray (array, start, length);
	heapSort (array, start, length);
	printArray (array, start, length);
	return 0;
}

