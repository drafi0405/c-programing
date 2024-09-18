#include<stdio.h>
#include<malloc.h>
typedef struct node{
    int data;
    struct node *next;
}Node;
Node *newnode(int v){
    Node *new=(Node *)malloc(sizeof(Node));
    new->data = v;
    new->next=NULL;
    return new;
}
int iscycle(Node *h){
    Node *f=h;
    Node *s=h;
    while(f && f->next){
        s= s->next;
        f = f->next->next;
        if(s == f)
            return 1;
    }
    return 0;
}
void freelist(Node *head){
    Node *tmp;
    while(head){
        tmp=head;
        head=head->next;
        free(tmp);  
    }
}
int middleelement(Node *h){
    Node *s=h;
    Node *f=h;
    while(f && f->next){
        s=s->next;
        f=f->next->next;
    }
    return s->data;
}
int main(){
   Node *head=NULL; 
   head = newnode(10);
   head->next=newnode(20);
   head->next->next = newnode(30);
   head->next->next->next = newnode(40);
   head->next->next->next->next = newnode(50);
   //head->next->next->next->next = head->next;
   if(iscycle(head))
    printf("cycle detected");
   else
    printf("no cycle");
    printf("\nmiddle element %d\n", middleelement(head));
   freelist(head);
   return 0;
}