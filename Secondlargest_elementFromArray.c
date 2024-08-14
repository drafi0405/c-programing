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
    return secondLarge;
}
int main()
{
    int a[]={-200,-30,-1,-20,-500};
    int alen = sizeof(a)/sizeof(a[0]);
    printf("%d", alen);
    printf("second largest %d\n",findSecondlargest(a, alen));
    return 0;
}