#include <iostream>
#include "list.h";
using namespace std;
int main()
{
	cout << "Enter quantity of elements, number of element that should not be deleted and maximum step\n";
	int quantity = 0;
	int number = 0;
	int maximumStep;
	cin >> quantity >> number >> maximumStep;
	ListElement *head = createList();
	int currentStep = 1;
	bool doStepsExist = false;
	while (currentStep <= maximumStep)
	{
		for (int i = 1; i <= quantity; i++)
		{
			insertElement(head, i);
		}
		loopList(head);
		if (getElements(head, currentStep) == number)
		{
			doStepsExist = true;
			cout << currentStep << "  ";
		}
		++currentStep;
	}
	delete(head);
	if (!doStepsExist) 
	{
		cout << "There are not such steps in this range.";
	}
	return 0;
}