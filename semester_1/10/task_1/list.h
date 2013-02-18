#pragma once

struct ListElement
{
	int number;
	int power;
	ListElement *next;
};
ListElement *createList();
void insertElement(ListElement *head, int number, int power);
bool isEmpty(ListElement *head);
void printElements(ListElement *head);
int result(ListElement *head, int x);
bool find(ListElement *head, int number, int power);
void polyPlus(ListElement *head, int number, int power);
void deleteList(ListElement *head);