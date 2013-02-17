#include <iostream>

using namespace std;
int main()
{
        cout << "Please enter a and b to calculate a / b\n";
	int a = 0;
  	int b = 0;
	int count = 0;
        cin >> a >> b;
	while ((a > b) || (a == b))
	{
		a = a - b;
		++count;
	}
    cout << count << endl;
	return 0;
}
