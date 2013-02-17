#include <iostream>;
using namespace std;
long Fibonacci(int number)
{
	if (number == 2 || number == 1) 
   	 	return 1;
    else 
   	 	return Fibonacci(number - 2) + Fibonacci(number - 1);
}
int main()
{
	cout << "Enter n to print nth Fibonacci number.\n";
	int n = 0;
	cin >> n;
	if (n == 0)
	{
		cout << n;
	}
	else 
	{
		cout << Fibonacci (n);
	}
	return 0;
}

