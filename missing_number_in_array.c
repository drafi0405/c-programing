#include <stdio.h>
int findmissing(int a[], int low, int high){
    for(int i=0;i<high;i++){
        if((i+1) != a[i]){
            return i+1;
        }
    }
    return -1;
}
int main(){
    int a[]={1,2,3,5,6,7,8};
    int miss = findmissing(a,0,7);
    if(miss != -1){
        printf("key exists at index %d", miss);
    }
    return 0;
}