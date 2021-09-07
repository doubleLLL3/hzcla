/*************************************************************************
	> File Name: 3.shared_ptr.cpp
	> Author: Double
	> Mail: doubleliu3@gmail.com
	> Created Time: Sat 06 Mar 2021 02:58:32 PM CST
 ************************************************************************/

#include <iostream>
#include <memory> // 智能指针
using namespace std;

namespace haizei {
class A {
public : 
    A() {
        cout << "default constructor" << endl;
    }
    int x, y;
    ~A() {
        cout << "destructor" << endl;
    }
};

class shared_ptr {
public :
    shared_ptr();
    shared_ptr(A *);
    shared_ptr(const shared_ptr &);
    int use_count();
    A *operator->();
    A &operator*();  // 返回引用
    shared_ptr &operator=(const shared_ptr &);
    ~shared_ptr();
private :
    void decrease_by_one();
    void increase_by_one();
    int *cnt;
    A *obj;
};

shared_ptr::shared_ptr() : obj(nullptr), cnt(nullptr) {}
shared_ptr::shared_ptr(A *obj) : obj(obj), cnt(new int(1)) {}
shared_ptr::shared_ptr(const shared_ptr &p) : obj(p.obj), cnt(p.cnt) { increase_by_one(); }
int shared_ptr::use_count() { return cnt ? *cnt : 0; }
A *shared_ptr::operator->() { return obj; }
A &shared_ptr::operator*() { return *obj; }
shared_ptr::~shared_ptr() {
    this->decrease_by_one();
    this->obj = nullptr;
    this->cnt = nullptr;
    /*
    if (this->cnt != nullptr) {
        *(this->cnt) -= 1;
        if (*(this->cnt) == 0) {
            delete this->obj;
            delete this->cnt;
        }
    if (cnt != nullptr) {
        *cnt -= 1;
        if (*cnt == 0) {
            delete obj;
            delete cnt;
        }
        obj = nullptr;
        cnt = nullptr;
    }
    */
}

void shared_ptr::decrease_by_one() {
    if (this->cnt != nullptr) {
        *(this->cnt) -= 1;
        if (*(this->cnt) == 0) {
            delete this->obj;
            delete this->cnt;
        }
    }
    return ;
}

void shared_ptr::increase_by_one() {
    if (cnt != nullptr) {
    // 也不需要this？
        cnt[0] += 1;  // 还可以写*cnt
    }
    return ;
}

shared_ptr &shared_ptr::operator=(const shared_ptr &p) {
    if (p.obj == this->obj) return *this;
    decrease_by_one();  // 不需要加this
    //this->obj = nullptr;  // 不需要吗？
    //this->cnt = nullptr;
    obj = p.obj;
    cnt = p.cnt;
    increase_by_one();
    return *this;
}

} // end of haizei

int main() {
    haizei::A *p1 = new haizei::A();
    p1 = nullptr;  // 发生内存泄漏
    haizei::shared_ptr p2(new haizei::A());
    cout << p2.use_count() << endl;  // 1
    haizei::shared_ptr p3 = p2;
    p2->x = 123; p2->y = 456;
    (*p2).x = 456;
    cout << p2.use_count() << endl;  // 2
    cout << p3.use_count() << endl;  // 2
    p2 = nullptr;  // 不会内存泄露，自动析构
    cout << p3.use_count() << endl;  // 1
    p2 = p3;
    cout << p3.use_count() << endl;  // 2
    return 0;
}
