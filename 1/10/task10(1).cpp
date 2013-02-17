#include <iostream>
using namespace std;
int main()
{
	cout << "Enter string to check if it is a palindrome.\n";
	char array[100];
	char symbol = '0';
	int i = 0;
	while ((symbol = getchar()) != EOF)
	{
		array[++i] = symbol;
	}
	bool isPalindrome = true;
	int j = 1;
	while ((isPalindrome) && (j < (1 + i) / 2))
	{
		if (array[j] != array[i - j + 1])
		{
			isPalindrome = false;
		}
		++j;
	}
	if (isPalindrome) 
	{
		cout << "Yes, it is a palindrome";
	}
	else
	{
		cout << "No, it's not";
	}
	
}

