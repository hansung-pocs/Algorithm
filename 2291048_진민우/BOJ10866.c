#include <stdio.h>
#include <string.h>
#define MAX_SIZE 10000

typedef int element;
typedef struct {
    int front;
    int rear;
    int data[MAX_SIZE];
} DequeType;

void init_deque(DequeType *dq) {
    dq->front = 0;
    dq->rear = 0;
    for(int i = 0; i < MAX_SIZE; i++) {
        dq->data[i] = 0;
    }
}

void push_front(DequeType *dq, element item) {
    dq->data[dq->front] = item;
    dq->front = (dq->front - 1 + MAX_SIZE) %  MAX_SIZE;
}

void push_back(DequeType *dq, element item) {
    dq->rear = (dq->rear + 1) % MAX_SIZE;
    dq->data[dq->rear] = item;
}

element pop_front(DequeType *dq) {
    int value;
    if(dq->front == dq->rear) {
        return -1;
    }
    else {
        dq->front = (dq->front + 1) % MAX_SIZE;
        value = dq->data[dq->front];
        dq->data[dq->front] = 0;
        return value;
    }
}

element pop_back(DequeType *dq) {
    int value;
    if(dq->front == dq->rear) {
        return -1;
    }
    else {
        value = dq->data[dq->rear];
        dq->data[dq->rear] = 0;
        dq->rear = (dq->rear - 1 + MAX_SIZE) % MAX_SIZE;
        return value;
    }
}

int size(DequeType *dq) {
    int size = 0;
    for(int i = 0; i < MAX_SIZE; i++) {
        if(dq->data[i] != 0) {
            size++;
        }
    }
    return size;
}

void empty(DequeType *dq) {
    if(dq->front == dq->rear) {
        printf("1\n");
    }
    else {
        printf("0\n");
    }
}

void front(DequeType *dq) {
    int value;
    if(dq->front == dq->rear) {
        printf("-1\n");
    }
    else {
        value = dq->data[(dq->front + 1) % MAX_SIZE];
        printf("%d\n", value);
    }
}

void back(DequeType *dq) {
    int value;
    if(dq->front == dq->rear) {
        printf("-1\n");
    }
    else {
        value = dq->data[dq->rear];
        printf("%d\n", value);
    }
}

int main(void){
    int value;
    char command[11];
    int N;
    scanf("%d", &N);

    DequeType dq;
    init_deque(&dq);


    for(int i = 0; i < N; i++) {
        scanf("%s", command);
        if(strcmp(command, "push_front") == 0) {
            scanf("%d", &value);
            push_front(&dq, value);
        }
        else if(strcmp(command, "push_back") == 0) {
            scanf("%d", &value);
            push_back(&dq, value);
        }
        else if(strcmp(command, "pop_front") == 0) {
            printf("%d\n", pop_front(&dq));
        }
        else if(strcmp(command, "pop_back") == 0) {
            printf("%d\n", pop_back(&dq));
        }
        else if(strcmp(command, "size") == 0) {
            printf("%d\n", size(&dq));
        }
        else if(strcmp(command, "empty") == 0) {
            empty(&dq);
        }
        else if(strcmp(command, "front") == 0) {
            front(&dq);
        }
        else if(strcmp(command, "back") == 0) {
            back(&dq);
        }
    }
    return 0;
}