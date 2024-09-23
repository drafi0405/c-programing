#include<stdio.h>
#include<stdlib.h>
#define HSIZE 10
typedef struct node{
    int key;
    int val;
    struct node *next;
}Node;
Node *hashtable[HSIZE]={0};

int hashfunction(int key){
    return key%HSIZE;
}
void addentry(int key, int val){
    int index = hashfunction(key);
    Node *new = (Node *)malloc(sizeof(Node));
    new->val = val;
    new->key = key;
    if(hashtable[index] == NULL)
        hashtable[index]=new;
    else{
        new->next = hashtable[index];
        hashtable[index] = new;
    }
}
void display(void){
    printf("\n");
    for(int i=0;i<HSIZE;i++){
        Node *tmp = hashtable[i];
        printf("hashtable[%d]:",i);
        while(tmp){
          printf(" (key %d, val %d),", tmp->key, tmp->val);
          tmp=tmp->next;
        }
        if(tmp==NULL)
          printf("NULL\n");
       // printf("\n");
    }
}
int search(int key){
    int index = hashfunction(key);
    Node *tmp = hashtable[index];
    while(tmp && tmp->key != key){
        tmp=tmp->next;
    }
    if(tmp == NULL){
        printf("key %d not found\n",key);
        return -1;
    }else{
        printf("Key %d found having value %d at hashtable index %d\n", key, tmp->val, index);
    }
}
void delete(int key){
    int index = hashfunction(key);
    Node *tmp = hashtable[index];
    Node *prev=NULL;
    if(tmp == NULL){
        printf("Delte: no value found with this key %d\n", key);
    }
    if(tmp!=NULL){
        if(tmp->key == key){
            printf("%d key having value %d\n", key, tmp->val);
            printf("identified as fisrt entry to be delete\n");
            if(tmp->next == NULL){
                printf("deleting entry\n");
                free(tmp);
                hashtable[index] = NULL;
            }else{
                hashtable[index] = tmp->next;
                printf("deleting entry\n");
                free(tmp);
            }
        }else{
            while(tmp && tmp->key!=key){
                prev = tmp;
                tmp=tmp->next;
            }
            prev->next = tmp->next;
            printf("%d key having value %d deleting it\n", key, tmp->val);
            free(tmp);
        }
    }
}
int main(){
    addentry(1, 10);
    addentry(11, 20);
    addentry(21, 30);
    addentry(5, 50);
    addentry(15, 100);
    display();
    if(search(11) ==-1){
        printf("key not found\n");
    }
    delete(11);
    display();
    return 0;
}