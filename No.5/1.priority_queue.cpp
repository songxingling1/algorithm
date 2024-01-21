#include <bits/stdc++.h>
#define F(n) n / 2
#define LS(n) n * 2
#define RS(n) n * 2 + 1
using namespace std;
struct PriorityQueue {
    int *data,*__data;
    int size,count;
};
PriorityQueue *initPQ(int n) {
    PriorityQueue *q = new PriorityQueue;
    q->__data = new int[n];
    q->data = q->__data - 1;
    q->size = n;
    q->count = 0;
    return q;
}
bool emptyPQ(PriorityQueue *p) {
    return p->count == 0;
}
int fullPQ(PriorityQueue *p) {
    return p->count == p->size;
}
int topPQ(PriorityQueue *p) {
    if(p->count == 0) return -1;
    return p->data[1];
}
void upPQ(PriorityQueue *p) {
    int pos = p->count;
    while(pos > 1) {
        if(p->data[pos] > p->data[F(pos)]) {
            swap(p->data[pos],p->data[F(pos)]);
            pos /= 2;
        } else {
            break;
        }
    }
}
void downPQ(PriorityQueue *p) {
    swap(p->data[1],p->data[p->count]);
    (p->count)--;
    int pos = 1,ids;
    while(LS(pos) <= p->count || RS(pos) <= p->count) {
        ids = pos;
        if(p->data[ids] < p->data[LS(pos)] && LS(pos) <= p->count) {
            ids = LS(pos);
        }
        if(p->data[ids] < p->data[RS(pos)] && RS(pos) <= p->count) {
            ids = RS(pos);
        } 
        if(ids == pos){
            break;
        }
        swap(p->data[pos],p->data[ids]);
        if(ids == LS(ids)) {
            pos = LS(pos);
        }else {
            pos = RS(pos);
        }
    }
}
bool pushPQ(PriorityQueue *q,int n) {
    if(fullPQ(q)) return false;
    (q->count)++;
    q->data[q->count] = n;
    upPQ(q);
    return true;
}
int popPQ(PriorityQueue *q) {
    if(emptyPQ(q)) return false;
    downPQ(q);
    return true;
}
void clearPQ(PriorityQueue *p) {
    if(p == nullptr) return;
    delete (p->__data);
    delete p;
}
void output(PriorityQueue *p) {
    printf("PQ(%d) : ",p->count);
    for(int i = 1;i <= p->count;i++) {
        printf("%d ",p->data[i]);
    }
    puts("");
}
int main() {
    srand(time(0));
    int n,t;
    PriorityQueue *q = initPQ(100);
    while(~scanf("%d",&t)) {
        if(t) {
            scanf("%d",&n);
            printf("insert %d to priority_queue\n",n);
            pushPQ(q,n);
            output(q);
        } else {
            printf("top : %d\n",topPQ(q));
            popPQ(q);
            output(q);
        }
    }
    clearPQ(q);
    return 0;
}