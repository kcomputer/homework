#ifndef PRIORITYQUEUE_H
#define PRIORITYQUEUE_H

#include <stdexcept>


//! Priority queue interface
template <class T>
class PriorityQueue
{
public:
    //! Exepetion

    /*!
        throws when you dequeue from empty queue.
    */
    class EmptyQueue{};

    //! Constructor
    PriorityQueue(): value(0), next(NULL), priority(0){}

    //! Destructor
    ~PriorityQueue();

    //! Checks if queue is empty
    bool isEmpty();

    //! Adds element to queue according to priority.
    void enqueue(T value, int priority);

    //! Returns element of the highest priority and deletes it from the queue
    T dequeue();

private:

    //! Look for an element
    PriorityQueue* find(T value, int priority );
    T value;
    int priority;
    PriorityQueue<T> *next;
};







template <class T>
PriorityQueue<T>::~PriorityQueue()
{
    delete next;
}


template <class T>
bool PriorityQueue<T>::isEmpty()
{
    return this->next == NULL;
}


template <class T>
PriorityQueue<T>* PriorityQueue<T>::find(T value, int priority)
{
    PriorityQueue<T> *current = this;
    while ((current->next) && (current->value != value) && (current->priority != priority))
    {
        current = current->next;
    }
    if (current->value == value)
    {
        return current;
    }
    else
    {
        return NULL;
    }
}

template <class T>
void PriorityQueue<T>::enqueue(T value, int priority)
{
    if (!this->find(value, priority))
    {
        PriorityQueue<T> *temp = new PriorityQueue();
        temp->value = value;
        temp->priority = priority;
        if (this->isEmpty())
        {
            this->next = temp;
        }
        else
        {
            PriorityQueue<T> *current = this->next;
            PriorityQueue<T> *beforeCurrent = this;
            while ((current->next)&&(current->priority >= priority))
            {
                beforeCurrent = beforeCurrent->next;
                current = current->next;
            }
            if (!current->next)
            {
                current->next = temp;
            }
            else
            {
                temp->next = current;
                beforeCurrent->next = temp;
            }
        }
    }
}


template <class T>
T PriorityQueue<T>::dequeue()
{
    if (isEmpty())
    {
        throw PriorityQueue<T>::EmptyQueue();
    }
    PriorityQueue<T> *temp = this->next;
    T tempValue = temp->value;
    this->next = temp->next;
    temp->next = NULL;
    delete temp;
    return tempValue;
}



#endif // PRIORITYQUEUE_H
