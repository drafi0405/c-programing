#include <stdio.h>
#include <stdbool.h>
#define MAX 3
int s1arr[MAX];
int s2arr[MAX];
int s1top = -1;
int s2top = -1;
bool isStack1full(int s1arr[]){
    return s1top == (MAX-1);
}
bool isStack2full(int s2arr[]){
    return s2top == (MAX-1);
}
bool isStack2Empty(int s2arr[]){
    return s2top == -1;
}
void stack2(int s2arr[], int val){
    if(isStack2full(s2arr)){
        printf("stack2 is full\n");
    }else{
         s2arr[++s2top] = val;
         printf("enque element %d\n", s2arr[s2top]);
    }
}
void stack1(int s1arr[], int val){
    if(isStack1full(s1arr)){
        printf("stack1 is full so fill the stack2\n");
        for(int i=0;i<MAX;i++){
            stack2(s2arr, s1arr[s1top]);
            s1arr[s1top--] = -99;
        }
    }else{
        s1arr[++s1top] = val;
        printf("enque element %d\n", s1arr[s1top]);
    }
}

void enque(int val){
    stack1(s1arr, val);
}

void deque(){
    if(isStack2Empty(s2arr)){
        printf("stack is empty\n");
    }else{
        printf("deque element is %d\n", s2arr[s2top]);
        s2arr[s2top] = -99;
        s2top--;
    }
}
int main()
{
    int val = 1;
    enque(val++);
    enque(val++);
    enque(val++);
    enque(val++);
    deque();
    deque();
    deque();
    deque();
    return 0;
}