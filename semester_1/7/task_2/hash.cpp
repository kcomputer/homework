#include "hash.h"

StackElement *hashArray[arraylength];


void createHash ()
{
		for (int i = 0; i < arraylength; ++i)
		{
			hashArray[i] = new StackElement;
			hashArray[i]->frequence = 0;
			hashArray[i]->next = NULL;
		}
}


void deleteHash ()
{
	for (int i = 0; i < arraylength; i++)
		deleteStack(hashArray[i]);
}


static long long degree = 1;


int function (string word)
{
	int j = 0;
	string::iterator i = word.begin();
	while (i < word.end())
	{
		j += realFunction( *i, j);
		i++;
	}
	degree = 1;
	j %= arraylength;
	return j;
}


int realFunction ( char ch, int j)
{
	j = ((int (ch)) * degree) % arraylength;
	degree *= 11;
	return j;
}


void insertHash (string word)
{
	if (!findElement (hashArray[function(word)], word))
	{
		insertElement(hashArray[function(word)], word);
	}
}


void printHash ()
{
	for (int i = 0; i < arraylength; i++)
	{
		std::cout << i << ":\n";
		if (hashArray[i]->frequence == 0)
		{
			cout << "Empty" << endl;
		}
		else
		{
			printStack (hashArray[i]);
		}
		cout << endl;
	}
}