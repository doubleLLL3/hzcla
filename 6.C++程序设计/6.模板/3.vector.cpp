/*************************************************************************
	> File Name: 3.vector.cpp
	> Author: Double
	> Mail: doubleliu3@gmail.com
	> Created Time: Sun 21 Mar 2021 07:52:47 PM CST
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

class A {
public :
    A() = delete;
    A(int x) : x(x) {}
    friend ostream &operator<<(ostream &ouot, const A &);
private:
    int x;
};

ostream &operator<<(ostream &out, const A &a) {
    out << "Class A : " << a.x;
    return out;
}

namespace haizei {
template<typename T>
class vector {
public :
    //vector(int n = 10) : __size(n), data(new T[__size]) {} // 可能没有构造函数
    vector(int n = 10);
    vector(const vector<T> &v);
    vector(vector<T> &v);

    T &operator[](int ind);
    const T &operator[](int ind) const;
    int size() const;
    void push_back(const T &);  // 左值
    void push_back(T &&);  // 右值

    ~vector();

private:
    int __size, __capacity;
    T *data;
};

template<typename T>
vector<T>::vector(int n) : __size(0), __capacity(n), data(nullptr) {
    data = (T *)malloc(sizeof(T) * __capacity);
    return ;
}

template<typename T>
vector<T>::vector(const vector<T> &v) : __size(v.__size), __capacity(v.__capacity) {
    data = (T *)malloc(sizeof(T) * __capacity);
    for (int i = 0; i < __size; i++) {
        //data[i] = v.data[i];  // 容易出BUG
        new(data + i) T(v.data[i]);    // 利用原地构造
    }
    return ;
}

template<typename T>
vector<T>::vector(vector<T> &v) : __size(v.__size), __capacity(v.__capacity), data(v.data) {
    v.data = nullptr;
    v.__size = 0;
    v.__capacity = 0;
}

template<typename T>
T &vector<T>::operator[](int ind) {
    return data[ind];
}

template<typename T>
const T &vector<T>::operator[](int ind) const {
    return data[ind];
}

template<typename T>
int vector<T>::size() const { return __size; }  // const: 这样才可以使用const定义
    
template<typename T>
void vector<T>::push_back(const T &d) {
    new(data + __size) T(d);
    __size += 1;
    return ;
}

template<typename T>
void vector<T>::push_back(T &&d) {
    new(data + __size) T(move(d));  // 会调用移动构造
    __size += 1;
    return ;
}

template<typename T>
vector<T>::~vector() {
    if (data) free(data);
    __size = 0;
    __capacity = 0;
    return ;
}

} // end of haizei

ostream &operator<<(ostream &out, const vector<A> &v) {
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
    return out;
}

ostream &operator<<(ostream &out, const haizei::vector<A> &v) {
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
    return out;
}

int main() {
    vector<A> v1;
    cout << v1.size() << endl;
    v1.push_back(123);
    v1.push_back(456);
    v1.push_back(789);
    //cout << v1[0] << endl;  // 一开始系统会报错，因为访问越界了
    haizei::vector<A> v2;
    cout << v2.size() << endl;
    v2.push_back(123);
    v2.push_back(456);
    v2.push_back(789);
    cout << v1 << endl;
    cout << v2 << endl;

    return 0;
}
