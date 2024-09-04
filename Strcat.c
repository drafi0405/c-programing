#include<stdio.h>
#include<string.h>
#include<malloc.h>
char *resultStr(int strcount, char **str){
    int slen=0;
    for(int i=0;i<4;i++)
        slen += strlen(str[i])+1;
    char *fullStr = (char *)malloc(slen * sizeof(char));
    fullStr[0]='\0';
    for(int i=0;i<4;i++){
        strcat(fullStr,str[i]);
    }
    return fullStr;
}
int main(){
    char *str[] = {"Hello", " ","World","!"};
    char *result = resultStr(4, str);
    printf("Concatinate str %s\n", result);
    return 0;
}