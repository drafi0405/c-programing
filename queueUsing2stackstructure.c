#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <malloc.h>
#define MAX 4
typedef struct stack{
    int top;
    int data[MAX];
}S;
typedef struct queue{
    S *s1;
    S *s2;
}Q;
bool isStackFull(S *s){
    return s->top == MAX - 1;
}
bool isStackEmpty(S *s){
    return s->top == -1;
}

void initialize(Q *q){
    q->s1 = (S*)malloc(sizeof(S));
    q->s2 = (S*)malloc(sizeof(S));
    q->s1->top = -1;
    q->s2->top = -1;
}
void push(S *s, int val){
    if(isStackFull(s)){
        printf("stack is full to enque the %d\n",val);
        return;
    }
    s->data[++(s->top)] = val;
    //printf("enqueue value %d\n", s->data[s->top]);
}
void enque(Q *q, int val){
    push(q->s1, val);
}

int pop(S *s){
    if(isStackEmpty(s)){
        printf("stack is empty\n");
        return -1;
    }
    return s->data[(s->top)--];
}
void deque(Q *q){
    int x;
    if(isStackEmpty(q->s1) && isStackEmpty(q->s2)){
        printf("Queue is empty\n");
    }else{
        if(isStackEmpty(q->s2)){
            while(!isStackEmpty(q->s1)){
                x = pop(q->s1);
                push(q->s2, x);
            }
        }else{
            x = pop(q->s2);
             printf("dequeued element is %d\n",x);
        }
    }
}
void displayqueue(Q *q){
    int i;
    printf("Queue elements : ");
    for(i=q->s2->top;i>=0;i--)
        printf("%d.. ",q->s2->data[i]);
    for(i=0;i<=q->s1->top;i++)
        printf("%d. ",q->s1->data[i]);
    printf("\n");
}

int main()
{
    Q q;
    initialize(&q);
    int a=10;
    enque(&q, a++);
    enque(&q, a++);
    enque(&q, a++);
    enque(&q, a++);
    enque(&q, a++);
    enque(&q, a++);
    enque(&q, a++);
    displayqueue(&q);
    deque(&q);
    displayqueue(&q);
    deque(&q);
    displayqueue(&q);
    deque(&q);
    displayqueue(&q);
        deque(&q);
    displayqueue(&q);
        deque(&q);
    displayqueue(&q);
        deque(&q);
    displayqueue(&q);
    return 0;
}