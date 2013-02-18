#include <cstdio>
#include "dfa.h"
using namespace std;

int main(void)
{
    printf("Enter a double value:\n");
    char value[80];
    scanf("%s", value);
    if (DFA(value))
	{
        printf("OK\n");
	}
    else
	{
        printf("FAIL\n");
	}
    return 0;
}