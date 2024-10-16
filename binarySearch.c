#include <stdio.h>
int binarySearch(int a[], int low, int high, int key){
    while(low<=high){
        int mid = low+(high-low)/2;
        if(a[mid]==key)
            return mid;
        if(a[mid]<key){
            low=mid+1;
        }else if(a[mid]>key){
            high = mid-1;
        }
    }
    printf("key not exists\n");
    return -1;
}
int main(){
    int a[]={2,3,5,6,10,33};
    int index = binarySearch(a,0,6,2);
    if(index != -1){
        printf("key exists at index %d", index);
    }
    return 0;
}