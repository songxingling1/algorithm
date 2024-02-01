#include <bits/stdc++.h>
#include <climits>
#include <cmath>
#include <cstdint>
#include <cstdio>
#include "tools.hpp"
using namespace std;
class ListNode {
public:
    ListNode ();
    ListNode (int key, int n);
    int mKey, mLevel;
    ListNode *mNext, *mDown, *mUp;
};
class SkipList {
private:
    ListNode *mHead, *mTail;
    int mAxLevel;

public:
    SkipList (int n);
    ~SkipList ();
    ListNode* find (int x);
    void insert (int x);
    int randLevel ();
    void output ();
};
ListNode::ListNode ()
    : mKey (0),
      mLevel (0),
      mNext (nullptr),
      mDown (nullptr),
      mUp (nullptr) {}
ListNode::ListNode (int key, int n) {
    if (n == 1) {
        mKey = key;
        mLevel = 0;
        mNext = nullptr;
        mUp = nullptr;
        mDown = nullptr;
        return;
    }
    mKey = key;
    mLevel = n - 1;
    ListNode *p, *q;
    mNext = nullptr;
    mUp = nullptr;
    p = new ListNode;
    p->mNext = nullptr;
    p->mUp = this;
    p->mDown = nullptr;
    p->mKey = key;
    p->mLevel = n - 2;
    mDown = p;
    for (int i = n - 3; i >= 0; i--) {
        q = p;
        p = new ListNode;
        q->mDown = p;
        p->mNext = nullptr;
        p->mUp = q;
        p->mDown = nullptr;
        p->mKey = key;
        p->mLevel = i;
    }
}
SkipList::SkipList (int n) {
    mHead = new ListNode (INT_MIN, n);
    mTail = new ListNode (INT_MAX, n);
    ListNode *p = mHead, *q = mTail;
    while (p != nullptr) {
        p->mNext = q;
        p = p->mDown;
        q = q->mDown;
    }
    mAxLevel = n;
    while (mHead->mLevel != 0)
        mHead = mHead->mDown;
}
SkipList::~SkipList () {
    ListNode *p = mHead, *q, *temp, *temp2;
    while (p != nullptr) {
        q = p->mDown;
        temp = p;
        while (temp != nullptr) {
            temp2 = temp->mNext;
            delete temp;
            temp = temp2;
        }
        p = q;
    }
}
ListNode* SkipList::find (int x) {
    ListNode* p = mHead;
    while (p != nullptr && p->mKey != x) {
        if (p->mNext->mKey <= x)
            p = p->mNext;
        else
            p = p->mDown;
    }
    return p;
}
int SkipList::randLevel () {
    int level = 1;
    double p = 1.0 / 2.0;
    while (get_rand_real<double> (0, 1) < p)
        level++;
    return min (mAxLevel, level);
}
void SkipList::insert (int x) {
    int level = randLevel ();
    while (mHead->mLevel + 1 < level)
        mHead = mHead->mUp;
    auto node = new ListNode (x, level);
    ListNode* p = mHead;
    while (p->mLevel != node->mLevel)
        p = p->mDown;
    while (p) {
        while (p->mNext->mKey < node->mKey)
            p = p->mNext;
        node->mNext = p->mNext;
        p->mNext = node;
        p = p->mDown;
        node = node->mDown;
    }
}
void SkipList::output () {
    ListNode* p = mHead;
    int len = 0;
    for (int i = 0; i <= mHead->mLevel; i++) {
        len += printf ("%4d", i);
    }
    puts ("");
    for (int i = 0; i < len; i++)
        printf ("-");
    puts ("");
    while (p->mLevel > 0)
        p = p->mDown;
    while (p) {
        bool flag = (p->mKey != INT_MIN && p->mKey != INT_MAX);
        for (ListNode* q = p; flag && q; q = q->mUp) {
            printf ("%4d", q->mKey);
        }
        if (flag)
            puts ("");
        p = p->mNext;
    }
}
int main () {
    int x;
#define MAX_LEVEL 32
    auto s = new SkipList (MAX_LEVEL);
#undef MAX_LEVEL
    // insert
    while (scanf ("%d", &x)) {
        if (x == -1)
            break;
        s->insert (x);
    }
    s->output ();
    // find
    while (scanf ("%d", &x)) {
        if (x == -1)
            break;
        ListNode* p = s->find (x);
        printf ("find result : ");
        if (p) {
            printf ("key : %d, level = %d\n", p->mKey, p->mLevel);
        } else {
            puts ("nullptr");
        }
    }
    delete s;
    return 0;
}