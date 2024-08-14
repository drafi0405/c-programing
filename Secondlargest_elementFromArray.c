#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
int findSecondlargest(int a[], int alen){
    int largest = INT_MIN; 
    static int secondLarge = INT_MIN; 
    for(int i=0;i<alen;i++){
        if(largest < a[i]){
            secondLarge = largest;
            largest = a[i];
        }
        if(largest > a[i] && secondLarge < a[i]){
            secondLarge = a[i];
        }
    }
    return INT_MIN == secondLarge ? -1 : secondLarge;
}
int main()
{
    int a[]={-200,40};
    int alen = sizeof(a)/sizeof(a[0]);
    printf("%d", alen);
    int result = findSecondlargest(a, alen);
    if(result == -1)
        printf("No second element found");
    else
        printf("second largest %d\n",result);
    return 0;
}