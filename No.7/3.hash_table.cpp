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
};
HashTable::ListNode::ListNode () : mStr (nullptr), mNext (nullptr) {}
HashTable::ListNode::ListNode (const char* s) {
    mStr = strdup (s);
    mNext = nullptr;
}
HashTable::HashTable (int n) {
    mData = new ListNode[n];
    mSize = n;
    mCnt = 0;
}
HashTable::~HashTable () {
    for (int i = 0; i < mSize; i++) {
        ListNode* p = mData[i].mNext,*q;
    }
}
int main () {
    ;
    return 0;
}