#include <iostream>
using namespace std;


int fromWhom(int arrayStudents[], int i)
{
	if ((arrayStudents[i] != 1) && (arrayStudents[i] != 2) && (arrayStudents[i] != 3))
	{
		return fromWhom(arrayStudents, arrayStudents[i]);
	}
	else
	{
		return arrayStudents[i];
	}
}


int main()
{
	cout << "How many students are?\n";
	int quantity = 0;
	cin >> quantity;
	int arrayStudents[200];
	for (int i = 1 ; i <= quantity; ++i)
	{
		arrayStudents[i] = 0;
	}
	int student = 0;
	int studentHelper = 0;
	cout << "Enter data, if you finish enter CTRL+Z:\n";
	while (!cin.eof())
	{
		cin >> student >> studentHelper;
		arrayStudents[student] = studentHelper;
	}
	for (int i = 4; i <= quantity; ++i)
	{
		if (arrayStudents[i] == 0)
		{
			cout << "Student " << i << " has a big problem.\n";
		}
		else
		{
			cout << "Student " << i << " has cheated using a code of " << fromWhom(arrayStudents, i) << " student.\n";
		}
	}
	return 0;
}
