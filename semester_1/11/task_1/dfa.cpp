#include "dfa.h"

void skipSpace(const char *&expression)
{
    while (*expression == ' ')
	{
        expression++;
	}
}
int symbolType(const char *&value)
{
    char currentSymbol = *value;
    value++;

    switch (currentSymbol)
    {
	case '*': case '/': case ')': case '\0': case ' ' :
		{
		--value;
        return 0;
		}
    case '+': case '-':
        return 1;
    case '.':
        return 3;
    case 'e': case 'E':
        return 4;
    default:
        if ((currentSymbol >= '0') && (currentSymbol <= '9'))
		{
            return 2;
		}
        return -1;
    }
}


bool isNumber(const char *&value)
{
    for (int state = 0;;)
    {
        int symbol = symbolType(value);
        state = move[symbol][state];
	    if (state == 8)
		{
		    return true;
		}
		if (state == 9)
		{
			value--;
			return true;
		}
		if (state == 0)
		{
			return false;
		}
	}
}



bool bracketsRule(const char *&expression)
{
	skipSpace(expression);
	if (expression == 0)
	{
		return false;
	}
	if (*expression == '(')
	{
		expression++;
		if (!plusMinusRule(expression))
		{
			return false;
		}
		skipSpace(expression);
		if (expression == 0)
		{
			return false;
		}
		if (*expression != ')')
		{
			return false;
		}
		expression++;
		return true;
	}
	else
	{
		return isNumber(expression);
	}
}


bool multiDivRule(const char *&expression)
{
	skipSpace(expression);
	if (!bracketsRule(expression))
	{
		return false;
	}
	skipSpace(expression);
	while (*expression == '*' || *expression == '/')
    {
        expression++;
		if (*expression == '*' || *expression == '/' || *expression == '+' || *expression == '-')
		{
			return false;
		}
        if (!bracketsRule(expression))
		{
            return false;
		}
    }
	if (symbolType(expression) == -1)
	{
		return false;
	}
	else
	{
		--expression;
	}
	return true;
}



bool plusMinusRule(const char *&expression)
{
	skipSpace(expression);
	if (!multiDivRule(expression))
	{
		return false;
	}
	skipSpace(expression);
	while (*expression == '+' || *expression == '-')
    {
        expression++;
		if (*expression == '+' || *expression == '-')
		{
			return false;
		}
        if (!multiDivRule(expression))
		{
            return false;
		}
	}
	if (symbolType(expression) == -1)
	{
		return false;
	}
	return true;
}



bool parse(const char *expression)
{
	return (plusMinusRule (expression));
}