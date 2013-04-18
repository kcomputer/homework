#include "stackMachine.h"
#include "stackInt.h"
#include "arrayStackInt.h"
#include "pointerStackInt.h"

int stackMachine(string stringExpression, int kindaStack)
{
    StackInt *expression;
    if (kindaStack !=  1)
    {
        expression = new ArrayStackInt();
    }
    else
    {
        expression = new PointerStackInt();
    }
    int a = 0;
    int b = 0;
	int i = 0;
	while (i < stringExpression.length())
	{
		switch (stringExpression[i])
		{
		case '+':
			a = expression->pop();
			b = expression->pop();
			expression->push(a+b);
			break;
		case '-':
			a = expression->pop();
			b = expression->pop();
			expression->push(b-a);
			break;
		case '*':
			a = expression->pop();
			b = expression->pop();
			expression->push(a*b);
			break;
		case '/':
			a = expression->pop();
			b = expression->pop();
			expression->push(b/a);
			break;
		default:
			expression->push(stringExpression[i]-'0');
			break;
		}
		++i;
	}
	int toReturn = expression->top();
	delete(expression);
	return toReturn;
}

		
