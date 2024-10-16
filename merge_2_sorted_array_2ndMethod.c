#include<stdio.h>
void mergeTwoArrays(int a[], int az, int b[], int bz, int c[]){
    int i=0,j=0,k=0;
    while(i<az && j<bz){
        if(i+1 < az && a[i] == a[i+1]){
            i++;
        }else if(j+1 < bz && b[j] == b[j+1]){
            j++;
        }
        else {
            if(a[i]<b[j]){
                c[k++]=a[i++];
            }else if(a[i]>b[j]){
                c[k++]=b[j++];
            }
            else if(a[i]==b[j]){
                c[k++]=a[i++];
                j++;
            }
        }
    }
    while(i<az){
        c[k++]=a[i++];
    }
    while(j<bz){
        c[k++]=b[j++];
    }
}
int main(){
    int a[]={1,3,4,5,6,8};
    int b[]={2,2,2,6,7};
    int az = sizeof(a)/sizeof(a[0]);
    int bz = sizeof(b)/sizeof(b[0]);
    int c[az+bz];
    mergeTwoArrays(a,az,b,bz,c);
    for(int i=0;i<(az+bz);i++){
        printf("%d ",c[i]);
    }
    return 0;
}