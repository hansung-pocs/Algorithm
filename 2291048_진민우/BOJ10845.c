#include <stdio.h>
#include <string.h>

#define MAX_SIZE 10000

typedef int element;
typedef struct {
    int front;
    int rear;
    int data[MAX_SIZE];
} QueueType;

void init_queue(QueueType *q) {
    q->front = -1; //front rear -1부터 시작함
    q->rear = -1;
}

void push(QueueType *q, element item) {
    q->data[++(q->rear)] = item; //rear를 증가 시키고 데이터 삽입
}

element pop(QueueType *q) {
    if (q->front == q->rear) {
        return -1;
    }
    int value;
    value = q->data[++(q->front)]; //front를 증가 시키고 데이터 꺼냄
    return value;
}

int size(QueueType *q) {
    int size = q->rear - q->front; //rear위치에서 front위치를 빼면 사이즈
    return size;
}

void front(QueueType *q) {
    if (q->front == q->rear) {
        printf("-1\n");
    } else {
        int value = q->data[(q->front + 1)]; //front에서 한칸 뒤에있는 것 출력
        printf("%d\n", value);
    }
}

void back(QueueType *q) {
    if (q->front == q->rear) {
        printf("-1\n");
    } else {
        int value = q->data[(q->rear)]; //rear위치에 있는 것 그대로 출력
        printf("%d\n", value);
    }
}

void empty(QueueType *q) {
    if (q->front == q->rear)
        printf("1\n"); //비어있으면
    else
        printf("0\n"); //아니면
}

int main(void) {
    char command[6]; //명령어
    int value = 0;

    QueueType q; //구조체 변수 생성
    init_queue(&q); //구조체 초기화

    int N; //명령 횟수
    scanf("%d", &N);

    for (int i = 0; i < N; i++) {
        scanf("%s", command);

        if (strcmp(command, "push") == 0) {
            scanf("%d", &value);
            push(&q, value);
        } else if (strcmp(command, "pop") == 0) {
            printf("%d\n", pop(&q));
        } else if (strcmp(command, "size") == 0) {
            printf("%d\n", size(&q));
        } else if (strcmp(command, "empty") == 0) {
            empty(&q);
        } else if (strcmp(command, "front") == 0) {
            front(&q);
        } else if (strcmp(command, "back") == 0) {
            back(&q);
        }
    }

    return 0;
}
