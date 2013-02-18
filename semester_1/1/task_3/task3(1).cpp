#include <iostream>

using namespace std;
void swapArray (int a[], int first, int last)
{
	for (int i = first;i < (last + first) / 2 + 1 ;++i)
	{
		int temp = a[i];
		a[i] = a[last + first - i];
		a[last + first - i] = temp;
	}
};
int main()
{
	int m = 0;
	int n = 0;
	int array[200];
	cout << "Enter m and n to find out about the length of both parts" << endl;
	cin >> m >> n;
	for (int i = 1;i < m + n + 1;++i)
	{
		cin >> array [i];
	}
	swapArray (array,1,m + n);
	swapArray (array,1, n);
	swapArray (array,n + 1,m + n);
	for (int i = 1;i < m + n + 1;++i)
	{
		cout << array[i] << " ";
	}
	return 0;
}

