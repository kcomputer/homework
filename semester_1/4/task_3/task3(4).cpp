#include "list.h"
#include <iostream>
using namespace std;
void dialog()
{
	cout << "0 - exit\n";
	cout << "1 - add value to sorted list\n";
	cout << "2 - remove value from list\n";
	cout << "3 - print list\n";
	cout << endl;
}
int main()
{
	ListElement *head = createList();
	int command = 3;
	while (command != 0)
	{
		dialog();
		cin >> command;
		if (command == 1)
		{
			cout << "Enter the value you want to add\n";
			int value = 0;
			cin >> value;
			insertElement(head, value);
			cout << "The value have been added.\n";
		}
		else 
		{
			if (command == 2)
			{
				cout << "Enter the value you want to delete\n";
				int value = 0;
				cin >> value;
				if (deleteElement(head, value))
				{
					cout << "The value have been deleted.\n";
				}
				else
				{
					cout << "There is not such element!\n";
				}
			}
			else
			{
				if (command == 3)
				{
					printElements(head);
					cout << endl;
				}
				else
				{
					if (command != 0)
					{
						cout << "Eror! There is not such command.\n";
					}
				}
			}
		}
	cout << endl;
	cout << endl;
	}
	deleteList(head);
	return 0;
}