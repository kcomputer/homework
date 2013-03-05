#include <iostream>
#include "stack.h"
#include "pointerStack.h"
#include "arrayStack.h"
#include <sstream>
#include <string.h>
#include "stackMachine.h"

using namespace std;

int priority (char symbol)
{
	switch(symbol)
	{
		case '(':
			return 0;
			break;
		case '+':
		case '-':
			return 1;
			break;
		case '*':
		case '/':
			return 2;
			break;
	}
}

int main ()
{
	cout << "What kind of stack would you like to use?\n";
	cout << "Press  1  for pointer stack.\n";
	cout << "Press  2  for array stack.\n";
	int kindOfStack = 0;
	cin >> kindOfStack;
	Stack *expression = NULL;
	if (kindOfStack == 1)
	{
		expression = new PointerStack();
	}
	else
	{
		expression = new ArrayStack();
	}

	cout << "And now enter an infix expression to calculate it using stack calculator:\n";

	stringstream postfixExpression;


	char symbol = '$';
	symbol = getchar();
	symbol = '$';

	while ((symbol = getchar()) != '\n')
	{
		if ((symbol == '(') || (symbol == ')') || (symbol == '*') || (symbol == '/') || (symbol == '-') || (symbol == '+'))
		{
			switch (symbol)
			{
			case '(':
				expression->push(symbol);
				break;
			case ')':
				while (expression->top() != '(')
				{
					postfixExpression << expression->pop();
				}
				expression->pop();
				break;
			case '+':
			case '-':
				if (expression->isEmpty())
				{
					if (priority(expression->top()) > 1)
					{
						postfixExpression << expression->pop();
					}
				}
				if (expression->isEmpty())
				{
					if (priority(expression->top()) == 1)
					{
						postfixExpression << expression->pop();
					}
				}
				expression->push(symbol);
				break;
			case '*':
			case '/':
				if (expression->isEmpty())
				{
					if (priority(expression->top()) == 2)
					{
						postfixExpression << expression->pop();
					}
				}
				expression->push(symbol);
				break;
			}
			
		}
		else
		{
			postfixExpression << symbol;
		}
	}
	while (expression->isEmpty())
	{
		postfixExpression << expression->pop();
	}
	delete (expression);
	string stringExpression;
	postfixExpression >> stringExpression;
	cout << "=" << endl << stackMachine(stringExpression);
	return 0;
}