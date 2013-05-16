#ifndef AVLTREE_H
#define AVLTREE_H

#include <treeNode.h>

template <class T>
class AVLTree
{
public:
    AVLTree();
    ~AVLTree();
    void addElement(TreeNode<T> *&current, T value);
    void removeElement(TreeNode<T> *&current, T value);
    TreeNode<T>*  find(TreeNode<T> *current, T value);
    bool isLeaf(TreeNode<T> *current);
    bool hasOneChild(TreeNode<T> *current);
    void removeNode(TreeNode<T> *&current, T value);



    int height(TreeNode<T> *node);
    int balanceFactor(TreeNode<T> *node);
    void fixHeight(TreeNode<T> *node);
    void balanceNode(TreeNode<T> *&current);
    TreeNode<T> *rotateRight(TreeNode<T> *current);
    TreeNode<T> *rotateLeft(TreeNode<T> *current);
    TreeNode<T> *LeftMostChild(TreeNode<T> *current);


    int nodeCounter;
    int elementsCounter;

    TreeNode<T>* root;
};


template <typename T>
AVLTree<T>::AVLTree()
{
    this->root = NULL;
    this->nodeCounter = 0;
    this->elementsCounter = 0;
}

template <typename T>
AVLTree<T>::~AVLTree()
{
    delete this->root;
}


template <typename T>
int AVLTree<T>::height(TreeNode<T> *node)
{
    return (node != NULL)? node->height : 0;
}

template <typename T>
int AVLTree<T>::balanceFactor(TreeNode<T> *node)
{
    return height(node->rightChild) - height(node->leftChild);
}

template <typename T>
void AVLTree<T>::fixHeight(TreeNode<T> *node)
{
    int hLeft = height(node->leftChild);
    int hRight = height(node->rightChild);
    if(hLeft > hRight)
        node->height =  hLeft + 1;
    else
        node->height = hRight + 1;
}

template <typename T>
void AVLTree<T>::balanceNode(TreeNode<T> *&current)
{
    if (balanceFactor(current) == 2)
    {
        if (balanceFactor(current->rightChild) >= 0)
        {
            current = rotateLeft(current);
        }
        else
        {
            current->rightChild = rotateRight(current->rightChild);
            current = rotateLeft(current);
        }
    }
    else
    {
        if (balanceFactor(current) == -2)
        {
            if (balanceFactor(current->leftChild) <= 0)
            {
                current = rotateRight(current);
            }
            else
            {
                current->leftChild = rotateLeft(current->leftChild);
                current = rotateRight(current);
            }
        }
    }
}

template <typename T>
TreeNode<T> *AVLTree<T>::rotateRight(TreeNode<T> *current)
{
    TreeNode<T> *temp = current->leftChild;
    current->leftChild = temp->rightChild;
    temp->rightChild = current;
    fixHeight(current);
    fixHeight(temp);
    return temp;
}

template <typename T>
TreeNode<T> *AVLTree<T>::rotateLeft(TreeNode<T> *current)
{
    TreeNode<T> *temp = current->rightChild;
    current->rightChild = temp->leftChild;
    temp->leftChild = current;
    fixHeight(current);
    fixHeight(temp);
    return temp;
}

template <typename T>
bool AVLTree<T>::isLeaf(TreeNode<T> *current)
{
    return (current->leftChild == NULL) && (current->rightChild == NULL);
}

template <typename T>
bool AVLTree<T>::hasOneChild(TreeNode<T> *current)
{
    return (current->leftChild == NULL && current->rightChild != NULL) || (current->rightChild == NULL && current->leftChild != NULL);
}

template <typename T>
TreeNode<T> *AVLTree<T>::LeftMostChild(TreeNode<T> *current)
{
    if (current->leftChild != NULL)
    {
        return LeftMostChild(current->leftChild);
    }
    return current;
}

template <typename T>
TreeNode<T>*  AVLTree<T>::find(TreeNode<T> *current, T value)
{
    if (current != NULL)
    {
        if (current->value == value)
        {
            return current;
        }
        else if (current->value > value)
        {
            return find(current->leftChild, value);
        }
        else
        {
            return find(current->rightChild, value);
        }
    }
    else
        return NULL;
}

template <typename T>
void AVLTree<T>::addElement(TreeNode<T> *&current, T value)
{
    if (current == NULL)
    {
        current = new TreeNode<T>(value);
        nodeCounter++;
        elementsCounter++;
    }
    else
    {
        if (value < current->value)
        {
            addElement(current->leftChild, value);
        }
        else
        {
            if (value > current->value)
            {
                addElement(current->rightChild, value);
            }
            else
            {
                ++current->counter;
                elementsCounter++;
            }
        }
    }
    fixHeight(current);
    balanceNode(current);
}

template <typename T>
void AVLTree<T>::removeNode(TreeNode<T> *&current, T value)
{
    if (value < current->value)
    {
        removeNode (current->leftChild, value);
    }
    else
    {
        if (value > current->value)
        {
            removeNode (current->rightChild, value);
        }
        else
        {
            if (isLeaf(current))
            {
                delete current;
                current = NULL;
                nodeCounter--;
                elementsCounter--;
                return;
            }
            else
            {
                if (hasOneChild(current))
                {
                    if (current->leftChild != NULL)
                    {
                        TreeNode<T> *temp = current->leftChild;
                        current->leftChild = NULL;
                        delete current;
                        current = temp;
                    }
                    else
                    {
                        TreeNode<T> *temp = current->rightChild;
                        current->rightChild = NULL;
                        delete current;
                        current = temp;
                    }
                }
                else
                {
                    TreeNode<T> *toReplace = LeftMostChild(current->rightChild);
                    current->value = toReplace->value;
                    current->counter = toReplace->counter;
                    removeNode(current->rightChild, toReplace->value);
                }
            }
        }
    }
    nodeCounter--;
    elementsCounter--;
    fixHeight(current);
    balanceNode(current);
}

template <typename T>
void AVLTree<T>::removeElement(TreeNode<T> *&current, T value)
{
    if (value < current->value)
    {
        removeElement(current->leftChild, value);
    }
    else
    {
        if (value > current->value)
        {
            removeElement(current->rightChild, value);
        }
        else
        {
            if (current->counter > 1)
            {
                --current->counter;
            }
            else
            {
                removeNode(current, value);
            }
        }
    }
}

#endif // AVLTREE_H
