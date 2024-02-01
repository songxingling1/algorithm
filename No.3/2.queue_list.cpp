#include <bits/stdc++.h>
#include "tools.hpp"
using namespace std;

struct link_list_node {
    int mData;
    link_list_node* mNext;
    link_list_node () : mData (0), mNext (nullptr) {}
    link_list_node (int a, link_list_node* p)
        : mData (a), mNext (p) {}
};
class LinkList {
private:
    link_list_node mHead, *mTail;
    int mSize;

public:
    LinkList () {
        mHead.mData = 0;
        mHead.mNext = nullptr;
        mTail = &mHead;
        mSize = 0;
    }
    ~LinkList () {
        link_list_node *p = mHead.mNext, *q;
        while (p != nullptr) {
            q = p->mNext;
            delete p;
            p = q;
        }
    }
    link_list_node getHead() {return mHead;}
    link_list_node* getTail() {return mTail;}
    int getSize () {
        return mSize;
    }
    int& operator[] (int pos) {
        link_list_node* p = mHead.mNext;
        for (int i = 0; i < pos; i++)
            p = p->mNext;
        return p->mData;
    }
    void pushBack (int val) {
        auto* node = new link_list_node (val, nullptr);
        mTail->mNext = node;
        mTail = node;
        mSize++;
    }
    void popFront () {
        if (mSize == 0)
            return;
        link_list_node* p = mHead.mNext;
        mHead.mNext = mHead.mNext->mNext;
        delete p;
        if (mSize == 1)
            mTail = &mHead;
        mSize--;
    }
};
class Queue {
private:
    LinkList* mL;

public:
    Queue () : mL (new LinkList){};
    ~Queue () {
        delete mL;
    }
    int getSize () {
        return mL->getSize ();
    }
    bool empty () {
        return mL->getSize () == 0;
    }
    void push (int val) {
        mL->pushBack (val);
    }
    void pop () {
        mL->popFront ();
    }
    int front () {
        if (empty ())
            return -1;
        return (*mL)[0];
    }
    void print () {
        int size = mL->getSize();
        printf ("Queue :");
        link_list_node* pos = mL->getHead().mNext;
        for (int i = 0; i < size; i++) {
            printf ("%4d", pos->mData);
            pos = pos->mNext;
        }
        printf ("\n\n");
    }
}
;
int main () {
#define MAX_OP 10
    auto* q = new Queue;
    for (int i = 0; i < MAX_OP; i++) {
        int op = get_rand<int> (0, 5),
            val = get_rand<int> (
                0, 100);          // 0,1 : pop | 2,3,4
                                  // : push
        switch (op) {
            case 0:
            case 1:
                printf ("front of queue : %d\n",
                        q->front ());
                q->pop ();
                break;
            case 2:
            case 3:
            case 4:
                printf ("push %d to queue\n", val);
                q->push (val);
                break;
            default:
                break;
        }
        q->print();
    }
    delete q;
    return 0;
}
