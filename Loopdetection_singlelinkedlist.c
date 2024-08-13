#include<stdio.h>
#include<malloc.h>
#include<stdbool.h>
typedef struct node{
    struct node *next;
    int data;
}Node;

Node *newnode(int v){
    Node *new = (Node *)malloc(sizeof(Node));
    if(new == NULL) {
        printf("memory allocation failed\n");
        return NULL;
    }
    new->data = v;
    new->next = NULL;
    return new;
}
bool isLoop(Node *list){
    Node *fast = list;
    Node *slow = list;
    while(slow && fast && fast->next){
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast)
            return true;
    }
    return false;
}
void printList(Node *head){
    int c =20;
    while(head && c){
        printf("%d->",head->data);
        head = head->next;
        c--;
    }
}
int main(int argc[], char *argv[]){
    Node *head=NULL;
    head = newnode(1);
    head->next = newnode(2);
    head->next->next = newnode(3);
    head->next->next->next = newnode(4);
    head->next->next->next->next = head->next;
    printList(head);
    if(isLoop(head))
        printf("\nLoop exist in List\n");
    else
        printf("No Loop in List\n");
    return 0;
}