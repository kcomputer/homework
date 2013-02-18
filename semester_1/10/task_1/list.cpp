#include "list.h"
#include <stdlib.h>
#include <iostream>
using namespace std;

ListElement *createList()
{
	ListElement *temp = new ListElement;
	temp->number = 0;
	temp->power = 0;
	temp->next = NULL;
	return temp;
}

bool isEmpty(ListElement *head)
{
	return head->next == NULL;
}

void insertElement(ListElement *head, int number, int power)
{
	if (isEmpty(head))
	{
		ListElement *temp = new ListElement;
		temp->number = number;
		temp->power = power;
		head->next = temp;
		temp->next = NULL;
	}
	else
	{
		ListElement *lastMore = head;
		while ((lastMore->next != NULL) && (lastMore->next->power > power))
		{
			lastMore = lastMore->next;
		}
		ListElement *temp = new ListElement;
		temp->number = number;
		temp->power = power;
		if (lastMore->next== NULL)
		{
			lastMore->next = temp;
			temp->next = NULL;
		}
		else
		{
			temp->next = lastMore->next;
			lastMore->next = temp;
		}
	}
} 

void printElements(ListElement *head)
{
	if (head->next == NULL)
	{
		cout << "List is empty.\n";
	}
	else
	{
		ListElement *elementToPrint = head->next;
		while (elementToPrint != NULL)
		{
			if ((elementToPrint->number != 1) && (elementToPrint->number != -1))
			{
				cout << elementToPrint->number;
			}
			cout << "x^(" << elementToPrint->power << ")";
			if (elementToPrint->next != NULL)
			{
				if (elementToPrint->next->number > 0)
				{
					cout << "+";
				}
				else
				{
					cout << "-";
				}
			}
			elementToPrint = elementToPrint->next;
		}
	}
}
int degree(int a, int n)
{
	int temp = 1;
	for (int i = 1; i <= n; ++i)
	{
		temp = temp * a;
	}
	return temp;
}

int result(ListElement *head, int x)
{
	int temp = 0;
	ListElement *tempElement = head->next;
	while (tempElement != NULL)
	{
		temp = temp + tempElement->number * degree(x, tempElement->power);
		tempElement = tempElement->next;
	}
	return temp;
}

bool find(ListElement *head, int number, int power)
{
	ListElement *tempElement = head->next;
	bool isThere = false;
	while ((tempElement != NULL) && (!isThere))
	{
		if ((tempElement->number == number) && (tempElement->power == power))
		{
			isThere = true;
		}
		tempElement = tempElement->next;
	}
	return isThere;
} 


void polyPlus(ListElement *head, int number, int power)
{
	ListElement *tempElement = head->next;
	bool isThere = false;
	while ((tempElement != NULL) && (!isThere))
	{
		if (tempElement->power == power)
		{
			isThere = true;
			continue;
		}
		tempElement = tempElement->next;
	}
	if (isThere)
	{
		tempElement->number = tempElement->number + number;
	}
	else
	{
		insertElement(head, number, power);
	}
}

void deleteList(ListElement *head)
{
	ListElement *elementToDelete = head;
	while (head->next != NULL)
	{
		elementToDelete = head->next;
		head->next = head->next->next;
		delete(elementToDelete);
	}
	head->next = NULL;
}