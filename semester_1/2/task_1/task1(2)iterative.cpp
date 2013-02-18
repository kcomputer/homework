#include <iostream>;
using namespace std;
int main()
{
	cout << "Enter n to print nth Fibonacci number.\n";
	int n = 0;
	cin >> n;
	int currentN = 2;
	long previous = 1;
	long current = 1;
	if (n == 0)
	{
		cout << n;
	}
	else
	{
		if (n < 3)
		{
			cout << current;
		}
		else
		{
			while (currentN != n)
			{
				++currentN;
				int temp;
				temp = current;
				current = previous + current;
				previous = temp;
			}
			cout << current;
		}
	}
	return 0;
}

