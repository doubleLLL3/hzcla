/*************************************************************************
	> File Name: 4.sort.cpp
	> Author: Double
	> Mail: doubleliu3@gmail.com
	> Created Time: Sat 06 Mar 2021 04:34:14 PM CST
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
#include <functional>
using namespace std;

ostream &operator<<(ostream &out, const vector<int> &a) {
    for (auto x : a) {
        out << x << " ";
    }
    return out;
}

bool cmp1(int a, int b) {
    return a > b;
}

namespace haizei {
class CMP {
public :
    CMP(int z = 0) : z(z) {} // z = 0 less, z = 1 greater
    bool operator()(int a, int b) {
        return (a < b) ^ !!(z);
    }
    int z;
};

void sort(int *arr, int l, int r, function<bool(int, int)> cmp = CMP()) {
// function 高级的函数，可以指向任意
    if (l >= r) return ;
    int x = l, y = r, z = arr[(l + r) >> 1];
    do {
        while (cmp(arr[x], z)) ++x;  // default: arr[x] < z
        while (cmp(z, arr[y])) --y;  // default: z < arr[y]
        if (x <= y) {
            swap(arr[x], arr[y]);
            ++x, --y;
        }
    } while (x <= y);
    sort(arr, l, y, cmp);
    sort(arr, x, r, cmp);
    return ;
}
}  // end of haizei

void output_arr(int *arr, int n) {
    if (arr == NULL) return ;
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    return ;
}

int main() {
    vector<int> arr;
    int n;
    cin >> n;
    while (n--) { int a; cin >> a, arr.push_back(a); }
    sort(arr.begin(), arr.end(), haizei::CMP());  // CMP() 匿名对象
    cout << arr << endl;

    int arr2[5] = {6, 8, 4, 5, 1};
    haizei::sort(arr2, 0, 4);
    output_arr(arr2, 5);

    haizei::sort(arr2, 0, 4, cmp1);
    output_arr(arr2, 5);

    haizei::sort(arr2, 0, 4);
    output_arr(arr2, 5);

    haizei::sort(arr2, 0, 4, haizei::CMP(1));
    output_arr(arr2, 5);
    return 0;
}
