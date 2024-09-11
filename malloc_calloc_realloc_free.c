#include<stdio.h>
#include<stdlib.h>
int main(){
    int *mallocptr = (int *)malloc(sizeof(int)*4);
    for(int i=0;i<4;i++){
        *(mallocptr+i) = i;
        printf("%p[%d] ",mallocptr+i,*(mallocptr+i));
    }
    printf("\n");
    int *callocptr = (int *)calloc(5, sizeof(int));
    for(int i=0;i<5;i++)
        printf("%p[%d] ",callocptr+i,*(callocptr+i));
    printf("\n");
    mallocptr = (int *)realloc(mallocptr, sizeof(int)*6);
    for(int i=0;i<6;i++){
        printf("%p[%d] ",mallocptr+i,*(mallocptr+i));
    }
    free(mallocptr);
    free(callocptr);
    return 0;
}