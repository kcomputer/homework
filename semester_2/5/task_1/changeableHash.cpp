#include "changeableHash.h"

ChangeableHash::ChangeableHash(HashFunction *temp, int arrayLength)
{
    length = arrayLength;
    hashFunction = temp;
    hashTable = new StringList*[length];
    for (int i = 0; i < length; ++i)
    {
        hashTable[i] =  new StringList();
    }
    quantity = 0;
}




ChangeableHash::~ChangeableHash()
{
    for (int i = 0; i < length; ++i)
    {
        delete hashTable[i];
    }
    delete[] hashTable;
}


bool ChangeableHash::isIn(string key)
{
    return hashTable[hashFunction->hash(key)]->find(key);
}


void ChangeableHash::addElement(string key)
{
    if (!isIn(key))
    {
        hashTable[hashFunction->hash(key)]->insert(key);
        ++quantity;
    }
}

void ChangeableHash::deleteElement(string key)
{
    if (hashTable[hashFunction->hash(key)]->deleteValue(key))
    {
        --quantity;
    }
}


void ChangeableHash::showStatistics()
{
    cout << endl << "Quantity is " << quantity << endl;
    cout << "Load factor is " << quantity / length << endl;
}

void ChangeableHash::changeHashFunction (HashFunction *nHash)
{
    hashFunction = nHash;
    StringList **tempTable = new StringList*[length];
    for (int i = 0; i < length; ++i)
    {
        tempTable[i] =  new StringList();
    }
    for (int i = 0; i < length; i++)
    {
        tempTable[i] = hashTable[i];
        delete hashTable[i];
        hashTable[i] = new StringList();
    }
    for (int i = 0; i < length; i++)
    {
        while (!tempTable[i])
        {
            addElement(tempTable[i]->getValue());
            tempTable[i]->deleteValue(tempTable[i]->getValue());
        }
    }
    delete[] tempTable;
}



