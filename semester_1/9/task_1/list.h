#pragma once
#include <string>
using namespace std;
struct ListElement
{
	string symbol;
	ListElement *next;
};
ListElement *createList();
void insertElement(ListElement *head, string element);
bool isEmpty(ListElement *head);
bool doesExist(ListElement *head, string element);
void deleteList(ListElement *head);