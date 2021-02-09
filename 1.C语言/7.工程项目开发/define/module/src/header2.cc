#include <stdio.h>
#include "header1.h"
void funcC(int a, int b) {
    printf("funcC: %d + %d = %d\n", a, b, a + b);
    funcA(a);
    return;
}
