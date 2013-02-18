#include "stdafx.h"
#include <iostream>
using namespace std;
void SternBrocotTree(int a, int b, int c, int d, int number)
{
	if (((a + c) <= number) && ((b + d) <= number))
	{
		SternBrocotTree(a, b, c + a, d + b, number);
		cout << a + c << "/" << b + d << "  ";
		SternBrocotTree(a + c, b + d, c, d, number);
	}
}
int _tmain(int argc, _TCHAR* argv[])
{
	cout << "Please enter N";
	int n = 0;
	cin >> n;
	int leftNumerator = 0;
	int leftDenominator = 1;
	int rightNumerator = 1;
	int rightDenominator = 0;
	SternBrocotTree(leftNumerator, leftDenominator, rightNumerator, rightNumerator, n);
	return 0;
}
