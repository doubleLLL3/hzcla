/*************************************************************************
	> File Name: 13.prime.c
	> Author: Double
	> Mail: doubleliu3@gmail.com
	> Created Time: Sat 24 Oct 2020 02:39:00 PM CST
 ************************************************************************/
#include <stdio.h>
#define max_n 100

int prime[max_n + 5] = {0};  // +5 一类编程技巧
// 打标记
void init() {
    for (int i = 2; i <= max_n; i++) {
        // 从2开始
        /*if (!prime[i]) {
            for (int j = i * 2; j <= max_n; j += i) {
                prime[j] = 1;
            }   
        }*/  // 可以改成对偶逻辑，减少缩进，提高可读性
        
        if (prime[i]) continue;  // 正好第一个数2是素数
        // 在打标记的过程中将素数直接挑出来
        prime[++prime[0]] = i;  // prime[0]-计数器，用来记录素数个数，再依次存放素数
        // 上面一句等价于下面两句
        /*++prime[0];
        prime[prime[0]] = i;*/
        for (int j = i * 2; j <= max_n; j += i) {  
        // 用i * i 代替 i * 2可以将时间效率从O(Nlogn)优化为O(Nlognlogn)，但i * i 可能溢出int类型
            prime[j] = 1;
        }
    }
    return ;
}

int main() {
    init();
    for (int i = 1; i <= prime[0]; i++) {
        printf("%d\n", prime[i]);
    }
    return 0;
}
