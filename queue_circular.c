//원형큐
#include <stdio.h>
#include <stdlib.h>
#define MAX_QUEUE_SIZE 5

typedef int element;
typedef struct {
    int front;  //!!큐의 첫번째 요소의 하나 앞(전)을 가리킴!!
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
    q->front = q->rear = 0;
}

//비어있는 상태인지 확인
int is_empty(QueueType *q) {
    return (q->front == q->rear);
}

//포화 상태인지 확인:: 다음에 추가할 위치(rear+1)==front =>포화상태O
int is_full(QueueType *q) {
    return ((q->rear+1) % MAX_QUEUE_SIZE == q->front);
}   

//삽입:: rear 증가 -> 증가된 위치에 삽입
void enqueue(QueueType *q, element item) {
    if (is_full(q)) {
        error("큐가 포화상태입니다.\n");
        return;
    }
    q->rear = (q->rear+1) % MAX_QUEUE_SIZE;
    q->data[q->rear]=item;
}

//삭제:: front 증가 -> 증가된 위치에서 삭제
element dequeue(QueueType *q){
    if (is_empty(q)) {
        error("큐가 공백상태입니다.\n");
        return -1;
    }
    q->front = (q->front+1) % MAX_QUEUE_SIZE;
    return q->data[q->front];
}