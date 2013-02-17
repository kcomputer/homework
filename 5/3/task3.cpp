#include <iostream>
#include <stdio.h>
using namespace std;

int main ()
{
	FILE *streamFile;
	streamFile = fopen ("input.txt","r");
	char symbol = '0';
	char secondSymbol = '0';
	if (streamFile == NULL) 
	{
		perror ("Error opening file");
	}
	else
	{
		while (!feof(streamFile))
		{
			symbol = fgetc(streamFile);
			if (symbol == '\n')
			{
				cout << endl;
			}
			if (symbol == '"')
			{
				symbol = fgetc(streamFile);
				while (symbol != '"')
				{
					symbol = fgetc(streamFile);
				}
				symbol = fgetc(streamFile);
			}
			if (symbol == '/')
			{
				secondSymbol = fgetc(streamFile);
				if (secondSymbol == '/')
				{
					cout << "//";
					while (((symbol = fgetc(streamFile)) != '\n') && (!feof(streamFile)))
					{
						cout << symbol;
					}
					cout << endl;
				}
				else
				{
					if (secondSymbol == '*')
					{
						bool isClosed = false;
						cout << "/*";
						while (!isClosed)
						{
							while (((symbol = fgetc(streamFile)) != '*') && (!feof(streamFile)) && (!isClosed))
							{
								if (symbol == '"')
								{
									cout << '"';
									symbol = fgetc(streamFile);
									while (symbol != '"')
									{
										cout << symbol;
										symbol = fgetc(streamFile);
										
									}
									symbol = fgetc(streamFile);
								}
								if (symbol == '/')
								{
									secondSymbol = fgetc(streamFile);
									if (secondSymbol == '/')
									{
										while ((symbol = fgetc(streamFile)) != '*')
										{
										}
										secondSymbol = fgetc(streamFile);
										if (secondSymbol == '/')
										{
											isClosed = true;
											cout << "*/";
											symbol = fgetc(streamFile);
										}
									}
								}
								cout << symbol;
								
							}
							if (!isClosed)
							{
								secondSymbol = fgetc(streamFile);
								if (secondSymbol == '/')
								{
									cout << "*/";
									isClosed = true;
								}
								else
								{
									cout << symbol;
								}
							}
						}
					}
				}
			}
		}
	}
  return 0;
}