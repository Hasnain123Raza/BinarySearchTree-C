#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H

#include <stdio.h>
#include <stdlib.h>

typedef struct BinarySearchTreeNode {
	int value;
	struct BinarySearchTreeNode *left;
	struct BinarySearchTreeNode *right;
} BinarySearchTreeNode;

BinarySearchTreeNode *createBinarySearchTree(int value);
void destroyBinarySearchTree(BinarySearchTreeNode *binarySearchTree);

int insertValueBinarySearchTree(BinarySearchTreeNode *binarySearchTree, int value);

#endif
