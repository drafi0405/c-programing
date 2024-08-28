#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <ctype.h>

int myatoi(char *st){
    int i=0, sign =1, digit=0, result=0;
    while(st[i]!='\0'){
        if(isalpha(st[i++]))
            return -1;
    }
    i=0;
    while(isspace(st[i])){
        i++;
    }
    if(st[i] == '-'){
        sign = -1;
        i++;
    }
    while(st[i] != '\0' && isdigit(st[i])){
        digit = st[i]-'0';
        if(result > (INT_MAX-digit)/10)
            return (sign-1)?INT_MAX:INT_MIN;
        result = result*10+digit;
        i++;
    }
    return result*sign;
}
int main(int argc, char *argv[]) {
    // you can write to stdout for debugging purposes, e.g.
    printf("This is a debug message\n");
    printf("%d %s %s\n", argc, argv[0],argv[1]);
    printf("converted value from ascii of %s to interger is %d", argv[1], myatoi(argv[1]));
    return 0;
}