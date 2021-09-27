#include "BinarySearchTree.h"

#include <stdio.h>
#include <stdlib.h>
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

		printf("Please enter a number (+ive to add, -ive to remove, 0 to quit):\n");
		scanf("%d", &input);

		if (input == 0)
			break;

		if (input > 0)
		{
			if (binarySearchTree == NULL)
				binarySearchTree = createBinarySearchTree(input);
			else
				insertValueBinarySearchTree(binarySearchTree, input);
		}
		else
		{
			binarySearchTree = removeValueBinarySearchTree(binarySearchTree, input * -1);
		}

		printf("\n");

		printBinarySearchTree(binarySearchTree, "", 0);
		printf("\n");
		
		printf("Size of Tree: %d\n", getSizeBinarySearchTree(binarySearchTree));
		printf("Depth of Tree: %d\n", getDepthBinarySearchTree(binarySearchTree));

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

void printArray(BinarySearchTreeNode **array, int length)
{
	for (int index = 0; index < length; index++)
		printf("%d, ", (*(array + index))->value);
}

void printInOrder(BinarySearchTreeNode *binarySearchTree)
{
	int binarySearchTreeSize = getSizeBinarySearchTree(binarySearchTree);
	BinarySearchTreeNode *nodes[binarySearchTreeSize];
	int currentIndex = 0;

	inOrderTraversalBinarySearchTree(binarySearchTree, nodes, &currentIndex);
	printArray(nodes, binarySearchTreeSize);
}

void printPreOrder(BinarySearchTreeNode *binarySearchTree)
{
	int binarySearchTreeSize = getSizeBinarySearchTree(binarySearchTree);
	BinarySearchTreeNode *nodes[binarySearchTreeSize];
	int currentIndex = 0;

	preOrderTraversalBinarySearchTree(binarySearchTree, nodes, &currentIndex);
	printArray(nodes, binarySearchTreeSize);
}

void printPostOrder(BinarySearchTreeNode *binarySearchTree)
{
	int binarySearchTreeSize = getSizeBinarySearchTree(binarySearchTree);
	BinarySearchTreeNode *nodes[binarySearchTreeSize];
	int currentIndex = 0;

	postOrderTraversalBinarySearchTree(binarySearchTree, nodes, &currentIndex);
	printArray(nodes, binarySearchTreeSize);

}
