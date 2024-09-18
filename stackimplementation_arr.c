#include<stdio.h>
#include<stdlib.h>
#define STACK_SIZE 5
int stack_top = -1;
int arr[STACK_SIZE];
int stack_full(void){
    if(stack_top == STACK_SIZE){
        return 1;
    }
    return 0;
}
int stack_empty(void){
    if(stack_top == -1)
        return 1;
    else
        return 0;
}
void push(int arr[], int val){
    if(stack_full()){
        printf("stack is full to push %d\n",val);
        //exit(1);
    }else{
        stack_top++;
        arr[stack_top] = val;
    }
}
void pop(int arr[]){
    if(stack_empty()){
        printf("stack is empty\n");
        //exit(1);
    }else{
        printf("\npopped element is %d\n", arr[stack_top--]);
    }
}
void printstack(int arr[]){
    if(!stack_empty()){
        for(int i=stack_top;i>=0;i--){
            printf("%d ",arr[i]);
        }
    }
}
int main(){
    push(arr, 10);
    push(arr, 20);
    push(arr, 30);
    printstack(arr);
    pop(arr);
    printstack(arr);
    pop(arr);
    pop(arr);
    pop(arr);
    push(arr, 10);
    push(arr, 20);
    push(arr, 30);
    push(arr, 40);
    push(arr, 50);
    printstack(arr);
    push(arr, 60);
    printf("\n");
    printstack(arr);
    printf("\n");
    push(arr, 70);
    printf("\n");
    printstack(arr);
    
    return 0;
}