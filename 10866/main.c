#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
	int value;
	struct Node * left;
	struct Node * right;
} Node;

typedef struct Deque {
	Node * begin;
	Node * end;
	int count;
} Deque;

void InitDeque(Deque * deque)
{
	deque->begin = NULL;
	deque->end = NULL;
	deque->count = 0;
}

void push(Deque * deque, int pos, int value)
{
	if (!deque->begin)
	{
		Node * newNode = (Node *)malloc(sizeof(Node));
		newNode->value = value;
		newNode->left = newNode->right = NULL;
		deque->begin = deque->end = newNode;
		++deque->count;
	}
	else if (pos)
	{
		Node * newNode = (Node *)malloc(sizeof(Node));
		deque->end->right = newNode;
		newNode->left = deque->end;
		newNode->right = NULL;
		newNode->value = value;
		deque->end = newNode;
		++deque->count;
	}
	else
	{
		Node * newNode = (Node *)malloc(sizeof(Node));
		deque->begin->left = newNode;
		newNode->left = NULL;
		newNode->right = deque->begin;
		newNode->value = value;
		deque->begin = newNode;
		++deque->count;
	}
}

int pop(Deque * deque, int pos)
{
	int result;
	if (!deque->begin)
	{
		result = -1;
	}
	else if (pos)
	{
		Node * tmp = deque->end;
		deque->end = deque->end->left;
		if (!deque->end)
			deque->begin = NULL;
		else
			deque->end->right = NULL;
		result = tmp->value;
		free(tmp);
		--deque->count;

	}
	else
	{
		Node * tmp = deque->begin;
		deque->begin = deque->begin->right;
		if (!deque->begin)
			deque->end = NULL;
		else
			deque->begin->left = NULL;
		result = tmp->value;
		free(tmp);
		--deque->count;
	}
	return result;
}

int main()
{
	Deque * deque;
	deque = (Deque *)malloc(sizeof(Deque));
	InitDeque(deque);

	int N;
	scanf("%d", &N);
	for (int i = 0; i < N; ++i)
	{
		char instruction[11];
		scanf("%s", instruction);
		if (!strcmp(instruction, "push_front"))
		{
			int value;
			scanf("%d", &value);
			push(deque, 0, value);
		}
		else if (!strcmp(instruction, "push_back"))
		{
			int value;
			scanf("%d", &value);
			push(deque, 1, value);
		}
		else if (!strcmp(instruction, "pop_front"))
		{
			printf("%d\n", pop(deque, 0));
		}
		else if (!strcmp(instruction, "pop_back"))
		{
			printf("%d\n", pop(deque, 1));
		}
		else if (!strcmp(instruction, "size"))
		{
			printf("%d\n", deque->count);
		}
		else if (!strcmp(instruction, "empty"))
		{
			printf("%d\n", deque->count==0);
		}
		else if (!strcmp(instruction, "front"))
		{
			printf("%d\n", (deque->begin)?deque->begin->value:-1);
		}
		else if (!strcmp(instruction, "back"))
		{
			printf("%d\n", (deque->end)?deque->end->value:-1);
		}
	}

	
	
	return 0;
}