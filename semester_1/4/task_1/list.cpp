#include "list.h"
#include <stdlib.h>
#include <iostream>
using namespace std;

ListElement *createList()
{
	ListElement *temp = new ListElement;
	temp->symbol = 0;
	temp->next = NULL;
	return temp;
}
bool isEmpty(ListElement *head)
{
	return head->next == NULL;
}
void insertElement(ListElement *head, char element)
{
	if (isEmpty(head))
	{
		ListElement *temp = new ListElement;
		temp->symbol = element;
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
		temp->symbol = element;
		lastElement->next = temp;
		temp->next = NULL;
	}
} 
bool doesExist(ListElement *head, char element)
{
	bool tempDoesExist = false;
	ListElement *temp = head->next;
	ListElement *previousTemp = head;
	while (temp != NULL)
	{
		if (element == temp->symbol)
		{
			previousTemp->next = temp->next;
			delete (temp);
			return !tempDoesExist;
		}
		previousTemp = previousTemp->next;
		temp = temp->next;
	}
	return tempDoesExist;
}
void deleteList(ListElement *head)
{
	ListElement *temp = head->next;
	while (head->next != NULL)
	{
		temp = head->next;
		head->next = head->next->next;
		delete(temp);
	}
	delete (head);
}