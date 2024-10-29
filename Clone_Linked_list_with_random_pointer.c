#include<stdio.h>
#include<malloc.h>
typedef struct List{
    int data;
    struct List *next;
    struct List *random;
}LL;
LL *createNode(int v){
    LL *new = malloc(sizeof(LL));
    new->next = NULL;
    new->random = NULL;
    new->data = v;
    return new;
}
LL *cloneList(LL *original){
    if(original == NULL)
        return NULL;
    LL *cur = original;
    while(cur){
        LL *tmp = createNode(cur->data);
        tmp->next = cur->next;
        cur->next = tmp;
        cur = tmp->next;
    }
    cur = original;
    while(cur){
        if(cur->random){
            cur->next->random = cur->random->next;
        }
        cur = cur->next->next;
    }
    LL *newHead = original->next;
    LL *curnewHead = newHead;
    cur = original;
    while(cur){
        cur->next = cur->next->next;
        if(curnewHead->next){
            curnewHead->next = curnewHead->next->next;
        }
        cur = cur->next;
        curnewHead = curnewHead->next;
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
    head->random =head->next->next;
    head->next->random = head;
    head->next->next->random = head;
    LL *clone = cloneList(head);
    printList(clone);
    return 0;
}