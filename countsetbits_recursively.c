#include<stdio.h>
static int count;
int countsetbits(int val){
    if(val > 1){
        countsetbits(val/2);
    }
    printf("%d", val%2);
    if(val%2)
        count++;
}
int main(){
    countsetbits(15);
    printf("%d", count);
    return 0;
}