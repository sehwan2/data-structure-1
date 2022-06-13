#include <stdio.h>
#include <stdlib.h>
#define MAX_QUEUE_SIZE 5

typedef int element;
typedef struct {
	int rear;
	int front;
	element data[MAX_QUEUE_SIZE];
}QueueType;

void error(char* message)
{
	fprintf(stderr, "%s\n", message);
	exit(1);
}

void init_queue(QueueType* q)
{
	q->front = q->rear = 0;
}

int is_empty(QueueType* q)
{
	return (q->front == q->rear);
}
int is_full(QueueType* q)
{
	return((q->rear + 1) % MAX_QUEUE_SIZE == q->front);
}
void queue_print(QueueType* q)
{
	printf("QUEUE(front=%d rear =%d) = ", q->front, q->rear);
	if (!is_empty(q)) {
		int i = q->front;
		do {
			i = (i + 1) % (MAX_QUEUE_SIZE);
			printf("%d | ", q->data[i]);
			if (i == q->rear)
				break;
		} while (i != q->front);
	}
	printf("\n");
}
void enqueue(QueueType* q, element item)
{
	if (is_full(q))
		error("포화");
	q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
	q->data[q->rear] = item;
}
element dequeue(QueueType* q)
{
	if (is_empty(q))
		error("공백");
	q->front = (q->front + 1) % MAX_QUEUE_SIZE;
	return q->data[(q->front)];
}

element peek(QueueType* q)
{
	if (is_empty(q))
		error("공백");
	return q->data[(q->front + 1) % MAX_QUEUE_SIZE];
}
int main(void)
{
	QueueType q;
	int element;

	init_queue(&q);
	while (!is_full(&q))
	{
		printf("정수입력");
		scanf_s("%d", &element);
		enqueue(&q, element);
		queue_print(&q);
	}
	printf("큐는 포화상태\n");

	while (!is_empty(&q))
	{
		element = dequeue(&q);
		printf("꺼내진 정수: %d \n", element);
		queue_print(&q);
	}
	printf("큐는 공백상태\n");
	return 0;
}
