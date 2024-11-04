#include<stdio.h>
#include<malloc.h>
#include<stdbool.h>
typedef struct link{
    int data;
    struct link *next;
}List;
List *newnode(int data){
    List *new = malloc(sizeof(List));
    if(new == NULL){
        return NULL;
    }
    new->data = data;
    new->next = NULL;
    return new;
}
bool isLoop(List *head){
    List *s=head;
    List  *f = head;
    while(f && f->next){
        s = s->next;
        f = f->next->next;
        if(s == f)
            return true;
    }
    return false;
}
int remove_3rd_element(List *h, int pos){
    List *tmp = h;
    List *tmp2 = h;
    int p = pos;
    if(tmp == NULL){
        printf("list is empty\n");
    }else{
        if(tmp2->next->data != tmp2->data){
            List *prev;
            while(tmp->next && p != 1){
                prev = tmp;
                tmp = tmp->next;
                p--;
            }
            prev->next = tmp->next;
            printf("\ndeleted element %d\n",tmp->data);
            free(tmp);
            if(prev->next)
                remove_3rd_element(prev->next,3);
            else
                return tmp2->data;
        }
        
    }
    
}
void printlist(List *h){
    while(h){
        printf("%d ",h->data);
        h=h->next;
    }
}
int main(){
    List *head = NULL;
    head = newnode(10);
    head->next = newnode(20);
    head->next->next = newnode(30);
    head->next->next->next = newnode(40);
    head->next->next->next->next = newnode(50);
    head->next->next->next->next->next = newnode(60);
    head->next->next->next->next->next->next = head;
    if(isLoop(head)){
        printf("loop exists");
        printf("remaining element %d", remove_3rd_element(head, 3));
    }
    printlist(head);
    return 0;
}