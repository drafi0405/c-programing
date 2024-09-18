#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    int data;
    struct node *next;
}Node;
typedef struct queue{
    Node *rear, *front;
}Queue;
Queue *createqueue(void){
    Queue *q = (Queue *)malloc(sizeof(Queue));
    q->rear = q->front = NULL;
    return q;
}
Node *newnode(int val){
    Node *new = (Node *)malloc(sizeof(Node));
    if(new == NULL){
        printf("mem loc failed exiting\n");
        exit(1);
    }
    new->data = val;
    new->next = NULL;
    return new;
}
void enqueue(Queue *q, int val){
    Node *new = newnode(val);
    if(q->rear == NULL){
        q->rear = q->front = new;
    }else{
        q->rear->next = new;
        q->rear = new;  
    }
    printf("%d enqueued\n",q->rear->data);
}
int isempty(Queue *q){
    return(q->front == NULL);
}
int peek(Queue *q){
    if(!isempty(q)){
        return q->front->data;
    }
}
int dequeue(Queue *q){
    if(isempty(q)){
        printf("Queue is empty exiting\n");
        exit(1);
    }
    Node *tmp = q->front;
    int deq_element = tmp->data;
    q->front = q->front->next;
    
    if(q->front == NULL)
        q->rear = NULL;
    free(tmp);
    return deq_element;
}
int main(){
    Queue  *q = createqueue();
    enqueue(q, 10);
    enqueue(q, 20);
    enqueue(q, 30);
    printf("%d peek element of Queue\n",peek(q));
    printf("%d dequeued element\n", dequeue(q));
    printf("%d peek element of Queue\n",peek(q));
    return 0;
}