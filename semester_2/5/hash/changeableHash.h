#ifndef CHANGEABLEHASH_H
#define CHANGEABLEHASH_H

#include "hash.h"
#include <iostream>
#include <stringList.h>
#include <string>

using namespace std;

class ChangeableHash : public Hash
{
public:
    ChangeableHash(HashFunction *temp, int arrayLength);
    ~ChangeableHash();
    void addElement(string key);

    void deleteElement(string key);

    bool isIn(string key);

    void showStatistics();

    void changeHashFunction (HashFunction &nHash);


    int quantity;
    const int length;
    QList<QString> **hashTable;
    HashFunction *hashFunction;
};


#endif // CHANGEABLEHASH_H
