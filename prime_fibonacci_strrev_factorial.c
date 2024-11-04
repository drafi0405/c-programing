#include<stdio.h>
#include<stdbool.h>
#include<string.h>
int factorial(int n){
    if(n>1)
        return n*factorial(n-1);
    else if (n ==1){
        return n;
    }else{
        return 0;
    }
}
bool isPrime(int n){
    if(n<=1)
        return 0;
    if(n<=3)
        return 1;
    if(n%2 == 0)
        return 0;
    for(int i=3;(i*i)<n;i+=2){
        if(i%n == 0)
            return 0;
    }
    return 1;
}
char *reverse(char s[], int slen){
    char ch;
    int i=0;
    while(slen/2){
        ch = s[slen];
        s[slen] = s[i];
        s[i]=ch;
        i++;
        slen--;
    }
    return s;
}
void fibonacci_iterate(int n){
    int t1=0,t2=1,nxt;
    printf("%d %d ",t1,t2);
    for(int i=3;i<=n;i++){
        nxt = t1+t2;
        printf("%d ",nxt);
        t1= t2;
        t2 = nxt;
    }
}
int fibonacci(int n){
    if(n == 0)
        return 0;
    if(n == 1)
        return 1;
    return fibonacci(n-1)+fibonacci(n-2);
}
int main(){
    if(isPrime(7))
        printf("7 is Prime\n");
    printf("factorial of 4 is %d", factorial(4));
    char s[]="happy";
    printf("\nreverse of %s is ",s);
    printf("%s\n",reverse(s,strlen(s)-1));
    //printf("first 10 fibonacci numbers are ");
    //fibonacci(10);
    for(int i=0;i<10;i++){
        printf("%d ",fibonacci(i));
    }
    return 0;
}