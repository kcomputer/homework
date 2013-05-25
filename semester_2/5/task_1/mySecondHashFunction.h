#ifndef MYSECONDHASHFUNCTION_H
#define MYSECONDHASHFUNCTION_H


#include "hashFunction.h"
#include <stringList.h>
#include <string>

using namespace std;

class MySecondHashFunction : public HashFunction
{
public:
    MySecondHashFunction(const int length);
    int hash(string key);
    int arrayLength;
private:
    int realFunction(char ch, int j);
    int degree;
};

#endif // MYSECONDHASHFUNCTION_H
