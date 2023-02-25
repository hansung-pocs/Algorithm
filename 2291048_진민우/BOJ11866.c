#include <stdio.h>
#define MAX_SIZE 1000000

typedef int element;
typedef struct {
    int front;
    int rear;
    element data[MAX_SIZE];
} QueueType;

void init_queue(QueueType *q) {
    q->front = 0;
    q->rear = 0;
}

void push(QueueType *q, element item) {
    q->data[++(q->rear)] = item;
}

element pop(QueueType *q) {
    element value;
    value = q->data[++(q->front)];
    return value;
}

int is_empty(QueueType *q) {
    if (q->front == q->rear) {
        return 1; //비어있음
    } else {
        return 0;
    }
}

int main(void) {
    QueueType q;
    init_queue(&q);

    QueueType store; //저장할 큐
    init_queue(&store);

    int N;
    int K;
    int item;

    scanf("%d %d", &N, &K);
    //데이터 삽입
    for (int i = 1; i <= N; i++) {
        push(&q, i);
    }

    while (is_empty(&q) != 1) {
        for(int i = 0; i < K - 1; i++) {
            item = pop(&q); //앞에서 꺼내서
            push(&q, item); //뒤로 넣음
        }
        item = pop(&q); //맨 앞꺼
        push(&store, item); //다른 큐에 저장
    }

    //저장된 큐의 내용물 출력
    printf("<");
    for(int i = 1; i <= N ;i++) {
        if (i == N) {
            printf("%d>", store.data[i]);
        }else {
            printf("%d, ", store.data[i]);
        }
    }

    return 0;
}
