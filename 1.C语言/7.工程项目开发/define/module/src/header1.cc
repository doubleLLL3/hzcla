#include <stdio.h>
#include <header1.h>
void funcA(int n) {
    if (n == 0) return;
    printf("funcA : %d\n", n);
    funcB(n - 1);
    return ;
}

void funcB(int n) {
    if (n == 0) return;
    printf("funcB : %d\n", n);
    funcA(n - 1);
    return ;
}
