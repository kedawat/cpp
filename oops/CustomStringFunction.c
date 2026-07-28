#include <stdio.h>

int customStringLen(const char *s){
    int len = 0;
    while(*s != '\0'){
        len++;
        s++;
    }
    return len;
}

void customStringCopy(char *dest, char *source){
    int i=0;
    while(*source != '\0'){
        *dest = *source;
        dest++;
        source++;
    }
    *dest = '\0';
}

void customStringConcatenate(char *dest, char *source){
    while(*dest != '\0'){
        dest++;
    }

    while(*source != '\0'){
        *dest = *source;
        dest++;
        source++;
    }
    *dest = '\0';
}

int main(){
    char *s1 = "nilesh";
    char *s2 = "Gupta";

    int lenS1 = customStringLen(s1);
    int lenS2 = customStringLen(s2);

    printf("Lenth of s1: %d\n", lenS1);
    printf("Lenth of s2: %d\n", lenS2);

    char newCopy[200];
    customStringCopy(newCopy, s1);

    printf("copied string: %s\n", newCopy);

    customStringConcatenate(newCopy, s2);

    printf("Concatenated string: %s\n", newCopy);
}