#ifndef UNIQUELISTSET_H
#define UNIQUELISTSET_H
#include <listSet.h>


template<class T>
class UniqueListSet : public ListSet<T>
{
public:
    class DeleteUnexisting {};
    class AddExisting {};
    void add(T value);
    void deleteElement(T value);
};


template<class T>
void UniqueListSet<T>::add(T value)
{
    if (ListSet<T>::find(value))
    {
        throw UniqueListSet<T>::AddExisting();
    }
    ListSet<T>::add(value);
}

template<class T>
void UniqueListSet<T>::deleteElement(T value)
{
    if (!ListSet<T>::find(value))
    {
        throw UniqueListSet<T>::DeleteUnexisting();
    }
    ListSet<T>::deleteElement(value);
}

#endif // UNIQUELISTSET_H
