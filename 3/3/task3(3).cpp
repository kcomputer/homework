#include <iostream>
#include "stack.h"
using namespace std;
int main ()
{
	cout << "Enter an infix expression, this program will print postfix the postfix expression\n";
	StackElement *head = createStack();
	char symbol = '1';
	while ((symbol = getchar()) != '\n')
	{
		if ((symbol == '(') || (symbol == ')') || (symbol == '*') || (symbol == '/') || (symbol == '-') || (symbol == '+'))
		{
			switch (symbol)
			{
			case '(':
				insertElement (head, symbol, 0);
				break;
			case ')':
				while (head->next->operand != '(')
				{
					cout << head->next->operand;
					deleteElement (head);
				}
				deleteElement (head);
				break;
			case '+':
				if (!isEmpty(head))
				{
					if (head->next->priority > 1)
					{
						cout << head->next->operand;
						deleteElement (head);
					}
				}
				if (!isEmpty(head))
				{
					if (head->next->priority == 1)
					{
						cout << head->next->operand;
						deleteElement (head);
					}
				}
				insertElement (head, symbol, 1);
				break;
			case '-':
				if (!isEmpty(head))
				{
					if (head->next->priority > 1)
					{
						cout << head->next->operand;
						deleteElement (head);
					}
				}
				if (!isEmpty(head))
				{
					if ((head->next->priority) == 1)
					{
						cout << head->next->operand;
						deleteElement (head);
					}
				}
				insertElement (head, symbol, 1);
				break;
			case '*':
		      if (!isEmpty(head))
				{
					if (head->next->priority == 2)
					{
						cout << head->next->operand;
						deleteElement (head);
					}
				}
				insertElement (head, symbol, 2);
				break;
			case '/':
				if (!isEmpty(head))
				{
					if (head->next->priority == 2)
					{
						cout << head->next->operand;
						deleteElement (head);
					}
				}
				insertElement (head, symbol, 2);
				break;
			}
		}
		else
		{
			cout << symbol;
		}
	}
	cout << head->next->operand;
	delete(head->next);
	delete (head);
	return 0;
}