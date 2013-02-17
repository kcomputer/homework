#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include "tree.h"
using namespace std;

int main()
{
	FILE *streamFile;
	streamFile = fopen ("input.txt","r");
	if (streamFile == NULL) 
	{
		perror ("Error opening file");
	}
	else
	{
		Tree *tree = createTree();
		readTree(tree, streamFile);
		printTree(tree);
		cout << " = " << printResult(tree);		
		deleteTree(tree);
	}
	return 0;
}