/*************************************************************************
	> File Name: str.c
	> Author: Double
	> Mail: doubleliu3@gmail.com
	> Created Time: Sat 14 Nov 2020 10:09:47 AM CST
 ************************************************************************/
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
char* get() {
    char * p = "hello world";
    return p;
}

int main() {
    char *str = (char *)malloc(sizeof(char) * 1);
    printf("past: \t%p\n", str);
    //str = get();
    str = "hello world";
    //str = {'h', 'e', 'l', 'l', 'o', ' ', 'w', 'o', 'r', 'l', 'd', '\0'};
    //strcpy(str, "hello world");
    printf("now: \t%p\n", str);
    printf("%s\n", str);
    return 0;
}
