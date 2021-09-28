#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define WORD_SIZE 16

typedef struct BinarySearchTreeNode {
	char value[WORD_SIZE];
	struct BinarySearchTreeNode *left;
	struct BinarySearchTreeNode *right;
} BinarySearchTreeNode;

/* Constructor and Destructor */

BinarySearchTreeNode *createBinarySearchTree(char *value);
void destroyBinarySearchTree(BinarySearchTreeNode *binarySearchTree);

/* Insert and Delete */

int insertValueBinarySearchTree(BinarySearchTreeNode *binarySearchTree, char *value);
BinarySearchTreeNode *removeValueBinarySearchTree(BinarySearchTreeNode *binarySearchTree, char *value);

/* Tree Dimension Functions */

int getSizeBinarySearchTree(BinarySearchTreeNode *binarySearchTree);
int getDepthBinarySearchTree(BinarySearchTreeNode *binarySearchTree);

/* Tree Traversal Functions */

void inOrderTraversalBinarySearchTree(BinarySearchTreeNode *binarySearchTree, BinarySearchTreeNode **nodesArrayPointer, int *currentIndexPointer);
void preOrderTraversalBinarySearchTree(BinarySearchTreeNode *binarySearchTree, BinarySearchTreeNode **nodesArrayPointer, int *currentIndexPointer);
void postOrderTraversalBinarySearchTree(BinarySearchTreeNode *binarySearchTree, BinarySearchTreeNode **nodesArrayPointer, int *currentIndexPointer);

#endif
