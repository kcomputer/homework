#ifndef TREENODE_H
#define TREENODE_H


#include <stdlib.h>

/** TreeNode template class */
template <typename T>
class TreeNode
{
public:
    TreeNode(T value) : leftChild(NULL), rightChild(NULL), value(value), height(0), counter(1) {}
    ~TreeNode()
    {
        if (leftChild != NULL)
        {
            delete leftChild;
        }
        if (rightChild != NULL)
        {
            delete rightChild;
        }
    }
    TreeNode *leftChild;
    TreeNode *rightChild;
    T value;
    int height;
    int counter;
};

#endif // TREENODE_H
