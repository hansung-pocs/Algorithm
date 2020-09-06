#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
	struct Node * left;
	struct Node * right;
	int value;
} Node;

typedef struct DoubleLinkedList {
	Node * first;
} DoubleLinkedList;

void InitList(DoubleLinkedList * list)
{
	list->first = NULL;
}

void AddData(DoubleLinkedList * list, int value)
{
	if (list->first)
	{
		Node * itr = list->first;
		while (itr->right)
		{
			itr = itr->right;
		}
		itr->right = (Node *)malloc(sizeof(Node));
		itr->right->right = NULL;
		itr->right->left = itr;
	}
	else
	{
		list->first = (Node *)malloc(sizeof(Node));
		list->first->left = NULL;
		list->first->right = NULL;
	}

}


int main()
{
	DoubleLinkedList * list = (DoubleLinkedList *)malloc(sizeof(DoubleLinkedList));
	InitList(list);
}

