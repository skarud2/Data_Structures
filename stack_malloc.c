//동적 메모리 할당한 배열을 이용한 스택 구현
#include <stdio.h>
#include <stdlib.h>

//스택 => 구조체로 정의
typedef int element;
typedef struct {
    element *data;  //data 포인터로 정의
    int capacity; //현재 크기
    int top;
} StackType;


//스택 초기화
void init_stack(StackType *s) {
    s->top=-1;
    s->capacity=1;
    s->data=(element *)malloc(s->capacity * sizeof(element));
}

//비어있는 상태인지 확인
int is_empty(StackType *s){
    return (s->top == -1);
}

//포화 상태인지 확인
int is_full(StackType *s){
    return (s->top == (s->capacity -1));
}

//삽입
void push(StackType *s, element item) {
    if (is_full(s)) {        //포화상태였을 경우, 
        s->capacity *= 2;   //!!동적할당 통해서 메모리 크기 2배로 늘림!!
        s->data = (element *)realloc(s->data, s->capacity * sizeof(element));   //realloc =>기존 메모리 공간 재할당
        return;
    }
    s->data[++(s->top)]=item;
}

//삭제
element pop(StackType *s) {
    if (is_empty(s)) {
        fprintf(stderr, "스택 공백 에러\n");
        exit(1);
    }
    else {
        return s->data[(s->top)--];
    }
}