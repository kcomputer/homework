#pragma once


struct TreeNode 
{
	char operand;
	char operation;
	TreeNode *left;
	TreeNode *right;
	TreeNode *parent;
};

struct Tree
{
	TreeNode *root;
};


Tree *createTree();
void readTree(Tree *tree, FILE *streamFile);
bool isLeaf(TreeNode *node);
void printTree(Tree *tree);
int printResult(Tree *tree);
void deleteTree(Tree *tree);
