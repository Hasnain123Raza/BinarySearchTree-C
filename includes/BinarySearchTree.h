#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H

#include <stdio.h>
#include <stdlib.h>

typedef struct BinarySearchTreeNode {
	int value;
	struct BinarySearchTreeNode *left;
	struct BinarySearchTreeNode *right;
} BinarySearchTreeNode;

/* Constructor and Destructor */

BinarySearchTreeNode *createBinarySearchTree(int value);
void destroyBinarySearchTree(BinarySearchTreeNode *binarySearchTree);

/* Insert and Delete */

int insertValueBinarySearchTree(BinarySearchTreeNode *binarySearchTree, int value);
BinarySearchTreeNode *removeValueBinarySearchTree(BinarySearchTreeNode *binarySearchTree, int value);

/* Tree Dimension Functions */

int getSizeBinarySearchTree(BinarySearchTreeNode *binarySearchTree);
int getDepthBinarySearchTree(BinarySearchTreeNode *binarySearchTree);

/* Tree Traversal Functions */

void inOrderTraversalBinarySearchTree(BinarySearchTreeNode *binarySearchTree, BinarySearchTreeNode **nodesArrayPointer, int *currentIndexPointer);
void preOrderTraversalBinarySearchTree(BinarySearchTreeNode *binarySearchTree, BinarySearchTreeNode **nodesArrayPointer, int *currentIndexPointer);
void postOrderTraversalBinarySearchTree(BinarySearchTreeNode *binarySearchTree, BinarySearchTreeNode **nodesArrayPointer, int *currentIndexPointer);

#endif
