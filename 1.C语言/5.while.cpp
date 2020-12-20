/*************************************************************************
	> File Name: 7.while.cpp
	> Author: Double
	> Mail: doubleliu3@gmail.com
	> Created Time: Sat 17 Oct 2020 04:48:19 PM CST
 ************************************************************************/

#include<stdio.h>

int main() {
    int n = 1;
    while (n <= 100) {
        printf("%d ", n);
        ++n;
    }
    printf("\n");
    n = 1;
    do {
        printf("%d ", n);
        ++n;
    }while(n <= 100);
    printf("\n");
    return 0;
}

