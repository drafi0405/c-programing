#include<stdio.h>
int is_power_2(int n){
    return (n>0) && ((n & (n-1)) == 0);
}
int main(){
    for(int i=0;i<100;i++)
        (is_power_2(i))?printf("%d is power\n",i):printf("%d is not power\n",i);
    return 0;
}