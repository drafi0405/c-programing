#include<stdio.h>
#include<malloc.h>
typedef struct List{
    int data;
    struct List *next;
}LL;
LL *createNode(int v){
    LL *new = malloc(sizeof(LL));
    new->next = NULL;
    new->data = v;
    return new;
}
LL *cloneList(LL *original){
    if(original == NULL)
        return NULL;
    LL *newHead = createNode(original->data);
    LL *newList = newHead;
    LL *curoriginal = original->next;
    while(curoriginal){
        newList->next = createNode(curoriginal->data);
        curoriginal = curoriginal->next;
        newList = newList->next;
    }
    return newHead;
}
void printList(LL *h){
    while(h){
        printf("%d->",h->data);
        h=h->next;
    }
    printf("NULL");
}
int main(){
    LL *head=NULL;
    head = createNode(10);
    head->next = createNode(20);
    head->next->next = createNode(30);
    LL *clone = cloneList(head);
    printList(clone);
    return 0;
}