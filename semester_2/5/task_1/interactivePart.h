#ifndef INTERACTIVEPART_H
#define INTERACTIVEPART_H

#include <iostream>
#include "hashFunction.h"
#include "changeableHash.h"
#include "myHashFunction.h"
#include "mySecondHashFunction.h"
#include <stringList.h>
#include <string>

using namespace std;



int  ask()
{
    cout << "You can use this commands:\n"
            "  1 - add value to table\n"
            "  2 - remove value from table\n"
            "  3 - find value in table\n"
            "  4 - change hash function\n"
            "  5 - print hash-table statistics\n"
            "  0 - exit the program\n";
    int command = 0;
    cin >> command;
    return command;
}

void interactivePart()
{
    HashFunction *mHasherOne = new MyHashFunction(157);
    HashFunction *mHasherTwo = new MySecondHashFunction(157);
    HashFunction *currentHasher = mHasherOne;
    ChangeableHash *mHash = new ChangeableHash(currentHasher, 157);
    string key = "";

    int command = -1;
    while (command)
    {
        command = ask();
        switch(command)
        {
        case (1):
        {
            cout << "Enter the element.\n";
            cin >> key;
            mHash->addElement(key);
            break;
        }
        case(2):
        {
            cout << "Enter the element.\n";
            cin >> key;
            mHash->deleteElement(key);
            break;
        }
        case(3):
        {
            cout << "Enter the element.\n";
            cin >> key;
            mHash->isIn(key);
            break;
        }
        case(4):
        {
            if (currentHasher == mHasherOne)
            {
                currentHasher = mHasherTwo;
            }
            else
            {
                currentHasher = mHasherOne;
            }
            mHash->changeHashFunction(currentHasher);
            break;
        }
        case(5):
        {
            mHash->showStatistics();
            break;
        }
        }
    }

}

#endif // INTERACTIVEPART_H
