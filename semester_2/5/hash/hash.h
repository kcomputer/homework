#ifndef HASH_H
#define HASH_H

#include <HashFunction.h>
#include <stringList.h>
#include <string>

using namespace std;

//! Virtual hash table interface.

class Hash
{
public:
    //! Add element to hash table.
    virtual void addElement(string key) = 0;

    //! Delete element from hash table.
    virtual void deleteElement(string key) = 0;

    //! Return true if element is in hash table, false if not.
    virtual bool isIn(string key) = 0;

    //! Show information about hash table.
    virtual void showStatistics() = 0;

    //! Change hash function.
    virtual void changeHashFunction (HashFunction &nHash) = 0;

};

#endif // HASH_H
