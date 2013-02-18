#include <iostream>
#include "list.h"
#include <string>
#include <fstream>
#include <stdlib.h>
using namespace std;
int main()
{
	cout << "Enter the first filename:\n";
	string firstFileName = "";
	cin >> firstFileName;
	ifstream firstFile(firstFileName, ifstream::in);
	if (!firstFile.good())
	{
		cout << "Error! Something is wrong with input file.\n";
		return 1;
	}

	cout << "Enter the second filename:\n";
	string secondFileName = "";
	cin >> secondFileName;
	ifstream secondFile(secondFileName, ifstream::in);
	if (!firstFile.good())
	{
		cout << "Error! Something is wrong with input file.\n";
		return 1;
	}
	freopen("output.txt", "w", stdout);
	ListElement * head = createList();
	string temp = "";
	while (firstFile)
	{
		temp.clear();
		getline(firstFile, temp);
		insertElement(head, temp);
	}
	while (secondFile)
	{
		temp.clear();
		getline(secondFile, temp);
		if (doesExist(head, temp))
		{
			cout << temp << endl;
		}
	}
	deleteList(head);	
	return 0;
}
