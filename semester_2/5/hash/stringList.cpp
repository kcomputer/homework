#include "stringList.h"


StringList::~StringList ()
{
    delete next;
}
int StringList::inclusions()
{
    if (this)
    {
        return counter;
    }
    return 0;
}

string StringList::getVal()
{
    return value;
}

StringList* StringList::find(string value)
{
    StringList* tmp = finder(value);
    return tmp->next;
}

StringList* StringList::finder(string value)
{
    StringList* tmp = this;
    while (tmp->next && tmp->next->value.compare(value))
        tmp = tmp->next;
    return tmp;
}

bool StringList::deleteValue(string value)
{
    StringList* tmp = finder(value);
    if (tmp->next)
    {
        if (tmp->next->counter > 1)
        {
            tmp->next->counter--;
            return true;
        }
        else
        {
            if (current == tmp->next)
                current = tmp;
            StringList* temp = tmp->next;
            tmp->next = tmp->next->next;
            temp->next = NULL;
            delete temp;
            return true;
        }
    }
    return false;
}


void StringList::insertElement(string value)
{
    StringList* tmpx = new StringList;
    tmpx->value = value;
    if (!next)
    {
        current = tmpx;
        next = current;
    }
    else
    {
        current->next = tmpx;
        current = tmpx;
    }
}



void StringList::insert(string value)
{
    StringList* tmp = next;
    if (tmp && (tmp = tmp->find(value)))
    {
        tmp->counter++;
    }
    else
    {
        insertElement(value);
        current->counter = 1;
    }
}


/*void StringList::print()
{
    StringList* tmp = next;
    while (tmp)
    {
        cout <<'\t' << tmp->value.c_str() << ' ' << tmp->counter << " times " << endl;
        tmp = tmp->next;
    }
    if (!this)
        cout << "empty";
}*/
