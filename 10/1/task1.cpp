#include <iostream>
#include <fstream>
#include "list.h"
using namespace std;

int main()
{
	ListElement *polynomialOne = createList();
	ListElement *polynomialTwo = createList();
	ListElement *temp = polynomialOne->next;
	int command = 0;
	int x = 0;
	int number = 0;
	int power = 0;
	bool isEqual = true;
	while (cin)
	{
		cout << "Input 0 to to exit.\n";
		cout << "Input 1 to create a new polynomial.\n";
		cout << "Input 2 to evaluate the polynomial.\n";
		cout << "Input 3 to add two polynomials.\n";
		cout << "Input 4 to check equality of a polynomial to the polynomial.\n" << endl;
		cin >> command;
		switch (command)
		{
		case 1:
			cout << "Enter coefficients and powers. Enter 0 0, if you finish\n";
			deleteList(polynomialOne);
			number = -1;
			while ((cin) && (number != 0))
			{
				cin >> number >> power;
				if (number == 0)
				{
					continue;
				}
				insertElement(polynomialOne, number, power);
			}
			break;
		case 2:
			cout << "Enter x to evaluate polynomial:\n";
			cin >>  x;
			cout << result(polynomialOne, x) << endl;
			break;			
		case 3:
			cout << "Enter coefficients and powers of the second polinomial. Enter 0 0, if you finish\n";
			isEqual = true;
			number = -1;
			temp = polynomialOne->next;
			while (temp != NULL)
			{
				insertElement(polynomialTwo, temp->number, temp->power);
				temp = temp->next;
			}
			while ((cin) && (number != 0))
			{
				cin >> number >> power;
				if (number == 0)
				{
					continue;
				}
				polyPlus(polynomialTwo, number, power);
			}
			cout << "The summm is:\n";
			printElements(polynomialTwo);
			deleteList(polynomialTwo);
			break;
		case 4: 
			cout << "Enter coefficients and powers of the second polinomial. Enter 0 0, if you finish:\n";
			isEqual = false;
			number = -1;
			while ((cin) && (number != 0))
			{
				cin >> number >> power;
				if (number == 0)
				{
					continue;
				}
				if (find(polynomialOne, number, power))
				{
					isEqual = true;
				}
			}
			if (isEqual)
			{
				cout << "Polinomials are equal.\n";
			}
			else
			{
				cout << "Polinomials are not equal.\n";
			}
			break;
		case 0: 
		    deleteList(polynomialOne);
			delete(polynomialOne);
			delete(polynomialTwo);
			return 0;		
		}
		cout << endl << endl << endl;
	}

}
