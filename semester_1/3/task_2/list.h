#pragma once

struct ListElement
{
	int value;
	ListElement *next;
};
ListElement *createList();
void insertElement(ListElement *head, int x);
int getElements(ListElement *head, int i);
bool isEmpty(ListElement *head);
void getElement(ListElement *head, int x);
void loopList(ListElement *head);