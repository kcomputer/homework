#ifndef HASHFUNCTION_H
#define HASHFUNCTION_H

#include <string>

using namespace std;

class HashFunction
{
public:
    virtual ~HashFunction () {}
    virtual int hash(string key);
    int arrayLength;
};

#endif // HASHFUNCTION_H
