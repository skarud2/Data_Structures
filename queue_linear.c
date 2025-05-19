//선형큐
#include <stdio.h>
#include <stdlib.h>
#define MAX_QUEUE_SIZE 5

typedef int element;
typedef struct {
    int front;  //큐의 첫번째 요소 가리킴
    int rear;   //큐의 마지막 요소 가리킴
    element data[MAX_QUEUE_SIZE];
} QueueType;

//오류 함수
void error(char *message) {
    fprintf(stderr, "%s\n", message);
    exit(1);
}

//초기화
void init_queue(QueueType *q) {
    q->front = q->rear = -1;
}

//비어있는 상태인지 확인
int is_empty(QueueType *q) {
    return (q->front == q->rear);
}

//포화 상태인지 확인
int is_full(QueueType *q) {
    return (q->rear == MAX_QUEUE_SIZE-1);
}

//삽입
void enqueue(QueueType *q, element item) {
    if (is_full(q)) {
        error("큐가 포화상태입니다.\n");
        return;
    }
    q->data[++(q->rear)]=item;
}

//삭제
int dequeue(QueueType *q) {
    if (is_empty(q)) {
        error("큐가 공백상태입니다.\n");
        return -1;
    }
    return q->data[++(q->front)];
}