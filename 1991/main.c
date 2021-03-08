#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int c = 0;
typedef struct Tree {
	struct Tree * left;
	struct Tree * right;
	int ch;
} Tree;

typedef struct List {
	Tree * data;
	struct List * next;
} List;


void InitTreeNode(int ch, Tree * node)
{
	node->ch = ch;
	node->left = NULL;
	node->right = NULL;
}

void InitList(List * list)
{
	list->data = NULL;
	list->next = NULL;
}


void ListAdd(List * list, Tree * tree)
{
	if (list->data)
	{
		List * itr = list;
		while (itr->next)
		{
			itr = itr->next;
		}
		itr->next = (List *)malloc(sizeof(List));
		itr->next->next = NULL;
		itr->next->data = tree;
	}
	else
	{
		list->data = tree;
	}
}

List * FindTree(List * list, int ch)
{
	while (list)
	{
		if (list->data->ch == ch)
			return list;
		list = list->next;
	}
	return NULL;
}

void ListDescend(List * list)
{
	if (list->data->left && list->data->right)
	{
		List * newNode = (List *)malloc(sizeof(List));
		newNode->data = list->data->right;
		list->data = list->data->left;
		newNode->next = list->next;
		list->next = newNode;
	}
	if (!list->data->left && !list->data->right)
		return;
	else
	{
		if (list->data->left)
		{
			list->data = list->data->left;
		}
		else if (list->data->right)
		{
			list->data = list->data->right;
		}
	}
}

void preorder(Tree * tree)
{
	printf("%d ", tree->ch);
	++c;
	if (c % 10 == 0)
		printf("\n");
	if(tree->left)
		preorder(tree->left);
	if (tree->right)
		preorder(tree->right);
}

void inorder(Tree * tree)
{
	if (tree->left)
		inorder(tree->left);
	printf("%d ", tree->ch);
	++c;
	if (c % 10 == 0)
		printf("\n");
	if (tree->right)
		inorder(tree->right);
}

void postorder(Tree * tree)
{
	if (tree->left)
		postorder(tree->left);
	if (tree->right)
		postorder(tree->right);
	printf("%d ", tree->ch);
	++c;
	if (c % 10 == 0)
		printf("\n");
}

int size(List * list)
{
	int count = 0;
	while (list)
	{
		++count;
		list = list->next;
	}
	return count;
}

int at(List * list, int n)
{
	for (int i = 0; i < n; ++i)
	{
		list = list->next;
	}
	return list->data->ch;
}

int main()
{
	srand(time(NULL));
	int n;
	scanf("%d", &n);

	Tree * rootNode = (Tree *)malloc(sizeof(Tree));
	InitTreeNode(1,rootNode);

	List * listNode = (List *)malloc(sizeof(List));
	InitList(listNode);
	listNode->data = rootNode;

	int cc = 1;

	for (int i = 0; i < n; ++i)
	{
		int dest, left=-1, right = -1;
		//scanf(" %c %c %c", &dest, &left, &right);
		int sz = size(listNode);
		dest = at(listNode, rand() % sz);
		if (rand() % 2)
		{
			left = ++cc;
		}
		if (rand() % 2)
		{
			right = ++cc;
		}

		if (left < -1)
			return 1;
		if (right < -1)
			return 1;
		if (dest < -1)
			return 1;

		List * lst = FindTree(listNode, dest);
		if (!lst)
			return 1;

		if (left != -1)
		{
			lst->data->left = (Tree *)malloc(sizeof(Tree));
			InitTreeNode(left, lst->data->left);
		}

		if (right != -1)
		{
			lst->data->right = (Tree *)malloc(sizeof(Tree));
			InitTreeNode(right, lst->data->right);
		}

		ListDescend(lst);
	}

	c = 0;
	preorder(rootNode);
	printf("\n\n");
	c = 0;
	inorder(rootNode);
	printf("\n\n");
	c = 0;
	postorder(rootNode);
	printf("\n\n");


}