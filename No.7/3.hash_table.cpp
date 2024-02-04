#include <bits/stdc++.h>
#include <cstring>
#include <tools.hpp>
using namespace std;
class HashTable {
private:
    // --------------------链表结构定义：开始------------------
    class ListNode {
    public:
        char* mStr{};
        ListNode* mNext{};
        ListNode ();
        ListNode (const char*);
        ~ListNode ();
    };
    // --------------------链表结构定义：结束------------------
    ListNode* mData;
    int mCnt, mSize;

public:
    HashTable (int);
    ~HashTable ();
    void insert (const char*);
    bool find (const char*);
    void output ();
    void expand ();
};
HashTable::ListNode::ListNode () : mStr (nullptr), mNext (nullptr) {}
HashTable::ListNode::ListNode (const char* s) {
    mStr = strdup (s);
    mNext = nullptr;
}
HashTable::ListNode::~ListNode () {
    ListNode *p = mNext, *q;
    while (p) {
        q = p->mNext;
        delete[] p->mStr;
        free (p);
        p = q;
    }
}
HashTable::HashTable (int n) {
    mData = new ListNode[n];
    mSize = n;
    mCnt = 0;
}
HashTable::~HashTable () {
    delete[] mData;
}
int hash_func (const char* s) {
    int seed = 131, h = 0;
    for (int i = 0; s[i]; i++) {
        h = h * seed + s[i];
    }
    return h & 0x7fffffff;          // NOLINT
}
void HashTable::expand () {
    printf ("expand Hash Table %d -> %d\n", mSize, mSize * 2);
    HashTable* newH = new HashTable (mSize * 2);
    for (int i = 0; i < mSize; i++) {
        ListNode* p = mData[i].mNext;
        while (p) {
            newH->insert (p->mStr);
            p = p->mNext;
        }
    }
    swap (mData, newH->mData);
    swap (mCnt, newH->mCnt);
    swap (mSize, newH->mSize);
    delete newH;
}
void HashTable::insert (const char* s) {
    if (mCnt >= mSize * 2) {
        expand ();
    }
    int hcode = hash_func (s), ind = hcode % mSize;
    ListNode* p = new ListNode (s);
    p->mNext = mData[ind].mNext;
    mData[ind].mNext = p;
    mCnt++;
}
bool HashTable::find (const char* s) {
    int hcode = hash_func (s), ind = hcode % mSize;
    ListNode* p = mData[ind].mNext;
    while (p) {
        if (strcmp (s, p->mStr) == 0)
            return true;
        p = p->mNext;
    }
    return false;
};
void HashTable::output () {
    printf ("\n\nHash Table(%d / %d) : \n", mCnt, mSize);
    for (int i = 0; i < mSize; i++) {
        printf ("%d : ", i);
        ListNode* p = mData[i].mNext;
        while (p) {
            printf ("%s -> ", p->mStr);
            p = p->mNext;
        }
        puts ("");
    }
}
int main () {
    char s[100];
#define MAX_N 2;
    HashTable* h = new HashTable (2);
    while (scanf ("%s", s) != EOF) {
        if (strcmp (s, "end") == 0)
            break;
        h->insert (s);
    }
    h->output ();
    while (scanf ("%s", s) != EOF) {
        printf ("find(%s) = %d\n", s, h->find (s));
    }
#undef MAX_N
    delete h;
    return 0;
}