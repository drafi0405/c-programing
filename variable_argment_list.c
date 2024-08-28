#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include <time.h>
void my_printf(const char *formate, ...){
    time_t now;
    time(&now);
    char *time_string = ctime(&now);
    time_string[strlen(time_string)-1] = '\0';
    printf("%s: ", time_string);
    
    va_list(args);
    va_start(args, formate);
    const char *p = formate;
    while(*p){
        if(*p == '%' && *(p+1)){
            p++;
            switch(*p){
                case 'd':
                    int val = va_arg(args, int);
                    printf("%d", val);
                    break;
                case 's':
                    char *s = va_arg(args, char*);
                    printf("%s", s);
                    break;
                default:
                    printf("%%");
                    printf("%c", *p);
            }
        }else{
            putchar(*p);
        }
        p++;
    }
    va_end(args);
}
int main(int argc, char *argv[])
{
    my_printf("Hello World %d\n",10);
    my_printf("my name is %s\n","happy singh");
    return 0;
}