#include "list.h"
#include <stdlib.h>
#include <iostream>
using namespace std;

ListElement *createList()
{
	ListElement *temp = new ListElement;
	temp->value = 0;
	temp->next = NULL;
	return temp;
}
bool isEmpty(ListElement *head)
{
	return head->next == NULL;
}
void insertElement(ListElement *head, int x)
{
	if (isEmpty(head))
	{
		ListElement *temp = new ListElement;
		temp->value = x;
		head->next = temp;
		temp->next = NULL;
	}
	else
	{
		ListElement *lastElement = head;
		while (lastElement->next != NULL)
		{
			lastElement = lastElement->next;
		}
		ListElement *temp = new ListElement;
		temp->value = x;
		lastElement->next = temp;
		temp->next = NULL;
	}
} 
void loopList (ListElement *head)
{
	ListElement *lastElement = head->next;
	while (lastElement->next != NULL)
		{
			lastElement = lastElement->next;
		}
	lastElement->next = head->next;
}
int getElements(ListElement *head, int step)
{
	ListElement *thatElement = head->next;
	int value = thatElement->value;
	ListElement *temp = head->next;
	ListElement *lastElement = head->next;
	while (!isEmpty(head))
	{
		for (int j = 1; j < step; ++j)
		{
			thatElement = thatElement->next;
		}
		if (thatElement->value == thatElement->next->value)
		{
			head->next = NULL;
			value = thatElement->value;
			delete thatElement;
			return value;
		}
		temp = thatElement;
		if (head->next->value == thatElement->value)
		{
			head->next = thatElement->next;
		}
		while (temp->next->value != thatElement->value)
			{
				temp = temp->next;
			}
		temp->next = thatElement->next;
		temp = thatElement;
		thatElement= thatElement->next;
		delete temp;	
	}
}
