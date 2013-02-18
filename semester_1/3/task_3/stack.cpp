#include <stdlib.h>
#include <iostream>
#include "stack.h"
using namespace std;

StackElement *createStack()
{
	StackElement *head = new StackElement;
	head->next = NULL;
	head->operand = 'n';
	return head;
}
bool isEmpty(StackElement *head)
{
	return head->next == NULL;
}
void insertElement(StackElement *head, char element, int priority)
{
	if (isEmpty(head))
	{
		StackElement *temp = new StackElement;
		head->next = temp;
		temp->next = NULL;
		temp->operand = element;
		temp->priority = priority;
	}
	else
	{
		StackElement *temp = new StackElement;
		temp->next = head->next;
		head->next = temp;
		temp->operand = element;
		temp->priority = priority;
	}
}
void deleteElement(StackElement *head)
{
	StackElement *temp = head->next->next;
	delete (head->next);
	head->next = temp;
}