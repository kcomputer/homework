#include <stdio.h>
#include "arrayList.h"
#include "pointerList.h"
#include "list.h"
#include <iostream>

using namespace std;

int main()
{
	cout << "What kind of list would you like to use?\n";
	cout << "Press  1  for pointer list.\n";
	cout << "Press  2  for array list.\n";
	int kindOfList = 0;
	cin >> kindOfList;
	List *iosif = 0;
	if (kindOfList == 1)
	{
		iosif = new PointerList();
	}
	else
	{
		iosif = new ArrayList();
	}
	delete (iosif);
}