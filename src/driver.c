#include "BinarySearchTree.h"

#include <stdio.h>
#include <string.h>

#define PREFIX_BUFFER_SIZE 128

void printBinarySearchTree(BinarySearchTreeNode *binarySearchTree, char *prefix, int isLeft)
{
	if (binarySearchTree == NULL)
		return;

	printf("%s", prefix);
	printf(isLeft ? "├──" : "└──");
	printf("%d", binarySearchTree->value);
	printf("\n");
	
	char newPrefix[PREFIX_BUFFER_SIZE];
	strcat(newPrefix, prefix);
	strcat(newPrefix,  (isLeft ? "│   " : "    "));

	printBinarySearchTree(binarySearchTree->left, newPrefix, 1);
	printBinarySearchTree(binarySearchTree->right, newPrefix, 0);
}

int main(void)
{
	BinarySearchTreeNode *binarySearchTree = NULL;

	while (1)
	{
		int input;

		printf("Please enter a number (to exit, enter -ive number):\n");
		scanf("%d", &input);

		if (input < 0)
			break;

		if (binarySearchTree == NULL)
			binarySearchTree = createBinarySearchTree(input);
		else
			insertValueBinarySearchTree(binarySearchTree, input);
		
		printf("\n");
		printBinarySearchTree(binarySearchTree, "", 0);
		printf("\n");
	}

	printf("Goodbye!\n");

	return 0;
}
