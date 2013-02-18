#include <iostream>
using namespace std;
int main()
{
	cout << "Enter n" << endl;
        int n = 0; 
	cin >> n;
	bool simpleBool[100];
	for (int i = 2;i < n + 2;++i)
	{
		simpleBool[i] = true;
	}
	int simpleInt[100];
	int k = 1;
	int simpleNumber = 2;
	while (simpleNumber < n + 1)
	{
		int step = 2;
		while (simpleNumber * step < n)
		{
			simpleBool[simpleNumber * step] = false;
			++step;		  
		}
		simpleInt[k] = simpleNumber;
		++k;
		++simpleNumber;
		while (!simpleBool[simpleNumber])
		{
			++simpleNumber;
		}
	}
	for (int i = 1;i < k;++i)
	{
		cout << simpleInt[i] << " ";
	}
	return 0;
}