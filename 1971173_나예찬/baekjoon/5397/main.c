#include <stdio.h>
#include <stdlib.h>
#include <conio.h>


typedef struct Node {
	int value;
	struct Node * next;
} Node;

typedef struct StackHead {
	Node * top;
	int count;
	int (*empty)(struct StackHead *);
	void (*push)(struct StackHead *, int);
	void (*pop)(struct StackHead *);
} StackHead;

int empty(StackHead * stack)
{
	return stack->count == 0;
}

void push(StackHead * stack, int value)
{
	Node * tmp = stack->top;
	stack->top = (Node *)malloc(sizeof(Node));
	stack->top->value = value;
	stack->top->next = tmp;
	++stack->count;

}

void pop(StackHead * stack)
{
	Node * tmp = stack->top;
	stack->top = stack->top->next;
	free(tmp);
	--stack->count;
}



void InitStack(StackHead * stack)
{
	stack->top = NULL;
	stack->count = 0;
	stack->empty = empty;
	stack->push = push;
	stack->pop = pop;
}

void DeleteStack(StackHead * stack)
{
	while (stack->top)
	{
		Node * node = stack->top->next;
		free(stack->top);
		stack->top = node;
	}
	free(stack);
}

int main()
{
	

	int T;
	scanf("%d ", &T);

	for (int i = 0; i < T; ++i)
	{
		StackHead * lChar = (StackHead *)malloc(sizeof(StackHead));
		StackHead * rChar = (StackHead *)malloc(sizeof(StackHead));
		InitStack(lChar);
		InitStack(rChar);
		while (1)
		{
			char ch = getchar();
			if (ch == '\n') break;
			else if (ch == '<')
			{
				if (!lChar->empty(lChar))
				{
					char tmp = lChar->top->value;
					rChar->push(rChar, tmp);
					lChar->pop(lChar);
				}
			}
			else if (ch == '>')
			{
				if (!rChar->empty(rChar))
				{
					char tmp = rChar->top->value;
					lChar->push(lChar, tmp);
					rChar->pop(rChar);
				}
			}
			else if (ch == '-')
			{
				if (!lChar->empty(lChar))
				{
					lChar->pop(lChar);
				}
			}
			else
			{
				lChar->push(lChar, ch);
			}
		}
		while (!lChar->empty(lChar))
		{
			char tmp = lChar->top->value;
			lChar->pop(lChar);
			rChar->push(rChar, tmp);
		}
		while (!rChar->empty(rChar))
		{
			printf("%c", rChar->top->value);
			rChar->pop(rChar);
		}
		printf("\n");
		DeleteStack(lChar);
		DeleteStack(rChar);
	}

	
	return 0;

}