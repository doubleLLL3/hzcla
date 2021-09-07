/*************************************************************************
	> File Name: 5.priority_queue.cpp
	> Author: Double
	> Mail: doubleliu3@gmail.com
	> Created Time: Sun 07 Mar 2021 06:25:50 PM CST
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

class IQueue {
public :
    virtual void push(int) = 0;
    virtual void pop() = 0;
    virtual bool empty() = 0;
    virtual int top() = 0;
    virtual int size() = 0;
};

class vector_queue : public IQueue, public vector<int> {
    // vector<int>才是类
public :
    void push(int x) override {
        this->vector<int>::push_back(x);  // this这里要用？
        return ;
    }
    void pop() override {
        if (empty()) return ;
        vector<int>::iterator p = this->begin();
        for (auto iter = begin(); iter != end(); iter++) {
            if (*iter > *p) p = iter;
        }
        erase(p);
        return ;
    }
    bool empty() override {
        return size() == 0;
    }
    int top() override {
        if (empty()) return 0;
        int ans = at(0);
        for (int i = 1; i < size(); i++) {
            ans = max(at(i), ans);
        }
        return ans;
    }
    int size() override {
        return this->vector<int>::size(); 
    }
//private :
    //vector<int> v;  // 多重继承更好，不需要！
};

class heap_queue : public IQueue, public vector<int> {
public :
    void push(int x) override {
        push_back(x);
        up_maintain(size());
        return ;
    }
    void pop() override {
        std::swap(at(0), at(size() - 1));
        pop_back();
        down_maintain(1);
        return ;
    }
    bool empty() override {
        return size() == 0;
    }
    int top() override {
        if (empty()) return 0;
        return at(0); 
    }
    int size() override {
        return this->vector<int>::size();
    }
private :
    void up_maintain(int ind) {
        while (ind > 1 && at(ind - 1) > at((ind / 2) - 1)) {
            std::swap(at(ind - 1), at((ind / 2) - 1));
            ind /= 2;
        }
        return ;
    }
    void down_maintain(int ind) {
        while (ind * 2 <= size()) {
            int temp = ind;
            if (at(ind * 2 - 1) > at(temp - 1)) temp = ind * 2;
            if (ind * 2 + 1 <= size() && at(ind * 2) > at(temp - 1)) temp = ind * 2 + 1;
            if (temp == ind) break;
            std::swap(at(temp - 1), at(ind - 1));
            ind = temp;
        }
        return ;
    }
};

int main() {
    srand(time(0));
    vector_queue q1;
    heap_queue q2;
    for (int i = 0; i < 10; i++) {
        int val = rand() % 100;
        q1.push(val);
        cout << "push q1 : " << val << endl;
    }
    while (!q1.empty()) {
        cout << q1.top() << " ";
        q1.pop();
    }
    cout << endl;
    for (int i = 0; i < 10; i++) {
        int val = rand() % 100;
        q2.push(val);
        cout << "push q2 : " << val << endl;
    }
    while (!q2.empty()) {
        cout << q2.top() << " ";
        q2.pop();
    }
    cout << endl;
    return 0;
}
