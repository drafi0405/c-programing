#include<stdio.h>
#include<stdlib.h>
#define TABLESIZE 5
int hashtable[TABLESIZE];
int hashfunction(int key){
    return key%TABLESIZE;
}
void init(void){
    for(int i=0;i<TABLESIZE;i++){
        hashtable[i] = -1;
    }
}
void insert(int key){
    int index = hashfunction(key);
    while(hashtable[index]!=-1){
        index = (index+1)%TABLESIZE;
    }
    hashtable[index]=key;
}
void printhashtable(){
    for(int i=0;i<TABLESIZE;i++){
        if(hashtable[i]!=-1){
            printf("%d ", hashtable[i]);
        }
    }
}
int search(int key){
    int index = hashfunction(key);
    while(hashtable[index]!=-1){
        if(hashtable[index] == key){
            return index;
        }else{
            index = (index+1)%TABLESIZE;
        }
    }
    return -1;
}
int main(){
    init();
    insert(12);
    insert(22);
    insert(32);
    insert(42);
    printhashtable();
    int index = search(12);
    if(index == -1)
        printf("12 not found\n");
    else
        printf("\n12 found at index %d\n",index);
    return 0;
}