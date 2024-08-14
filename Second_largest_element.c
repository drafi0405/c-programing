#include <stdio.h>
#include <stdlib.h>
int findSecondlargest(int a[], int alen){
    int largest = 0; 
    static int secondLarge = 0; 
    for(int i=0;i<alen;i++){
        if(largest < a[i]){
            secondLarge = largest;
            largest = a[i];
        }
        if(largest > a[i]){
            secondLarge = a[i];
        }
    }
    return secondLarge;
}
int main()
{
    int a[]={200,30};
    int alen = sizeof(a)/sizeof(a[0]);
    printf("%d", alen);
    printf("second largest %d\n",findSecondlargest(a, alen));
    return 0;
}