#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void reverse(char *str) {
    int len = strlen(str)-1;
    int i=0;
    while(len>i){
        char t = str[len];
        str[len] = str[i];
        str[i] = t;
        i++;
        len--;
    }
}
void reversewholestr(int strcount, char **str){
    for(int i=0;i<strcount;i++)
        reverse(str[i]);
        
}
int main() {
    char **strings = (char **)malloc(sizeof(char*)*4);
    for(int i=0;i<4;i++){
        strings[i]=(char *)malloc(sizeof(char)*10);
        printf("enter the string\n");
        scanf("%s",strings[i]);
    }
    reversewholestr(4, strings);

    for (int i = 0; i < 4; i++) {
        printf("%s ", strings[i]);  // Outputs reversed strings: olleH, dlroW, C, gnimmargorP
        free(strings[i]);
    }
    free(strings);
    return 0;
}
