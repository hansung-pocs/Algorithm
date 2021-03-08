#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct {
	int front;
	int rear;
	element data[101];
}QueueType;

void init_queue(QueueType* q) {
	q->rear = q->front = 0;
}
void enqueue(QueueType* q, int i) {
	q->rear = (q->rear + 1) % 100;
	q->data[q->rear] = i;
}
int dequeue(QueueType* q) {
	q->front = (q->front + 1) % 100;
	return q->data[q->front];
}

int main() {
	int count, n, m, i, j, importance, numcount, tmp, trash, num_count;
	QueueType q;

	scanf("%d", &count);
	while (count--) {
		init_queue(&q);
		numcount = 0;
		num_count = 0;
		scanf("%d %d", &n, &m);
		for (i = 0; i < n; i++) {
			scanf("%d", &importance);
			enqueue(&q, importance);
		}
		for (i = 1; i < n + 1; i++) {
			for (j = i + 1; j < n + 1; j++) {
				if (q.data[i + num_count] < q.data[j + num_count]) {
					tmp = dequeue(&q);
					enqueue(&q, tmp);
					if (m == 0)
						m = n - 1;
					else
						m--;
				}
				numcount++;
			}
			trash = dequeue;
			num_count = numcount;
		}
		printf("%d\n", m + 1);
	}

	return 0;
}