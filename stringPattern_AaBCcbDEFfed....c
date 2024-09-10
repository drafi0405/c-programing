#include <stdio.h>
#include <ctype.h>
//65
//AaBCbcDEFdef
char buf[200];
void reverse(char buf[], int s1, int e1){
  int s=s1, e= e1;
    while(e>s){
        char c = buf[e];
        buf[e] = buf[s];
        buf[s] = c;
        s++;
        e--;
    }
    for(int i=s1;i<=e+1;i++)
        printf("%c", buf[i]);
}
int main()
{
    for(int j=1, i=65,m=97; i<=65+25;j++){ 
        printf("\n");
        for(int k=j; k>0 && i<=65+25; k--,i++){
            printf("%c",i);
        }
        for(int k=j; k>0 && m<=97+25; k--,m++ ){
            buf[m]=m;
            if(j==1)
                printf("%c",tolower(buf[m]));
        }
        if(j>1){
            reverse(buf,m-j,m-1);
        }
    }
    return 0;
}