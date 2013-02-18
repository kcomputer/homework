#include <iostream>
#include <string>
#include "hash.h"
#include "stack.h"
#include "fstream"
using namespace std;

int main()
{
	freopen("output.txt", "w", stdout);
	cout << "Enter the text, if there is not text anymore enter CTRL+Z:\n";
	string word = "input.txt";
	ifstream input(word,  ifstream::in);
	createHash();
	if (input.good())
	{
		while (input)
		{
			word.clear();
			input >> word;
			if (input)
			{
				insertHash (word);	
			}
		}
		printHash();
		deleteHash();
	}
	else
	{
		cout << "Error! Something is wrong with input file.\n";
	}
	return 0;
}