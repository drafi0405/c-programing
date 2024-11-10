/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include <time.h>
#include <string.h>
int main()
{
    time_t currenttime;
    struct tm *local_time;
    char isttime[100];
    currenttime = time(NULL);
    local_time = localtime(&currenttime);
    strftime(isttime, sizeof(isttime),  "%Y-%m-%d %H:%M:%S", local_time);
    printf("%s",isttime);
    return 0;
}