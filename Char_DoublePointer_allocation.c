#include<stdio.h>
#include<malloc.h>
int main(){
    char **entry = (char **)malloc(sizeof(char *)*5);
    for(int i=0;i<3;i++){
        entry[i]=(char *)malloc(sizeof(char)*10);
        snprintf(entry[i],10,"string %d",i);
    }
    for(int i=0;i<3;i++){
        printf("%s\n",entry[i]);
        free(entry[i]);
    }
    free(entry);
    return 0;
}