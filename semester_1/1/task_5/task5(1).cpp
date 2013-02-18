#include <iostream>

using namespace std;
int main()
{
                bool isIncorrect = false;
                char stack[100];
                char bracket = '0';
                int i = 0;
                char openBracket = '0';
		cout << "Enter a sequence of brackets to check\n";
                while (((bracket = getchar()) != EOF) && (!isIncorrect))
                {
                        bool isOpen=false;
                        if ((bracket == '(') || (bracket == '[') || (bracket == '{'))
                        {
                                isOpen = true;
                        }
 
                        if (isOpen)
                        {
                                stack[i++] = bracket;
                                openBracket = bracket;
                        }
                        else
                        {
                                if ((bracket - openBracket == 1) || (bracket - openBracket == 2))
                                {
                                        openBracket = stack[--i];
                                }
                                else
                                {
                                        isIncorrect = true;
                                }
                        }
                }

		if (isIncorrect)
		{
			cout << "Incorrect";
		}
		else
		{
			cout << "Correct";
		}
                return 0;
}