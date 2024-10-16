#include <stdio.h>
#include <string.h>
#include <stdbool.h>

void sortString(char* str) {
    int len = strlen(str);
    for (int i = 0; i < len - 1; i++) {
        for (int j = i + 1; j < len; j++) {
            if (str[i] > str[j]) {
                char temp = str[i];
                str[i] = str[j];
                str[j] = temp;
            }
        }
    }
}

bool areAnagrams(char* str1, char* str2) {
    if (strlen(str1) != strlen(str2)) return false;
    
    sortString(str1);
    sortString(str2);
    
    return strcmp(str1, str2) == 0;
}

int main() {
    char str1[] = "listen";
    char str2[] = "silent";

    if (areAnagrams(str1, str2)) {
        printf("%s and %s are anagrams\n", str1, str2);
    } else {
        printf("%s and %s are not anagrams\n", str1, str2);
    }

    return 0;
}
