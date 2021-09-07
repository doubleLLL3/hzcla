/*************************************************************************
	> File Name: hashtable.cpp
	> Author: Double
	> Mail: doubleliu3@gmail.com
	> Created Time: Sun 07 Mar 2021 07:13:11 PM CST
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

struct Node {
    char *str;
    Node *next;
};

struct HashTable {
    
};

class HashMap {
public :
    virtual int hash(char *, void *) = 0;
    virtual void insert(char *, void *) = 0;
    virtual int search(char *, void *) = 0;
    virtual void clear() = 0;
};

class MyHash : public vector<vector<string> > {
public :
    int hash(char *str, void *hash) override {
        return hash(str);
    }
    void insert(char *, void *) override {
        
    }
    int search(char *str, void *hash) override {

    }
    void clear() override {
        
    }
};

int main() {


    return 0;
}
