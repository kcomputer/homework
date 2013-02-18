#include <iostream>
 
using namespace std;
int main()
{
	cout << "Please enter x to calculate x^4 + x^3 + x^2 + x + 1\n"; 
        int x = 0;
        cin >> x;
        int q = x * x;
        cout << "x^4 + x^3 + x^2 + x + 1 = " << ((q + 1) * (q + x) +1) <<endl;
        return 0;
}