#include<stdio.h>
#include<malloc.h>
typedef struct node{
    int data;
    struct node *next;
}Node;
Node *newnode(int val){
    Node *new=(Node *)malloc(sizeof(Node));
    new->data = val;
    new->next=NULL;
    return new;
}
void reverselist(Node **head){
    Node *prev=NULL;
    Node *cur=*head;
    Node *tmp=NULL;
    while(cur){
        tmp = cur->next;
        cur->next = prev;
        prev = cur;
        cur =tmp;
    }
    *head = prev;
}
void printlist(Node *head){
    while(head){
        printf("%d->", head->data);
        head=head->next;
    }
    printf("\n");
}
int main(){
    Node *head=NULL;
    head = newnode(10);
    head->next = newnode(20);
    head->next->next = newnode(30);
    printlist(head);
    reverselist(&head);
    printlist(head);
    return 0;
    
}