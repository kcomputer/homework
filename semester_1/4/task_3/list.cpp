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
		ListElement *lastMore = head;
		while ((lastMore->next != NULL) && (lastMore->next->value > x))
		{
			lastMore = lastMore->next;
		}
		ListElement *temp = new ListElement;
		temp->value = x;
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
bool deleteElement(ListElement *head, int x)
{
	if (isEmpty(head))
	{
		return false;
	}
	else
	{
		ListElement *beforeElementToDelete = head;
		ListElement *ElementToDelete = head->next;
		while ((ElementToDelete != NULL) && (ElementToDelete->value != x))
		{
			ElementToDelete = ElementToDelete->next;
			beforeElementToDelete = beforeElementToDelete->next;
		}
		if (ElementToDelete == NULL)
		{
			return false;
		}
		else
		{
			beforeElementToDelete->next = ElementToDelete->next;
			delete(ElementToDelete);
			return true;
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
			cout << elementToPrint->value << "  ";
				elementToPrint = elementToPrint->next;
		}
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
	delete(head);
}