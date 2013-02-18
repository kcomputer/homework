#pragma once

struct ListElement
{
	int value;
	ListElement *next;
};
ListElement *createList();
void insertElement(ListElement *head, int x);
bool isEmpty(ListElement *head);
void printElements(ListElement *head);
bool deleteElement(ListElement *head, int x);
void deleteList(ListElement *head);