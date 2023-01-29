#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_STACK 10000

typedef struct {
    int stack[MAX_STACK];
    int top;
} StackType;

void init_stack(StackType *s)
{
    s->top = -1;
}

int is_empty(StackType *s)
{
    if(s->top == -1)
        return 1;
    else
        return 0;
}

int is_full(StackType *s)
{
    if(s->top == MAX_STACK - 1)
        return 1;
    else
        return 0;
}

void push(StackType *s, int item)
{
    if(is_full(s)){
        printf("full!\n");
    }
    else
        s->stack[++(s->top)] = item;
}

int pop(StackType *s)
{
    if(is_empty(s)){
        return -1;
    }
    else
        return s->stack[(s->top)--];
}

int peek(StackType *s)
{
    if(is_empty(s)){
        return -1;
    }
    else
        return s->stack[s->top];
}

int size(StackType *s)
{
    int count = 0;
    if(is_empty(s)){
        return 0;
    }
    while(count != s->top){
        count++;
    }
    return count + 1;
}

int main(void)
{
    StackType s;
    init_stack(&s);

    int n;
    char command[6];

    int N;
    scanf("%d", &N);

    for(int i = 0; i < N; i++){
        scanf("%s", command);

        if(strcmp(command, "push") == 0){
            scanf("%d", &n);
            push(&s, n);
        }
        else if(strcmp(command, "top") == 0){
            printf("%d\n", peek(&s));
        }
        else if(strcmp(command, "size") == 0){
            printf("%d\n", size(&s));
        }
        else if(strcmp(command, "empty") == 0){
            printf("%d\n", is_empty(&s));
        }
        else if(strcmp(command, "pop") == 0){
            printf("%d\n", pop(&s));
        }
    }
    return 0;
}