#include <stdio.h>

typedef struct Tree {
	int value;
	Tree * left;
	Tree * right;
} Tree;

Tree * InsertData(Tree * tree, int i)
{
	if (tree)
	{
		if (i > tree->value)InsertData(tree->right, i);
		else InsertData(tree->left, i);
	}
	else
	{
		tree = (Tree *)malloc(sizeof(Tree));
		tree->value = i;
		tree->left = NULL;
		tree->right = NULL;
	}
}

void DeleteData(Tree * tree, int i)
{

}

int main()
{


	return 0;
}