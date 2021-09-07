/*************************************************************************
	> File Name: 5.malloc_new.cpp
	> Author: Double
	> Mail: doubleliu3@gmail.com
	> Created Time: Sun 28 Feb 2021 04:48:33 PM CST
 ************************************************************************/

#include <iostream>
using namespace std;

class A {
public :
    A() {
        cout << "default constructor" << endl;
    }
    ~A() {
        cout << "destructor" << endl;
    }
};

class B {
public :
    B() {
        cout << "B-default constructor" << endl;
    }
    ~B() {
        cout << "B-destructor" << endl;
    }
};

int main() {
    int n = 10;
    // 一、申请与销毁n个int大小的空间
    //  1）malloc + free
    cout << "malloc int" << endl;
    int *data1 = (int *)malloc(sizeof(int) * n);
    free(data1);

    // 2）new + delete
    cout << "new int" << endl;
    int *data2 = new int[n];                 // 明显较简单
    delete[] data2;

    // 二、申请和销毁n个自定义类A大小的空间
    //  1）malloc 不会调用构造函数，+ new 实现原地构造
    cout << "malloc A" << endl;
    A *Adata1 = (A *)malloc(sizeof(A) * n);  // 不调用构造函数，不会初始化每一个元素
    //  + 原地构造，形式：new(地址) 构造函数
    for (int i = 0; i < n; i++) {
        new(Adata1 + i) B();                 // ❓：是否可以使用不同类（如类B）的构造函数？可以。
    }
    free(Adata1);                            // free 不会自动调用析构函数

    //  2）new 会自动初始化（调用构造函数）
    cout << "new A" << endl;
    A *Adata2 = new A[n];
    delete[] Adata2;                         // new 会自动调用析构函数

    // + 申请与销毁单个自定义类A大小的空间
    A *Adata3 = new A;
    delete Adata3;
    return 0;
}
