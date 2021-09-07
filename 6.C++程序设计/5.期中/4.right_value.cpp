/*************************************************************************
	> File Name: 4.right_value.cpp
	> Author: Double
	> Mail: doubleliu3@gmail.com
	> Created Time: Fri 19 Mar 2021 03:54:23 PM CST
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

#define func(x) __func(x, "func(" #x ")")
#define func2(x) __func2(x, "func2(" #x ")")

void __func2(int &x, const char *str) {
    cout << str << " is left value" << endl;
    return ;
}

void __func2(int &&x, const char *str) {
    cout << str << " is right value" << endl;
    return ;
}

void __func2(double &&x, const char *str) {
    cout << str << " is double value" << endl;
    return ;
}

void __func(int &x, const char *str) {
    cout << str << " is left value" << endl;
    func2(x);
    return ;
}

void __func(int &&x, const char *str) {
    cout << str << " is right value" << endl;
    func2(x);
    func2(forward<int &&>(x));
    return ;
}

namespace haizei {

    class vector {
    public :
        vector(int n = 10) : __size(n), data(new int[n]) {
            cout << "default constructor" << endl;
        }
        vector(const vector &v) : __size(v.size()), data(new int[__size]) {
            cout << "deep copy construtor" << endl;
            for (int i = 0; i < size(); i++) data[i] = v[i];
            return ;
        }
        vector(vector &&v) : __size(v.size()), data(v.data) {
            cout << "move copy constructor" << endl;
            v.data = nullptr;  // 需要管
            v.__size = 0;
        }
        vector operator+(const vector &v) {
            vector ret(v.size() + this->size());
            vector &now = *this;
            for (int i = 0; i < size(); i++) {
                ret[i] = now[i];
            }
            for (int i = size(); i < ret.size(); i++) {
                ret[i] = v[i - size()];
            }
            return ret;
        }
        vector operator[](const vector &v) {
            
        }
        int size() const {return __size;}
        ~vector() {
            if (data) delete[] data;
            data = nullptr;
            
        }
    private:
        int __size;
        int *data;
    };

}  // end of haizei


class A {
public :
    A operator+(int x) {}  // 返回的是右值
    A &operator+=(int x) {} // 返回的是左值引用
};

ostream &operator<<(ostream &out, const haizei::vector &v) {
    for (int i = 0; i < v.size(); i++) {
        out << v[i] << " ";
    }
    return out;
}

int main() {
    haizei::vector v1, v2;
    for (int i = 0; i < v1.size(); i++) v1[i] = rand() % 100;
    for (int i = 0; i < v2.size(); i++) v2[i] = rand() % 100;
    haizei::vector v3(v1 + v2);
    cout << v1 << endl;
    cout << v2 << endl;
    cout << v3 << endl;
    haizei::vector v4(move(v1));
    cout << v1 << endl;
    cout << v4 << endl;
    return 0;
    int x = 1234, y = 456;
    func(1234);
    func(x);
    func(x + y);
    func(x++);   // 右值
    func(++x);   // 左值
    func(x + 123);
    func(x *= 2);
    func(y += 3);
    func(y * 3);
    
    int &rx = x; // 左值引用
    return 0;
}
