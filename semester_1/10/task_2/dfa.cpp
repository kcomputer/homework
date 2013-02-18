#include "dfa.h"

int symbolType(const char *&value)
{
    char currentSymbol = *value;
    value++;

    switch (currentSymbol)
    {
    case '\0':
        return 0;
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

bool DFA(const char *value)
{
    for (int state = 0;;)
    {
        int symbol = symbolType(value);
        if (symbol == -1)
		{
            return false;
		}
        state = move[symbol][state];
        if (state == 0)
		{
            return false;
		}
        if (state == 8)
		{
            return true;
		}
    }
}
