/*************************************************************************
	> File Name: 11.LC-460.cpp
	> Author: Double
	> Mail: doubleliu3@gmail.com
	> Created Time: Sat 30 Jan 2021 04:03:31 PM CST
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
#include <unordered_map>
using namespace std;

class Node {
public :
    Node() : Node(0, 0) {}
    Node(int key, int value) : pre(nullptr), next(nullptr), key(key), value(value), cnt(0) {}
    Node *pre, *next;
    int value, key, cnt;
};

class LRUCache {
public:
    int node_cnt;
    Node head, tail;
    LRUCache *pre, *next;
    LRUCache() : pre(nullptr), next(nullptr) {
        this->node_cnt = 0;
        head.next = &tail;
        tail.pre = &head;
    }
    
    void output() {
        Node *p = head.next;
        while (p) {
            cout << "(" << p->key << "," << p->value << ")->";
            p = p->next;
        }
        cout << endl;
        return ;
    }
    void remove_node(Node *p) {
        p->next->pre = p->pre;
        p->pre->next = p->next;
		node_cnt -= 1;
        return ;
    }
    void insert_tail(Node *p) {
        p->next = &tail;
        p->pre = tail.pre;
        tail.pre->next = p;
        tail.pre = p;
        node_cnt += 1;
        return ;
    }
    void put(Node *p) {
        insert_tail(p);
        return ;
    }
    Node *pop() {
        Node *p = head.next;
        head.next = p->next;
        node_cnt -= 1;
        return p;
    }
};

class LFUCache {
public:
	unordered_map<int, LRUCache *> lfu;
    unordered_map<int, Node *> ind;
    LRUCache head, tail;
    int capacity, node_cnt;
    LFUCache(int capacity) : capacity(capacity), node_cnt(0) {
        head.next = &tail;
        tail.pre = &head;
    }
    void remove_from_LRUCache(Node *p) {
        LRUCache *c1 = lfu[p->cnt];
        c1->remove_node(p);
        if (c1->node_cnt == 0) {
            remove_LRUCache(c1);
            lfu.erase(lfu.find(p->cnt));
            delete(c1);
        }
        node_cnt -= 1;
        return ;
    }
    void remove_LRUCache(LRUCache *c) {
        c->next->pre = c->pre;
        c->pre->next = c->next;
        return ;
    }
    void insert_LRUCache(LRUCache *c1, LRUCache *c2) {
        c2->pre = c1, c2->next = c1->next;
        c1->next->pre = c2, c1->next = c2;
        return ;
    }
    void insert_to_LRUCache(Node *p) {
        LRUCache *c = lfu[p->cnt];
        c->put(p);
        node_cnt += 1;
        return ;
    }
    void move_next_LRUCache(Node *p) {
        LRUCache *c1 = lfu[p->cnt], *c2;
        if (lfu.find(p->cnt + 1) == lfu.end()) {
            c2 = new LRUCache();
            insert_LRUCache(c1, c2);
            lfu[p->cnt + 1] = c2;
        }
        remove_from_LRUCache(p);
        p->cnt += 1;
        insert_to_LRUCache(p);
        return ;
    }

    int get(int key) {
        if (ind.find(key) == ind.end()) return -1;
        Node *p = ind[key];
        move_next_LRUCache(p);
        return p->value;
    }

    void put(int key, int value) {
        if (capacity == 0) return ;
        Node *p;
        if (ind.find(key) == ind.end()) {
            if (node_cnt == capacity) {
                p = head.next->head.next;
                remove_from_LRUCache(p);
                ind.erase(ind.find(p->key));
                delete p;
            }
            p = new Node(key, value);
            if (lfu.find(p->cnt) == lfu.end()) {
                lfu[p->cnt] = new LRUCache();
                insert_LRUCache(&head, lfu[p->cnt]);
            }
            ind[key] = p;
            insert_to_LRUCache(p);
        } else {
            move_next_LRUCache(ind[key]);
            ind[key]->value = value;
        }
        return ;
    }

};

int main() {
    
    return 0;
}
