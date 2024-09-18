#include<stdio.h>
#include<string.h>
#include<malloc.h>
char *my_strtok(char *str, char delimiter){
    static char *nextpointer = NULL;
    if(str == NULL){
      str = nextpointer;
    }
    nextpointer = str;
    char *token;
    if(*nextpointer == '\0')
        return NULL;
    int tokencount=0;
    while(*nextpointer != '\0' && *nextpointer != delimiter){
        tokencount++;
        nextpointer++;
    }
    token = (char *)malloc((tokencount+1)*sizeof(char));
    strncpy(token, str, tokencount);
    if(*nextpointer != '\0')
      nextpointer += 1;
    token[tokencount]='\0';
    return token;
}
int main(){
    char str[]="welcome to coding";
    char delimiter=' ';
    char *token;
    token  = my_strtok(str, delimiter);
    while(token != NULL){
        printf("%s", token);
        token = my_strtok(NULL, delimiter);
    }
    return 0;
}