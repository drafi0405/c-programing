#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    int data;
    struct node *next;
}Node;
Node *newnode(int val){
    Node *new = (Node *)malloc(sizeof(Node));
    if(new == NULL){
        printf("mem alloc failed \n");
        exit(1);
    }
    new->data = val;
    new->next = NULL;
    return new;
}
void push(Node **top, int val){
    if(*top == NULL){
        *top = newnode(val);
        printf("%d pushed to stack\n",(*top)->data);
    }else{
        Node *new = newnode(val);
        new->next = *top;
        *top = new;
        printf("%d pushed to stack\n",(*top)->data);
    }
}
int isEmpty(Node *top){
    return (top == NULL);
}
int peek(Node *top){
    if(isEmpty(top)){
        printf("stack is underflow\n");
    }else{
        return top->data;
    }
}
int pop(Node **top){
    if(isEmpty(*top)){
        printf("stack is underflow\n");
    }else{
        Node *tmp = *top;
        int popelement = tmp->data;
        *top = (*top)->next;
        free(tmp);
        return popelement;
    }
}
int main(){
    Node *stack = NULL;
    push(&stack, 10);
    push(&stack, 20);
    push(&stack, 30);
    printf("Peek node %d\n",peek(stack));
    printf("Popped element is %d\n", pop(&stack));
    printf("Peek node %d",peek(stack));
    return 0;
}

