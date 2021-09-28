#include "BinarySearchTree.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define PREFIX_BUFFER_SIZE 256

void flushStandardInput();
char *readStandardInput(char *buffer, int length);

void printBinarySearchTree(BinarySearchTreeNode *binarySearchTree, char *prefix, int isLeft);

void printInOrder(BinarySearchTreeNode *binarySearchTree);
void printPreOrder(BinarySearchTreeNode *binarySearchTree);
void printPostOrder(BinarySearchTreeNode *binarySearchTree);

int main(void)
{
	BinarySearchTreeNode *binarySearchTree = NULL;

	while (1)
	{
		char input[WORD_SIZE] = {};

		printf("Please enter a word (to remove a word, prefix it with - and to quit the program, input *):\n");
		readStandardInput(input, WORD_SIZE);
		printf("\n");

		if (input[0] == '*')
			break;

		if (input[0] != '-')
		{
			if (binarySearchTree == NULL)
				binarySearchTree = createBinarySearchTree(input);
			else
				insertValueBinarySearchTree(binarySearchTree, input);
		}
		else
		{
			for (int counter = 0; input[counter] != '\0'; counter++)
				input[counter] = input[counter + 1];

			binarySearchTree = removeValueBinarySearchTree(binarySearchTree, input);
		}

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

void flushStandardInput()
{
	char c;
	while ((c = getchar()) != '\n' && c != EOF)
		;
}

char *readStandardInput(char *buffer, int length)
{
	if (!fgets(buffer, length, stdin))
		buffer = NULL;

	int actualLength = strlen(buffer);
	if (actualLength == length - 1)
		flushStandardInput();

	if (buffer[actualLength - 1] == '\n')
		buffer[actualLength - 1] = '\0';

	return buffer;
}

void printBinarySearchTree(BinarySearchTreeNode *binarySearchTree, char *prefix, int isLeft)
{
	if (binarySearchTree == NULL)
		return;

	printf("%s", prefix);
	printf(isLeft ? "├──" : "└──");
	printf("%s", binarySearchTree->value);
	printf("\n");
	
	char newPrefix[PREFIX_BUFFER_SIZE] = {};
	strcat(newPrefix, prefix);
	strcat(newPrefix,  (isLeft ? "│   " : "    "));

	printBinarySearchTree(binarySearchTree->left, newPrefix, 1);
	printBinarySearchTree(binarySearchTree->right, newPrefix, 0);
}

void printArray(BinarySearchTreeNode **array, int length)
{
	for (int index = 0; index < length; index++)	
		printf("%s, ", (*(array + index))->value);
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
