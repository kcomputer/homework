#ifndef HASHFUNCTION_H
#define HASHFUNCTION_H

#include <string>

using namespace std;

//! Virtual hash function interface.

class HashFunction
{
public:
    //! Calculates value of hash function
    virtual int hash(string key) = 0;
};

#endif // HASHFUNCTION_H
