#include <iostream>
#include <stdlib.h>
using namespace std;

void printMantissa (unsigned long long number)
{
	unsigned long long temp = 1;
	temp <<=63;
	if (temp & number)
	{
		cout << '-';
	}
	else 
	{
		cout << '+';
	}
	unsigned long long mantissa = 0;
	int numberOfZeros = 0;
	long long degreeInLong = 1;
	
	unsigned long long limit = 0;
	limit = ~limit;
	limit = limit / 10;

	unsigned long long currentBit = 1;
	currentBit <<= 51;

	unsigned long long valueForCheck = 0;
	valueForCheck = ~valueForCheck;
	valueForCheck >>=12;
	 
	while (valueForCheck & number)
	{
		if (mantissa <= limit)
		{
			mantissa = mantissa * 10;
			degreeInLong = degreeInLong * 5;
		}
		else
		{
			degreeInLong = degreeInLong * 5 / 10;
		}
		if ((mantissa == 0) && (!(currentBit & number)))
		{
				++numberOfZeros;
		}
		if (currentBit & number)
		{
			mantissa = mantissa + degreeInLong;
		}
		currentBit >>=1;
		valueForCheck >>=1; 
	}
	cout << "1." ;
	for (int i = 1; i <= numberOfZeros; ++i)
		{
			cout << '0';
		}
	cout << mantissa;
}


void printExponent (unsigned long long number)
{
	number <<=1;
	number >>=53;
	number = number - 1023;
	cout << "*2^(" << number << ')';
}


int main()
{
	cout << "Enter any number you want except zero.\n";
	double doubleNumber = 0;
	cin >> doubleNumber;
	long long mask = 1;
	unsigned long long *longNumber = (unsigned long long*)&doubleNumber;
	printMantissa (*longNumber);
	printExponent (*longNumber);
	return 0;
}