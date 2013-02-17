#pragma once
#include "string"
using namespace std;
struct StackElement
{
	string word;
	int frequence;
	StackElement *next;
};
bool findElement (StackElement *&head, string word);
void insertElement(StackElement *head, string word);
void printStack(StackElement *head);
void deleteStack(StackElement *head);
