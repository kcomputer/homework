#include "bst.h"
#include <stdlib.h>
#include <iostream>
using namespace std;


Tree *createTree()
{
    Tree *tree = new Tree;
    tree->root = NULL;
    return tree;
}

TreeNode *createNode(int value)
{
    TreeNode *node = new TreeNode;
    node->value = value;
    node->left = NULL;
    node->right = NULL;
    return node;
}


void add(TreeNode *&node, int value)
{
	if (node == NULL)
    {
        node = createNode(value);
        return;
    }
    if (value < node->value)
        add(node->left, value);
    else
        add(node->right, value);
}


void add(Tree *tree, int value)
{
	add(tree->root, value);
}


TreeNode *leftmostChild(TreeNode *node)
{
    if (node->left != NULL)
        return leftmostChild(node->left);
    else
        return node;
}



bool isLeaf(TreeNode *node)
{
    return ((node->left == NULL) && (node->right == NULL));
}


bool hasOneChild(TreeNode *node)
{
    return ((node->left != NULL && node->right == NULL)
            || (node->left == NULL && node->right != NULL));
}

bool exists(TreeNode *root, int value)
{
	if (root == NULL)
        return false;
    if (root->value == value)
        return true;
    if (root->value > value)
        return exists(root->left, value);
    else
        return exists(root->right, value);
}


bool exists(Tree *tree, int value)
{
    return exists(tree->root, value);
}


int deleteMinTree(TreeNode *&node)
{
	if (node->left)
		return deleteMinTree(node->left);
	else
	{
		int k = node->value;
		delete node;
		node = NULL;       
		return k;
	}
}


void remove(TreeNode *&node, int value)
{
    if (node->value > value)
        remove(node->left, value);
    else if (node->value < value)
        remove(node->right, value);
    else if (isLeaf(node))
    {
        delete node;
        node = NULL;
    }
    else
	if (hasOneChild(node))
    {
        if (node->left != NULL)
        {
            TreeNode *temp = node->left;
			node->left = NULL;
            delete node;
            node = temp;
        }
        else 
        {
			if (node->right != NULL)
			{
				TreeNode *temp = node->right;
				node->right = NULL;
				delete node;
				node = temp;
		    }
		}
	}
	else
	{			
		node->value = deleteMinTree(node->right);
	}
}

void remove(Tree *&tree, int value)
{
    if (!exists(tree, value))
       return;
    remove(tree->root, value);
}

void printSymmetrically(TreeNode *node)
{
	if (isLeaf(node))
	{
		cout << node->value << "  ";
		return;
	}
	TreeNode *tempNode = node;
	bool wasThere = false;
	if ((tempNode->left != NULL) && (!wasThere))
	{
		wasThere = true;
		printSymmetrically(node->left);	
	}	
	cout << tempNode->value << "  ";
	if (tempNode->right != NULL)
	{
		printSymmetrically(tempNode->right);
	}
}
void printSymmetrically(Tree *tree)
{
	if (tree->root == NULL)
	{
		cout << "Set is empty!\n";
	}
	else
	{
		printSymmetrically(tree->root);
	}
}


void printAntiSymmetrically(TreeNode *node)
{
	if (isLeaf(node))
	{
		cout << node->value << "  ";
		return;
	}
	TreeNode *tempNode = node;
	bool wasThere = false;
	if ((tempNode->right != NULL) && (!wasThere))
	{
		wasThere = true;
		printAntiSymmetrically(node->right);
		
	}	
	cout << tempNode->value << "  ";
	if (tempNode->left != NULL)
	{
		printAntiSymmetrically(tempNode->left);
	}
}
void printAntiSymmetrically(Tree *tree)
{
	if (tree->root == NULL)
	{
		cout << "Set is empty!\n";
	}
	else
	{
		printAntiSymmetrically(tree->root);
	}
}

void deleteBst(TreeNode *node)
{
	if (isLeaf(node))
	{
		delete (node);
		node = NULL;
		return;
	}
	TreeNode *tempNode = node;
	bool wasThere = false;
	if ((tempNode->right != NULL) && (!wasThere))
	{
		wasThere = true;
		deleteBst(node->right);
	}	
	if (tempNode->left != NULL)
	{
		deleteBst(tempNode->left);
	}
	delete(tempNode);
	tempNode = NULL;
}


void deleteBst (Tree *tree)
{
	if (tree->root != NULL)
	{
		deleteBst(tree->root);
	}
	delete (tree);
}