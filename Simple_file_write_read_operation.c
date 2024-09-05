#include<stdio.h>
#include<stdlib.h>
int main(){
    FILE *fp;
    char input[100];
    char output[100];
    
    fp=fopen("simple.txt","w");
    if(NULL == fp){
        printf("fopen error\n");
        return -1;
    }
    fgets(input, 100, stdin);
    fprintf(fp, "%s", input);
    fclose(fp);
    
    fp=fopen("simple.txt","r");
    if(NULL==fp){
        printf("fopen error\n");
        return -1;
    }
    while(fgets(output,100,fp)!=NULL)
        printf("%s",output);
    fclose(fp);
    
    return 0;
}