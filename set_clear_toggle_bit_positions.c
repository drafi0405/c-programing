#include<stdio.h>
void toggleNthBit(int *v, int n){
    *v = *v ^ (1<<n);
}
void setNthBit(int *v, int n){
    *v = *v | (1<<n);
}
void clearNthBit(int *v, int n){
    *v = *v & ~(1<<n);
}
void printinbinary(unsigned int n){
    if (n > 1) {
        printinbinary(n/2);
    }
    printf("%d", n%2);
}
int main(){
    unsigned int value = 0xf;
    printf("%x->", value);
    printinbinary(value);
    clearNthBit(&value,3);
    printf("\n%x->", value);
    printinbinary(value);
    setNthBit(&value,3);
    printf("\n%x->", value);
    printinbinary(value);
    toggleNthBit(&value,3);
    printf("\n%x->", value);
    printinbinary(value);
    
    return 0;
}