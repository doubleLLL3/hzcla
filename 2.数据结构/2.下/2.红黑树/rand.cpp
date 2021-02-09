/*************************************************************************
	> File Name: rand.cpp
	> Author: Double
	> Mail: doubleliu3@gmail.com
	> Created Time: Sun 20 Dec 2020 10:37:06 AM CST
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <queue>
#include <stack>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
using namespace std;

int main() {
    srand(time(0));
    int op, val;
    #define MAX_OP 20
    for (int i = 0; i < MAX_OP; i++) {
        switch (rand() % 5) {
            // 非等概率——1：3：1——查：插：删
            case 0: printf("0 %d\n", rand() % 15); break;
            case 1: 
            case 2:
            case 3: printf("1 %d\n", rand() % 15); break;
            case 4: printf("2 %d\n", rand() % 15); break;
        }
    }  
    return 0;
}
