#include<stdio.h>
#include<string.h>
void revstr(char s[]){
    short int len = strlen(s)-1;
    char c;
    int i=0;
    while(len/2){
        c=s[i];
        s[i]=s[len];
        s[len]=c;
        i++;
        len--;
    }
}
int main(int argc[], char *argv[]){
    char s[]="hello";
    revstr(s);
    printf("%s",s);
    return 0;
}