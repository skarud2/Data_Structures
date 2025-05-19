//일반적인 1차원 배열을 이용한 스택 구현
#include <stdio.h>
#include <stdlib.h>
#define MAX_STACK_SIZE 100

//스택 => 구조체로 정의
typedef int element;
typedef struct {
    element data[MAX_STACK_SIZE];
    int top;
} StackType;

//스택 초기화
void init_stack(StackType *s) {
    s->top = -1;
}

//비어있는 상태인지 확인
int is_empty(StackType *s) {
    return (s->top==-1);   //비어있으면 1, 아니면 0
}

//포화 상태인지 확인
int is_full(StackType *s) {
    return (s->top == (MAX_STACK_SIZE -1));   //포화상태면 1, 아니면 0
}

//삽입
void push(StackType *s, element item) {
    if (is_full(s)){        
        fprintf(stderr, "스택 포화 에러\n");
        return;
    }
    else {  //포화 상태가 아니면 삽입
        s->data[++(s->top)]=item;
    }
}

//삭제
element pop(StackType *s) {
    if (is_empty(s)) {
        fprintf(stderr, "스택 공백 에러\n");
        exit(1);
    }
    else {   //비어있지 않으면 삭제
        return s->data[(s->top)--];
    }
}

//스택의 top 리턴
element peek(StackType *s) {
    if (is_empty(s)){
        fprintf(stderr, "스택 공백 에러\n");
        exit(1);
    }
    else {
        return s->data[s->top];
    }
}