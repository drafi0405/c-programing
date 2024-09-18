#include<stdio.h>
#include<string.h>
int ispolindrom(char s[], int e){
    int b=0;
    while(b<e){
        if(s[b] != s[e])
            return 0;
        printf("%c %c",s[b],s[e]);
        b++;
        e--;
    }
    return 1;
}
int main(){
    char s[]="abba";
    if(ispolindrom(s,strlen(s)-1))
        printf("polindrome");
    else
        printf("not polindrome");
    return 0;
}