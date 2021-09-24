#include "BinarySearchTree.h"

/* Constructor and Destructor */

BinarySearchTreeNode *createBinarySearchTree(int value)
{
	BinarySearchTreeNode *newNode = malloc(sizeof(BinarySearchTreeNode));
	if (!newNode)
		return NULL;
	newNode->value = value;
	newNode->left = NULL;
	newNode->right = NULL;

	return newNode;
}

void destroyBinarySearchTree(BinarySearchTreeNode *binarySearchTree)
{
	if (binarySearchTree->left)
		destroyBinarySearchTree(binarySearchTree->left);
	
	if (binarySearchTree->right)
		destroyBinarySearchTree(binarySearchTree->right);

	free(binarySearchTree);
}

/* Insert and Delete */

int insertValueBinarySearchTree(BinarySearchTreeNode *binarySearchTree, int value)
{
	if (value < binarySearchTree->value)
	{
		if (binarySearchTree->left)
			return insertValueBinarySearchTree(binarySearchTree->left, value);
		else
		{
			BinarySearchTreeNode *newNode = createBinarySearchTree(value);
			if (!newNode)
				return 0;
			binarySearchTree->left = newNode;
			return 1;
		}
	}
	else if (value > binarySearchTree->value)
	{
		if (binarySearchTree->right)
			return insertValueBinarySearchTree(binarySearchTree->right, value);
		else
		{
			BinarySearchTreeNode *newNode = createBinarySearchTree(value);
			if (!newNode)
				return 0;
			binarySearchTree->right = newNode;
			return 1;
		}
	}
	else
		return 0;	/* No Duplicates */
}

/* Tree Dimension Functions */

int getSizeBinarySearchTree(BinarySearchTreeNode *binarySearchTree)
{
	return 1 + (binarySearchTree->left ? getSizeBinarySearchTree(binarySearchTree->left) : 0) + (binarySearchTree->right ? getSizeBinarySearchTree(binarySearchTree->right) : 0);
}

int getHeightBinarySearchTree(BinarySearchTreeNode *binarySearchTree)
{

}

/* Tree Traversal Functions */

void inOrderTraversalBinarySearchTree(BinarySearchTreeNode *binarySearchTree, int *valuesArrayPointer, int *currentIndexPointer)
{
	if (binarySearchTree->left)
		inOrderTraversalBinarySearchTree(binarySearchTree->left, valuesArrayPointer, currentIndexPointer);

	*(valuesArrayPointer + *currentIndexPointer) = binarySearchTree->value;
	(*currentIndexPointer)++;

	if (binarySearchTree->right)
		inOrderTraversalBinarySearchTree(binarySearchTree->right, valuesArrayPointer, currentIndexPointer);
}

void preOrderTraversalBinarySearchTree(BinarySearchTreeNode *binarySearchTree, int *valuesArrayPointer, int *currentIndexPointer)
{
	*(valuesArrayPointer + *currentIndexPointer) = binarySearchTree->value;
	(*currentIndexPointer)++;

	if (binarySearchTree->left)
		preOrderTraversalBinarySearchTree(binarySearchTree->left, valuesArrayPointer, currentIndexPointer);
	
	if (binarySearchTree->right)
		preOrderTraversalBinarySearchTree(binarySearchTree->right, valuesArrayPointer, currentIndexPointer);
}

void postOrderTraversalBinarySearchTree(BinarySearchTreeNode *binarySearchTree, int *valuesArrayPointer, int *currentIndexPointer)
{
	if (binarySearchTree->left)
		postOrderTraversalBinarySearchTree(binarySearchTree->left, valuesArrayPointer, currentIndexPointer);
	
	if (binarySearchTree->right)
		postOrderTraversalBinarySearchTree(binarySearchTree->right, valuesArrayPointer, currentIndexPointer);

	*(valuesArrayPointer + *currentIndexPointer) = binarySearchTree->value;
	(*currentIndexPointer)++;
}
