#include <iostream>
#include "bst.h"
using namespace std;

void dialog()
{
	cout << endl << endl;
	cout << "0 - exit" << endl;
	cout << "1 - add value to the set" << endl;
	cout << "2 - remove value from the set" << endl;
	cout << "3 - add value to check if it belongs to the set" << endl;
	cout << "4 - print elements ascendingly" << endl;
	cout << "5 - print elements descendingly" << endl << endl;
}
int main()
{
	dialog();
	Tree *tree = createTree();
	int command = -1;
	while (command != 0)
	{
		cin >> command;
		int value = 0;
		switch (command)
		{
		case 1:
			cout << endl << "Enter value to add:\n";
			cin >> value;
			add(tree, value);
			break;
		case 2:
			cout << endl << "Enter value to delete:\n";
			cin >> value;
			if (exists(tree,value))
			{
					remove(tree, value);
			}
			else
			{
				cout << "There is not such an element.\n";
			}
			break;
		case 3:
			cout << endl << "Enter value to check:\n";
			cin >> value;
			if (exists(tree,value))
			{
				cout << "There is " << value << " in the set.\n";
			}
			else
			{
				cout << "There is not such an element.\n";
			}
			break;
		case 4:
			cout << endl;
			printSymmetrically(tree);
			break;
		case 5:
			cout << endl;
			printAntiSymmetrically(tree);
			break;
		}
	dialog();
	}
	deleteBst(tree);
	return 0;
}

	