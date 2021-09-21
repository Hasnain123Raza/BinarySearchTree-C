#include "BinarySearchTree"

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
