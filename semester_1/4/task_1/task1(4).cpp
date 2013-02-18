#include <iostream>
#include "list.h"
using namespace std;
int main()
{
	cout << "Enter two strings and the program will inform you if we can get other string by transposing symbols of the first string.\n";
	char symbol = '0';
	int lengthFirst = 0;
	ListElement * head = createList();
	while ((symbol = getchar()) != '\n')
	{
		++lengthFirst;
		insertElement(head, symbol);
	}
	bool canWe = true;
	while (((symbol = getchar()) != '\n') && (canWe))
	{
		if (!isEmpty(head))
		{
			if (!doesExist(head, symbol))
			{
				canWe = false;
			}
		}
		else
		{
			canWe = false;
		}
	}
	if (!isEmpty(head))
	{
		canWe = false;
		deleteList(head);
	}
	else
	{
		delete (head);
	}
	if (canWe)
	{
		cout << "Yes, we can do it";
	}
	else
	{
		cout << "No, we can't do it";
	}
	return 0;
}