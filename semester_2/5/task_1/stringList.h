#ifndef STRINGLIST_H
#define STRINGLIST_H

#include "string.h"
#include "iostream"

using namespace std;

/// String List.

class StringList
{
public:
    StringList (): next(NULL), current(this), counter(0), value("") {}
    ~StringList ();
    //! Inserts string to list.

    /*!
        If element is in list, it will increase counter, if not it will add it as a new element.
    */
    void insert(string h);

    //! Returns value of element.
    string getValue();

    //! Gets the first element from a List

    /*!
        deletes it from the list, returns NULL if it is empty
    */
    StringList* find (string h);

    //! Deletes a string from the list
    /*!
        \return true if deleted, false if element not found
     */
    bool deleteValue(string h);



private:
    StringList* next;
    StringList* current;
    int counter;
    string value;
    void insertElement (string h);
    StringList* finder(string h);

};
#endif // STRINGLIST_H
