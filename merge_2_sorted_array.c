#include <stdio.h>
#include <stdlib.h>
int findHighestElement(int a[], int as, int b[], int bs){
    int i,highVal=0;
    for(i=0;i<as;i++){
        if(highVal<a[i])
            highVal = a[i];
    }
    for(i=0;i<bs;i++){
        if(highVal<b[i])
            highVal = b[i];
    }
    return highVal+1;
}
int main(){
    int a[]={2,3,5,6,7,8};
    int b[]={4,5,6,7,8,9,10};
    int highest = findHighestElement(a,sizeof(a)/sizeof(a[0]),b,sizeof(b)/sizeof(b[0]));
    
    int *tmp= (int *)calloc(highest, sizeof(int));
    int count=0;
    for(int i=0;i<=highest;i++){
        if(i<(sizeof(a)/sizeof(a[0]))&&tmp[a[i]]==0)
            tmp[a[i]]=1;
    }
    for(int i=0;i<(sizeof(b)/sizeof(b[0]));i++){
            if( tmp[b[i]]==0)
                tmp[b[i]]=1;
            else if(tmp[b[i]]==1)
                tmp[b[i]]=2;
    }
    for(int i=0;i<highest;i++){
      printf("%d ",tmp[i]);
        if(tmp[i] >= 1)
            count++;
    }
    printf("count %d\n", count);
    int result[count];
    
    for(int i=0,j=0;i<highest;i++){
        if(tmp[i] >= 1){
            result[j]=i;
            printf("%d ",result[j]);
            j++;
        }
    }
    return 0;
}