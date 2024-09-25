#include<stdio.h>
unsigned int reversebits(unsigned int n){
    unsigned int result=0;
    int bitcount = sizeof(n)*8;//32 bits 
    for(int i=0;i<bitcount;i++){
        if(n&(1<<i)){
            result |= (1 <<bitcount-1-i);
        }
    }
    return result;
}
void printbits(int v){
    if(v > 0){
        printbits(v/2);
    }
    printf("%d",v%2);
}

int main(){
    unsigned int v=4;
    printf("\n%d\n",v);
    printbits(v);
    unsigned int v_r = reversebits(v);
    printf("\n%d\n",v_r);
    printbits(v_r);
    return 0;
}