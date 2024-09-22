#include<stdio.h>
#include<stdbool.h>
#include<stdint.h>
#define POOLSIZE 200
static uint8_t memory[POOLSIZE];
typedef struct block{
    struct block *next;
    size_t size;
    bool is_free;
}Block;
Block *freelist = (Block *)memory;
void mem_init(){
    freelist->next=NULL;
    freelist->size = POOLSIZE-sizeof(Block);
    freelist->is_free = true;
}
void *my_alloc(size_t size){
    Block *current = freelist;
    while(current){
        if(current->is_free && current->size >= size){
            if(current->size > size+sizeof(Block)){
                Block *newBlock = (Block *)((uint8_t *)current+size+sizeof(Block));
                newBlock->size = current->size-size-sizeof(Block);
                newBlock->is_free = true;
                newBlock->next = current->next;
                current->next = newBlock;
            }
            current->size = size;
            current->is_free = false;
            return((uint8_t *)current+sizeof(Block));
        }
        current = current->next;
    }
    return NULL;
}
void my_free(void *ptr){
    Block *current = (Block *)((uint8_t *)ptr-sizeof(Block));
    current->is_free = true;
}
void display(){
    Block *current = freelist;
    while(current){
        printf("current %p  size %zu free %d\n", current, current->size, current->is_free);
        current = current->next;
    }
}
int main(){
    mem_init();
    void *ptr1 = my_alloc(10);
    printf("Allocated 10 bytes at %p\n", ptr1);
    void *ptr2 = my_alloc(20);
    printf("Allocated 10 bytes at %p\n", ptr2);
    display();
    my_free(ptr1);
    printf("Free memory at %p\n", ptr1);
    my_free(ptr2);
    printf("Free memory at %p\n", ptr2);
    display();
    return 0;
}