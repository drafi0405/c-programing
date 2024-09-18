#include<stdio.h>
#include<stdlib.h>
void swap(int *a, int *b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
}
void bubblesort(int a[], int len){
    for(int i=0;i<=len;i++){
        for(int j=i;j<=len;j++){
            if(a[i]>a[j]){
                swap(&a[i],&a[j]);
            }
        }
    }
}
int main(){
    int arr[]={3,8,1,5,6};
    int len = sizeof(arr)/sizeof(arr[0]);
    bubblesort(arr, len-1);
    for(int i=0;i<len;i++)
        printf("%d ",arr[i]);
    return 0;
}