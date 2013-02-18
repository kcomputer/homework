# pragma once

struct StackElement
{
	char operand;
	int priority;
	StackElement *next;
};
StackElement *createStack();
bool isEmpty(StackElement *head);
void insertElement(StackElement *head, char element, int priority);
void deleteElement(StackElement *head);
void printStack(StackElement *head);

