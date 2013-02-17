#include <iostream>
using namespace std;
int main()
{
	cout << "Enter a and n to calculate a^n\n";
	int a = 0;
	int n = 0;
	cin >> a >> n;
	int degree = 1;
	for (int i = 1; i <= n;++i)
	{
		degree = a * degree;
	}
	cout << "a^n = " << degree;
	return 0;
}

