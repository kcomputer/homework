#include <iostream>
using namespace std;
int main()
{
	cout << "Enter n to calculate n!\n";
	int n = 0;
	cin >> n;
	int factorial = 1;
	while (n > 1)
	{
		factorial = factorial * n;
		--n;
	}
	cout << factorial;
	return 0;
}

