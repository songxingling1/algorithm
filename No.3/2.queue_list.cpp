#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *next;
};

struct LinkList {
    Node head,*tail;
    int size;
};

LinkList *initLinkList() {
    LinkList *l = new(nothrow) LinkList;
    if(l == nullptr) return nullptr;
    l->head.next = nullptr;
    l->tail = &(l->head);
    l->size = 0;
    return l;
}

void clearLinkList(LinkList *l) {
    Node *p = l->head.next,*q;
    while(p != nullptr) {
        q = p->next;
        delete p;
        p = q;
    }
    delete l;
}

int atLinkList(LinkList *l,int pos) {
    if(l == nullptr) return -1;
    Node *p = l->head.next;
    for(int i = 0;i < pos;i++) {
        if(p == nullptr) return -1;
        p = p->next;
    }
    if(p == nullptr) return -1;
    else return p->data;
}

void pushLinkList(LinkList *l,int val) {
    Node *p = new(nothrow) Node;
    if(p == nullptr) return;
    p->data = val;
    p->next = nullptr;
    l->tail->next = p;
    l->tail = p;
    l->size += 1;
}

void popLinkList(LinkList *l) {
    if(l == nullptr) return;
    if(l->size == 0) return;
    Node *p = l->head.next;
    l->head.next = l->head.next->next;
    if(p == l->tail) l->tail = &(l->head);
    delete p;
    l->size -= 1;
}

struct Queue{
    LinkList *l;
};

Queue *initQueue() {
    Queue *q = new(nothrow) Queue;
    if(q == nullptr) return nullptr;
    q->l = initLinkList();
    return q;
}

void clearQueue(Queue *q) {
    if(q == nullptr) return;
    clearLinkList(q->l);
    delete q;
}

void pushQueue(Queue *q,int val) {
    pushLinkList(q->l,val);
}

void popQueue(Queue *q) {
    popLinkList(q->l);
}

bool emptyQueue(Queue *q) {
    return q->l->size == 0;
}

int frontQueue(Queue *q) {
    if(emptyQueue(q)) return -1;
    return atLinkList(q->l,0);
}

void output_Queue(Queue *q) {
    int size = q->l->size;
    printf("Queue :");
    Node *pos = q->l->head.next;
    for(int i = 0;i < size;i++) {
        printf("%4d",pos->data);
        pos = pos->next;
    }
    printf("\n\n");
}

int main() {
    srand(time(0));
    #define MAX_OP 10
    Queue *q = initQueue();
    for(int i = 0;i < MAX_OP;i++) {
        int op = rand() % 5,val = rand() % 100; // 0,1 : pop | 2,3,4 : push
        switch(op) {
            case 0:
            case 1:
                printf("front of queue : %d\n",frontQueue(q));
                popQueue(q);
                break;
            case 2:
            case 3:
            case 4:
                printf("push %d to queue\n",val);
                pushQueue(q,val);
                break;
        }
        output_Queue(q);
    }
    clearQueue(q);
    return 0;
}
