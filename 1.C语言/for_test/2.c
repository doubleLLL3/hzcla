/*************************************************************************
	> File Name: 2.c
	> Author: Double
	> Mail: doubleliu3@gmail.com
	> Created Time: Fri 13 Nov 2020 02:42:42 PM CST
 ************************************************************************/

#include <stdio.h>

int main() {
    char str[100];
    while (~scanf("%[^\n]s", str)) {
        getchar();
        printf(" has %d chars!\n", printf("%s", str));
    }

    return 0;
}
