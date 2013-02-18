#include <stdio.h>
#include <iostream>
#include "stack.h"
using namespace std;
void calculate(int result[], int &currentIndex, char operand, StackElement *head)
{
	switch (operand)
	{
	case '*':
		result[currentIndex - 1] = result[currentIndex] * result[currentIndex-1];
		break;
	case '/':
		result[currentIndex - 1] = result[currentIndex - 1] / result[currentIndex];
		break;
	case '-':
		result[currentIndex - 1] = result[currentIndex-1] - result[currentIndex];
		break;
	case '+':
		result[currentIndex - 1] = result[currentIndex] + result[currentIndex-1];
		break;
	}
	--currentIndex;
	deleteElement(head);
}


int main ()
{
	cout << "Enter an infix expression, this program will calculate it.\n";
	StackElement *head = createStack();
	int result [100];
	int currentIndex = 0;
	char symbol = '1';
	while ((symbol = getchar()) != '\n')
	{
		if ((symbol == '(') || (symbol == ')'))
		{
			switch (symbol)
			{
			case '(':
				insertElement (head, symbol, 0);
				break;
			case ')':
				while (head->next->operand != '(')
				{
					calculate(result, currentIndex, head->next->operand, head);
				}
				deleteElement (head);
				break;
			}
		}
		else
		{
			if ((symbol == '*') || (symbol == '/') || (symbol == '-') || (symbol == '+'))
			{
				if (!isEmpty(head) && (head->next->priority > 1))
				{
					calculate(result, currentIndex, head->next->operand, head);
				}
				switch (symbol)
				{
				case '+':
					insertElement (head, symbol, 1);
					break;
					case '-':
					insertElement (head, symbol, 1);
					break;
				case '*':
					insertElement (head, symbol, 2);
					break;
				case '/':
					insertElement (head, symbol, 2);
					break;
				}
			}
			else
			{
				++currentIndex;
				result[currentIndex] = symbol - 48;
			}
		}
	}
	while (head->next != NULL)
	{
		calculate(result, currentIndex, head->next->operand, head);
	}
	cout << result[1];
	delete(head->next);
	delete (head);
	return 0;
}