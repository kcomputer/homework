#include <iostream>
using namespace std;


int main()
{
    const int length = 50;

    int *array = new int[length];
    for (int i = 0; i < length; i++)
    {
        if (i % 2 == 0)
        {
            array[i] = 0;
        }
        else
        {
            array[i] = 1;
        }
    }

    int counter = 0;
    for (int i = 0; i < length; i++)
    {
        if (array[i] == 0)
        {
            ++counter;
        }
    }

    delete array;

    cout << counter << endl;
    return 0;
}

