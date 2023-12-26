#include <bits/stdc++.h>
using namespace std;

class Queue {
private:
    List *l;
public:
    Queue():l(new List) {};
    ~Queue() {
        delete l;
    }
    int getSize() {return l->getSize();}
    bool empty() {
        return l->getSize() == 0;
    } 
    int push(int val) {
        if(l->push_back(val) == -1) return -1;
        return 0;
    }
    int pop() {
        if(l->pop_front() == -1) return -1;
        return 0;
    }
    int front() {
        if(empty(l)) return -1;
        return l[1];
    }
};

int main() {
    return 0;
}
