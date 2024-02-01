#include <bits/stdc++.h>
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
};
int main () {
    auto* q = new Queue;
    q->push (5);
    printf ("%d\n", q->front ());
    q->push (7);
    printf ("%d\n", q->front ());
    q->pop ();
    printf ("%d\n", q->front ());
    return 0;
}
