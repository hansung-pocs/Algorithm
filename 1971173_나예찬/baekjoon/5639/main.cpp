#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct Tree {
	int data;
	struct Tree* left, *right;
}Tree;
void init(Tree* l) {
	l->left = l->right = NULL;
}
void postorder(Tree* l) {
	if (l != NULL) {
		postorder(l->left);
		postorder(l->right);
		printf("%d\n", l->data);
	}
}

void push(Tree* l, int n) {
	while (1) {
		if (l->data > n)
		{
			if (l->left)
			{
				l = l->left;
			}
			else
			{
				l->left = (Tree*)malloc(sizeof(Tree));
				l->left->data = n;
				init(l->left);
				break;
			}
		}
		else
		{
			if (l->right)
			{
				l = l->right;
			}
			else
			{
				l->right = (Tree*)malloc(sizeof(Tree));
				l->right->data = n;
				init(l->right);
				break;
			}
		}
	}
}
int main() {
	int n;
	Tree* l = (Tree*)malloc(sizeof(Tree));
	init(l);
	scanf("%d", &n);
	l->data = n;


	while (scanf("%d", &n) != EOF) {
		push(l, n);
	}

	postorder(l);
	return 0;
}