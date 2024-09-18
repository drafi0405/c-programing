#include<stdio.h>
#include<stdlib.h>
int binarysearch(int arr[], int len, int target){
    int low =0, high=len-1;
    while(low <= high){
        int mid = low+(high-low)/2;
        if(arr[mid] == target){
            return mid;
        }
        if(target < arr[mid]){
            high = mid-1;
        }
        if(target > arr[mid]){
            low = mid+1;
        }
        
    }
    return -1;
}
int main(){
    int arr[]={1,3,5,6,8};
    int len = sizeof(arr)/sizeof(arr[0]);
    int res = binarysearch(arr, len, 6);
    if(res == -1){
        printf("not found");
    }else{
        printf("found at index %d",res);
    }
    return 0;
}