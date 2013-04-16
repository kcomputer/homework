#include "calculator.h"

int Calculator::calculate(int left, char sym, int right)
{
    switch (sym)
    {
        case '+':
            return left + right;
        case '-':
            return left - right;
        case '*':
            return left * right;
        case '/':
            return left / right;
    }
    return 0;
}
