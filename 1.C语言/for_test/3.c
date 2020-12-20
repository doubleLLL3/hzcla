/*************************************************************************
	> File Name: 3.c
	> Author: Double
	> Mail: doubleliu3@gmail.com
	> Created Time: Fri 13 Nov 2020 02:48:49 PM CST
 ************************************************************************/

#include <stdio.h>
#define swap(a, b) {\
    __typeof(a) temp = a;\
    a = b, b = temp;\
}

int main() {
    int n;
    scanf("%d", &n);
    char str[50] = {0}, buffer[50] = {0}, *p = str, *q = buffer;
    sprintf(str, "%d.%d.%d.%d", 192, 168, 1, 2);
    if (n & 1) {
        sprintf(q, "[%s]", p);
        swap(p, q);
    }
    if (n & 2) {
        sprintf(str, "{%s}", str);
    }
    if (n & 4) {
        sprintf(str, "(%s)", str);
    }
    printf("%s\n", p);
    return 0;
}
