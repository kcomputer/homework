#include <stdlib.h>
#include <iostream>
#include "stack.h"
using namespace std;


void insertElement(StackElement *head, string word)
{
	if (head->frequence == 0)
	{
		head->word = word;
		head->frequence = 1;
	}
	else
	{
		StackElement *temp = head;
		while (temp->next != NULL)
		{
			temp = temp->next;
		}
		StackElement *newElement = new StackElement;
		temp->next = newElement;
		newElement->next = NULL;
		newElement->frequence = 1;
		newElement->word = word;
	}
}


bool findElement (StackElement *&head, string word)
{
	if (head->frequence != 0)
	{
		StackElement *temp = head;
		while ((temp->next != NULL) && (temp->word != word))
		{
			temp = temp->next;
		}
		if (temp->word == word)
		{
			++temp->frequence;
			return true;
		}
	}
	return false;
}


void printStack(StackElement *head)
{
	while (head != NULL)
	{
		cout << head->word << "  " << head->frequence << endl;
		head = head->next;
	}
}

void deleteStack(StackElement *head)
{
	if (head->next != NULL)
	{
		deleteStack(head->next);
	}
	delete (head);
	head = NULL;
}