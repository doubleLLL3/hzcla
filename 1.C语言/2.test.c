/*************************************************************************
	> File Name: 2.test.c
	> Author: Double
	> Mail: doubleliu3@gmail.com
	> Created Time: Tue 13 Oct 2020 08:44:10 PM CST
 ************************************************************************/

#include <stdio.h>

int main() {
    //char str[100] = {0};
    //scanf("%s", str);
    //printf("%s\n", str);  

    //char str[100] = {0};
    //int ret;
    //while ((ret = scanf("%[^\n]", str)) != EOF) {
    //   // printf("%c", getchar());  // 输出这个被吞的字符可以发现，是\n，一直是
    //    printf("%s: ret = %d\n", str, ret);
    //}

    char str[100] = {0};
    while(scanf("%[^\n]s", str) != EOF){
        getchar();
        printf(" has %d chars!\n", printf("%s", str));
     }

    return 0;
}
