#include <bits/stdc++.h>
using namespace std;

struct  Queue{
    Linklist *l;
};

Queue *initQueue() {
    Queue *q = new Queue;
    q->l = initLinkList();
}

void clearQueue(Queue *q) {
    if(q == nullptr) return;
    clearLinkList(q->l);
    delete q;
}

void pushQueue(Queue *q,int val) {
    pushLinkList(q->l,val);
}

void popQueue() {
    popLinkList(q->l);
}

bool emptyQueue(Queue *q) {
    return q->l->size == 0;
}

int frontQueue(Queue *q) {
    if(emptyQueue(q)) return -1;
    return atLinkList(q->l,0);
}
int main() {
    return 0;
}
