#include "BinarySearchTree.h"

#include <stdio.h>
#include <string.h>

#define PREFIX_BUFFER_SIZE 128

void printBinarySearchTree(BinarySearchTreeNode *binarySearchTree, char *prefix, int isLeft);

void printInOrder(BinarySearchTreeNode *binarySearchTree);

void printPreOrder(BinarySearchTreeNode *binarySearchTree);

void printPostOrder(BinarySearchTreeNode *binarySearchTree);

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

		printf("InOrder Traversal: ");
		printInOrder(binarySearchTree);
		printf("\n");

		printf("PreOrder Traversal: ");
		printPreOrder(binarySearchTree);
		printf("\n");

		printf("PostOrder Traversal: ");
		printPostOrder(binarySearchTree);
		printf("\n");
	}

	printf("Goodbye!\n");

	return 0;
}

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

void printInOrder(BinarySearchTreeNode *binarySearchTree)
{
	if (binarySearchTree->left)
		printInOrder(binarySearchTree->left);

	printf("%d, ", binarySearchTree->value);

	if (binarySearchTree->right)
		printInOrder(binarySearchTree->right);
}

void printPreOrder(BinarySearchTreeNode *binarySearchTree)
{
	printf("%d, ", binarySearchTree->value);

	if (binarySearchTree->left)
		printPreOrder(binarySearchTree->left);

	if (binarySearchTree->right)
		printPreOrder(binarySearchTree->right);
}

void printPostOrder(BinarySearchTreeNode *binarySearchTree)
{
	if (binarySearchTree->left)
		printPostOrder(binarySearchTree->left);

	if (binarySearchTree->right)
		printPostOrder(binarySearchTree->right);

	printf("%d, ", binarySearchTree->value);
}
