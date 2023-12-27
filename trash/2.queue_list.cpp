#include <bits/stdc++.h>
using namespace std;
struct LinkListNode {
    int data;
    LinkListNode *next;
    LinkListNode():data(0),next(nullptr) {}
    LinkListNode(int a,LinkListNode *p):data(a),next(p){}
};
class LinkList {
private:
    LinkListNode head,*tail;
    int size;
public:
    LinkList() {
        head.data = 0;
        head.next = nullptr;
        tail = &head;
        size = 0;
    }
    ~LinkList() {
        LinkListNode *p = head.next,*q;
        while(p != nullptr) {
            q = p->next;
            delete p;
            p = q;
        }
    }
    int getSize() {return size;}
    int &operator[](int pos) {
        LinkListNode *p = head.next;
        for(int i = 0;i < pos;i++) p = p->next;
        return p->data;
    }
    void push_back(int val) {
        printf("%p\n",tail);
        LinkListNode *node = new LinkListNode(val,nullptr);
        tail->next = node;
        tail = node;
        size++;
    }
    void pop_front() {
        if(size == 0) return;
        LinkListNode *p = head.next;
        head.next = head.next->next;
        delete p;
        if(size == 1) tail = &head;
        size--;
    }
};
class Queue {
private:
    LinkList *l;
public:
    Queue():l(new LinkList) {};
    ~Queue() {
        delete l;
    }
    int getSize() {return l->getSize();}
    bool empty() {
        return l->getSize() == 0;
    } 
    void push(int val) {
        l->push_back(val);
    }
    void pop() {
        l->pop_front();
    }
    int front() {
        if(empty()) return -1;
        return (*l)[0];
    }
};
int main() {
    Queue *q;
    q->push(5);
    printf("%d\n",q->front());
    q->push(7);
    printf("%d\n",q->front());
    q->pop();
    printf("%d\n",q->front());
    return 0;
}
