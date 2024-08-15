/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include <stdbool.h>
#include <math.h>
int square(int n){
    for(int i=1;;i++){
        if((i*i) > n)
            return i-1;
    }
}
bool isPrime(int n){
    if(n <= 1) return 0;
    if(n <= 3) return 1;
    if(n %2 == 0) return 0;
    
    for(int i=3;i<=square(n);i+=2){
        if(n%i == 0)
            return 0;
    }
    printf(" sqrt %f  ",sqrt(n));
    printf(" sqrt %d  ",square(n));
    return 1;
}
int factorial(int n){
    if(n <= 1) return 1;
    return n*factorial(n-1);
}
int main()
{
    for(int i=0;i<10;i++){
        if(isPrime(i))
            printf("%d is prime\n",i);
        printf("factorial of %d is %d\n",i,factorial(i));
    }
    
    return 0;
}