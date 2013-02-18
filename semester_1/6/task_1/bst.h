#pragma once


struct TreeNode 
{
	int value;
	TreeNode *left;
	TreeNode *right;
};

struct Tree
{
	TreeNode *root;
};


Tree *createTree();
void add(Tree *root, int value);
bool exists(Tree *root, int value);
void remove(Tree *&root, int value);
void printSymmetrically(Tree *tree);
void printAntiSymmetrically(Tree *tree);
void deleteBst (Tree *tree);
