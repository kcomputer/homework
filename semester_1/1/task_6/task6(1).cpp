#include <iostream>
using namespace std;
int main()
{
	cout << "Enter strings to check if one is substring of other\n";
    char string[100];
	char subString[100];
	char symbol = 0;
	int lengthOfFirst = 0;
	while ((symbol = getchar()) != '\n')
	{
		string[++lengthOfFirst] = symbol;
	}
	int lengthOfSecond = 0;
	while ((symbol = getchar()) != '\n')
	{
		subString[++lengthOfSecond] = symbol;
	}
	int i = 1;
	int count = 0;
	while ((lengthOfSecond + i - 1 <= lengthOfFirst) || (i <= lengthOfFirst))
	{
		bool isSubstring = true;
		int j = 0;
		while ((isSubstring) && (j < lengthOfSecond))
		{
			++j;
			if (string[i + j - 1] != subString[j])
			{
				isSubstring = false;
			}
		}			
		if (isSubstring)
		{
			++count;
		}
		++i;
	}
	cout << count;
	return 0;
}