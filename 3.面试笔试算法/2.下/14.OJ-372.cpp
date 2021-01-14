/*************************************************************************
	> File Name: 14.OJ-372.cpp
	> Author: Double
	> Mail: doubleliu3@gmail.com
	> Created Time: Sun 10 Jan 2021 08:59:46 PM CST
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
#define MAX_N 500000

class Queue {
public:
    Queue(int *arr) : arr(arr) {}
    void push(int i) {
        while (head - tail && arr[q[tail - 1]] > arr[i]) --tail;
        q[tail++] = i;
        return ;
    }
    void pop() { ++head; }
    int size() { return tail - head; }
private:
    int *arr;
    int q[MAX_N + 5], head, tail;
};

int a[MAX_N + 5], b[MAX_N + 5];
int n;
Queue q1(a), q2(b);

void read() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];
    return ;
}

int main() {
    read();
    int p;
    for (p = 0; p < n; p++) {
        q1.push(p);
        q2.push(p);
        if (q1.size() != q2.size()) break;
    }
    cout << p << endl;
    return 0;
}
