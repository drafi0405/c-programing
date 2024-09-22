#include<stdio.h>
int fibonacii(int n){
    if(n<=1)
        return n;
    int a=0,b=1;
    int r=a+b;
    int fib;
    printf("%d %d ",a,b);
    for(int i=2;i<n;i++){
        fib = a+b;
        printf("%d ",fib);
        a=b;
        b=fib;
        r+=fib;
    }
    return r;
}


int fibonacci_n(int n){
    if(n<=1){
        return 1;
    }
    return (fibonacci_n(n-1)+fibonacci_n(n-2));
}
int fibonacii_iterate(int n){
    for(int i=0;i<n;i++){
        printf("%d ", fibonacci_n(i));
    }
}
int main(){
    int n;
    printf("enter the numbers you want to print\n");
    scanf("%d",&n);
    printf("sum of numbers %d\n",fibonacii_iterate(n));
    
    printf("sum of numbers %d\n",fibonacii(n));
    return 0;
}