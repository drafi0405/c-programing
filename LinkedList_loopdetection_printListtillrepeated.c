#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define PRINTLIST
typedef struct node{
    int data;
    struct node *next;
}Node;
int count = 1;
void printList(Node *head){
    printf("List node count %d\n",count);
    if(head == NULL){
        printf("List is empty\n");
    }else{
        do{
            printf("%p[%d]->",head,head->data);
            head=head->next;
        }while(count-- && head!=NULL);
    }
    printf("NULL\n");
}
Node *newNode(int val){
    Node *new = (Node *)malloc(sizeof(Node));
    if(new == NULL){
        printf("memory allocation failed\n");
        return NULL;
    }
    new->data = val;
    new->next = NULL;
    return(new);
}
bool isLoop(Node *head){
    Node *slow, *fast;
    slow = fast = head;
    while(slow && fast && fast->next){
        slow = slow->next;
        count++;
        fast = fast->next->next;
        if(slow == fast){
            count++;
            return true;
        }
    }
    count++;
    return false;
}
int main(int argc[], char *argv[]){
    Node *head=NULL;
    head = newNode(10);
    head->next = newNode(20);
    head->next->next = newNode(30);
    head->next->next->next = newNode(40);
    head->next->next->next->next = head->next;
    if(isLoop(head)){
        printf("Loop exist in the given List\n");
    }
    else
        printf("Loop DOESN'T exist in the given List\n");
    #ifdef PRINTLIST
        printList(head);
    #endif
    return 0;
}