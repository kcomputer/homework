#include <iostream>
using namespace std;
int main()
{
	cout << "Please enter a and n to calculate a^n.\n";
	int a = 0;
	int n = 0;
	cin >> a >> n;
	int i = 1;
	int current = 1;
	long arrayDegree[100];
	arrayDegree[i] = a;
	long degree = a;
	while (current < n)
	{
		degree = degree * degree;
		arrayDegree[++i] = degree;
		current = current * 2;
	}
	int exponent = current;
	if (current != n)
	{
	    exponent = current / 2;
		current = current / 4;
		degree = arrayDegree[--i];
	}
	while (exponent != n)
	{
		--i;
		if (exponent + current  <= n)
		{
			degree = degree * arrayDegree[i];
			exponent = exponent + current;
		}
		current = current / 2;

	}
	cout << a << "^" << n << "= " << degree;	
	return 0;
}
