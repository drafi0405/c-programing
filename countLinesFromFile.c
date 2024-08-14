#include <stdio.h>
int countLinesOfFile(const char *filename){
    FILE *fp = fopen(filename, "r");
    int lineCount=0;
    char c;
    if(fp == NULL){
        return -1;
    }
    while(!feof(fp)){
        c = fgetc(fp);
        if(c == '\n')
            lineCount++;
    }
    /*while( (c = fgetc(fp))!=EOF){
            if(c == '\n')
                    lineCount++;
    }*/
    fclose(fp);
    return(lineCount);
}
int main()
{
    const char *filename = "simple.txt";
    int linecount = countLinesOfFile(filename);
    if( linecount== -1)
        printf("File %s is empty\n", filename);
    else
        printf("File %s haing %d lines", filename, linecount);
    return 0;
}