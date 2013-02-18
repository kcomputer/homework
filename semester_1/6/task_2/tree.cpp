#include <iostream>
#include <stdlib.h>
#include "tree.h"
#include <stdio.h>
using namespace std;


Tree *createTree()
{
    Tree *tree = new Tree;
    tree->root = NULL;
    return tree;
}

TreeNode *createNode(char value, TreeNode *parent)
{
    TreeNode *node = new TreeNode;
    if (value == '*' || value == '/' || value == '-' || value == '+')
	{
		node->operation = value;
		node->operand = 'e';
	}
	else
	{
		node->operation = 'e';
		node->operand = value;
	}
    node->left = NULL;
    node->right = NULL;
	node->parent = parent;
    return node;
}


void readTree(TreeNode *&node, FILE *streamFile)
{	
	char symbol = '$';
	TreeNode *temp = node;
	symbol = fgetc(streamFile);
	while (!feof(streamFile))
	{
		if (symbol == '(')
		{
			symbol = fgetc(streamFile);
			while ((symbol != '(') && (symbol != ')'))
			{
				if (symbol != ' ')
				{
					if ((temp->operand != 'e') && (symbol >= '0') && (symbol <= '9'))
					{
						temp = temp->parent;
					}
					if (temp->left == NULL)
					{
						temp->left = createNode(symbol, temp);
						temp = temp->left;
					}
					else
					{
						temp->right = createNode(symbol, temp);
						temp = temp->right;
					}
				}
				symbol = fgetc(streamFile);
			}
			if (symbol == '(')
			{
				ungetc(symbol, streamFile);
			}
		}
		else
		{
			if ((symbol != ' ') && (symbol != ')'))
			{
				temp->right = createNode(symbol, temp);
				temp = temp->right;
			}
		}
		if ((symbol == ')') && (temp->operand != 'r'))
			{
				temp = temp->parent;
				while (temp->right != NULL)
				{
					temp = temp->parent;
				}
			}
		symbol = fgetc(streamFile);
	}
}


void readTree(Tree *tree, FILE *streamFile)
{
	TreeNode *node = new TreeNode;
	node->operation = 'r';
	node->operand = 'r';
    node->left = NULL;
    node->right = NULL;
	node->parent = NULL;
	tree->root = node;
	readTree(tree->root, streamFile);

}

				

void printTree(TreeNode *node)
{
	if (node->operation != 'e')
	{
		cout << '(' << node->operation << ' ';
	}
	else
	{
		cout << ' ' << node->operand;
	}
	if (node->left != NULL)
	{
		printTree(node->left);
	}
	if (node->right != NULL)
	{
		printTree(node->right);
		cout << ')';
	}
}



void printTree(Tree *tree)
{
	if (!isLeaf(tree->root))
	{
		printTree (tree->root->left);
	}
}

int charToInt(char a)
{
	return a - '0';
}


int calculate(char operation, int operandFirst, int operandSecond)
{
	switch (operation)
	{
	case '*':
		return operandFirst * operandSecond;
	case '/':
		return operandFirst / operandSecond;
	case '+':
		return operandFirst + operandSecond;
	case '-':
		return operandFirst - operandSecond;
	}
}


int printResult(TreeNode *node)
{
	if ((node->left->operation == 'e') && (node->right->operation == 'e'))
	{
		return calculate(node->operation, charToInt(node->left->operand), charToInt(node->right->operand));
	}
	if ((node->left->operation != 'e') && (node->right->operation == 'e'))
	{
		return calculate(node->operation, printResult(node->left), charToInt(node->right->operand));
	}
	if ((node->left->operation == 'e') && (node->right->operation != 'e'))
	{
		return calculate(node->operation, charToInt(node->left->operand), printResult(node->right));
	}
	if ((node->left->operation != 'e') && (node->right->operation != 'e'))
	{
		return calculate(node->operation, printResult(node->left), printResult(node->right)); 
	}
}



int printResult(Tree *tree)
{
	if (!isLeaf(tree->root))
	{
		return printResult (tree->root->left);
	}
}



bool isLeaf(TreeNode *node)
{
    return ((node->left == NULL) && (node->right == NULL));
}


void deleteTree(TreeNode *node)
{
	if (isLeaf(node))
	{
		delete (node);
		return;
	}
	TreeNode *tempNode = node;
	if(tempNode->left != NULL)
	{
		deleteTree(node->left);
	}	
	if (tempNode->right != NULL)
	{
		deleteTree(tempNode->right);
	}
	delete(tempNode);
}


void deleteTree (Tree *tree)
{
	if (!isLeaf(tree->root))
	{
		deleteTree(tree->root->left);
	}
	delete (tree->root);
	delete (tree);
}