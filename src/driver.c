#include <stdio.h>

void printBinarySearchTree(BinarySearchTreeNode *binarySearchTree)
{

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

		printBinarySearchTree(binarySearchTree);
	}

	printf("Goodbye!\n");
}
