#pragma once

struct ListElement
{
	char symbol;
	ListElement *next;
};
ListElement *createList();
void insertElement(ListElement *head, char element);
bool isEmpty(ListElement *head);
char getElement(ListElement *head);
bool doesExist(ListElement *head, char element);
void deleteList(ListElement *head);