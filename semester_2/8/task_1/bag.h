#ifndef BAG_H
#define BAG_H
#include "avlTree.h"
#include <treeNode.h>
#include <QStack>
#include <stdexcept>




template <class T>
class Bag
{
public:

    //! Iterator class for Bag
    class iterator
    {
    public:
        //! Exception class
        /*!
            is throwed when no elements left
        */
        class DunnoHaveNext{};

        //! Iterator constructor
        iterator(Bag<T>* multiset)
        {
            tree = multiset->multisetTree;
            index = 0;
            sameElementCounter = 0;
            currentNode = tree->root;
            getLeftMost();
        }

        //! Checks if there is next element
        bool hasNext()
        {
            return (tree->elementsCounter != index);
        }

        //! Returns next element
        T next()
        {
            if (hasNext())
            {
                if(index == 0)
                {
                    ++index;
                    sameElementCounter = currentNode->counter;
                    --sameElementCounter;
                    return currentNode->value;
                }
                else
                {
                    if (sameElementCounter > 0)
                    {
                        --sameElementCounter;
                        ++index;
                        return currentNode->value;
                    }
                    else
                    {
                        if (currentNode->rightChild)
                        {
                            currentNode = currentNode->rightChild;
                            getLeftMost();
                        }
                        else
                        {
                            currentNode = wayBack.pop();
                        }
                        sameElementCounter = currentNode->counter;
                        return next();
                    }
                }
            }
            else
            {
                throw Bag<T>::iterator::DunnoHaveNext();
            }
        }

        //! Adds element.
        void add(T value)
        {
            tree->addElement(tree->root, value);
            ++index;
            if (currentNode->value == value)
            {
                --sameElementCounter;
            }
        }

        //! Remove current element and goes next
        T remove()
        {
            TreeNode<T>*temp = currentNode;
            next();
            --index;
            tree->removeElement(tree->root, temp->value);
            if (currentNode->value == temp->value)
            {
                --sameElementCounter;
            }
            else
            {
                if (wayBack.contains(temp))
                    wayBack.remove(wayBack.indexOf(temp));
            }

            return currentNode->value;
        }

    private:

        //! Helper to set current node of a tree as its most left child.
        void getLeftMost()
        {
            while(currentNode->leftChild)
            {
                wayBack.push(currentNode);
                currentNode = currentNode->leftChild;
            }
        }

        //! Stores path to have opportunity to get next element
        QStack<TreeNode<T>*> wayBack;
        TreeNode<T>* currentNode;
        AVLTree<T>* tree;
        int index;
        int sameElementCounter;
    };
    Bag();
    ~Bag();
    //! return amount of elements of set
    int size();

    //! return true if multiset is empty
    bool isEmpty();

    //! insert element
    void insert(T value);

    //! remove element
    void remove(T value);

    //! remove all elements
    void clearAll();

    //!  find element
    bool find(T value);

private:
    AVLTree<T>* multisetTree;
};





template <class T>
Bag<T>::Bag()
{
    multisetTree = new AVLTree<T>();
}

template <class T>
Bag<T>::~Bag()
{
    delete multisetTree;
}

template <class T>
int Bag<T>::size()
{
    return multisetTree->elementsCounter;
}

template <class T>
bool Bag<T>::isEmpty()
{
    return multisetTree->root == NULL;
}

template <class T>
void Bag<T>::insert(T value)
{
    multisetTree->addElement(multisetTree->root, value);
}

template <class T>
void Bag<T>::remove(T value)
{
    multisetTree->removeElement(multisetTree->root, value);
}

template <class T>
void Bag<T>::clearAll()
{
    delete multisetTree;
    multisetTree = NULL;
}

template <class T>
bool Bag<T>::find(T value)
{
    return (multisetTree->find(multisetTree->root, value) != NULL);
}




#endif // BAG_H


