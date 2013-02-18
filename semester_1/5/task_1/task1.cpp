#include <iostream>
#include <stdio.h>
using namespace std;

int main ()
{
	FILE *streamFile;
	streamFile = fopen ("input.txt","r");
	char word[100];
	int currentLength = 0;
	if (streamFile == NULL) 
	{
		perror ("Error opening file");
	}
	else
	{
		while (!feof(streamFile))
		{
			char letter = '0';
			letter = fgetc(streamFile);
			if ((letter == '\n') || (letter == ' '))
			{
				cout << letter;
				currentLength = 0;
			}
			else
			{
				bool isIn = false;
				for (int i = currentLength;i > 0;--i)
				{
					if (letter == word[i])
					{
						isIn = true;
					}
				}
				if (!isIn)
				{
					cout << letter;
					++currentLength;
					word[currentLength] = letter;
				}
			}
		}
	}
  return 0;
}