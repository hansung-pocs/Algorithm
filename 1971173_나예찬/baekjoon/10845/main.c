#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
	int value;
	struct node * next;
} node;

typedef struct Queue {
	struct node * head;
	struct node * tail;
	int size;
} Queue;

Queue * Init()
{
	Queue * queue = (Queue *)malloc(sizeof(Queue));
	queue->head = queue->tail = NULL;
	queue->size = 0;
	return queue;
}

void push(Queue * queue, int data)
{
	if (!queue->size)
	{
		queue->head = (node *)malloc(sizeof(node));
		queue->head->value = data;
		queue->head->next = NULL;
		queue->tail = queue->head;

		++queue->size;
	}
	else
	{
		queue->tail->next = (node *)malloc(sizeof(node));
		queue->tail = queue->tail->next;
		queue->tail->value = data;
		queue->tail->next = NULL;
		++queue->size;
	}
}

int pop(Queue * queue)
{
	int Value = -1;
	if (queue->size)
	{
		node * tmp = queue->head;
		Value = queue->head->value;
		queue->head = queue->head->next;
		free(tmp);
		--queue->size;
		if (!queue->head) queue->tail = NULL;
	}
	return Value;
}



int main()
{
	Queue * queue = Init();


	int n;


	scanf("%d", &n);
	char instruction[6];
	for (int i = 0; i < n; ++i)
	{
		scanf("%s", instruction);
		if (!strcmp("push", instruction))
		{
			int count;
			scanf("%d", &count);
			push(queue, count);
		}
		else if (!strcmp("pop", instruction))
		{
			printf("%d\n",pop(queue));
		}
		else if (!strcmp("size", instruction))
		{
			printf("%d\n", queue->size);
		}
		else if (!strcmp("empty", instruction))
		{
			printf("%d\n", queue->size<=0);
		}
		else if (!strcmp("front", instruction))
		{
			printf("%d\n", queue->size ? queue->head->value : -1);
		}
		else if (!strcmp("back", instruction))
		{
			printf("%d\n", queue->size ? queue->tail->value : -1);
		}
	}
	return 0;
}