#ifndef MYHASHFUNCTION_H
#define MYHASHFUNCTION_H

#include "hashFunction.h"
#include <string>

using namespace std;

class MyHashFunction : public HashFunction
{
public:
    MyHashFunction(const int length);
    int hash(string key);
    int arrayLength;
private:
    int realFunction(char ch, int j);
    int degree;
};

#endif // MYHASHFUNCTION_H
