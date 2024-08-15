#include<stdio.h>
#include<stdlib.h>
//#include<malloc.h>
typedef struct node{
    int data;
    struct node *next;
}Node;
void addNode(Node **head, int val){
    Node *new = (Node *)malloc(sizeof(Node));
    if(new == NULL){
        printf("memory allocation fail to new node\n");
    }else{
        if((*head) == NULL){
            new->data = val;
            new->next = NULL;
            *head = new;
        }else{
            new->data = val;
            new->next = (*head);
            (*head) = new;
        }
    }
}
void deleteNode(Node **head, int val){
    if(*head == NULL){
        printf("List is empty\n");
    }else{
        Node *tmp = *head;
        if(tmp->data == val){
            *head = tmp->next;
            printf("deleting element is %d\n",tmp->data);
            free(tmp);
        }else{
            Node *prev;
            while(tmp->data != val && tmp->next){
                prev = tmp;
                tmp = tmp->next;
            }
            prev->next = tmp->next;
            printf("deleting element is %d\n",tmp->data);
            free(tmp);
        }
    }
}
void printList(Node *head){
    if(head == NULL)
        printf("List is empty\n");
    else{
        for(;head!=NULL;head=head->next)
            printf("%d->",head->data);
    }
    printf("NULL\n");
}
int main(int argc[], char *argv[]){
    Node *head=NULL;
    int i;
    for(i=1;i<=5;i++)
       addNode(&head, i*10);
    printList(head);
    deleteNode(&head, 10);
    printList(head);
    return 0;
}