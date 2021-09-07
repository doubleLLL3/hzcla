/*************************************************************************
	> File Name: 4.deep_copy.cpp
	> Author: Double
	> Mail: doubleliu3@gmail.com
	> Created Time: Sun 28 Feb 2021 03:51:18 PM CST
 ************************************************************************/

#include <iostream>
using namespace std;

class Array {
public :
    // 转换构造函数
    Array(int n = 10) {
        this->n = n;        // 同名n，用this可以区分开
        data = new int[n];  
        // 🌟 new：
        //  类似C中的malloc，但malloc不会自动调用构造函数；
        //  malloc属于函数，而new属于操作符，可重载
    }
    // 🌟 加入深拷贝（非完美，后续注意）
    Array(const Array &a) {
        this->n = a.n;
        this->data = new int[this->n];
        for (int i = 0; i < this->n; i++) {
            this->data[i] = a.data[i];
        }
    }
    // 返回数组大小
    size_t size() const { return this->n; }
    // 🌟 重载"[]"运算符
    //  1）非const版
    int &operator[](int ind) {
        if (ind < 0 || ind >= n) return end;
        return data[ind];
    }
    //  2）const版
    const int &operator[](int ind) const {
        if (ind < 0 || ind >= n) return end;
        return data[ind];
    }
private :
    int *data, end;
    size_t n;
};

// 输出Array对象
//  const类型对象只能调用const类型方法，所以上面还要实现2）const版的"[]"重载
ostream &operator<<(ostream &out, const Array &a) {
    cout << "Array(" << &a << ") ";
    for (int i = 0; i < a.size(); i++) {
        i && out << " ";
        out << a[i];        // 调用的const版的"[]"重载
    }
    return out;
}

int main() {
    Array a;
    for (int i = 0; i < a.size(); i++) {
        a[i] = rand() % 100;// 调用的非const版的"[]"重载
    }
    cout << a << endl;
    Array b = a;            // ❗️如果没有自定义拷贝构造，默认浅拷贝：依次赋值，而只拷贝指针data的地址
    cout << b << endl;
    b[1] = 1111;
    cout << a << endl;
    cout << b << endl;
    return 0;
}
