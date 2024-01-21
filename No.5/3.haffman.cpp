#include <bits/stdc++.h>
#define F(n) ((n) / 2)
#define LS(n) ((n) * 2)
#define RS(n) ((n) * 2 + 1)
using namespace std;
struct node {
    char c;
    int freq;
    node *l;
    node *r;
};
struct heap {
    node **__data,**data;
    int size,count;
};
heap *getNewHeap(int n) {
    heap *p = new heap;
    p->__data = new node*[n];
    p->data = p->__data - 1;
    p->size = n;
    p->count = 0;
    return p;
}
node *top(heap *h) {
    if(h->count == 0) return nullptr;
    return h->data[1];
}
bool fullHeap(heap *h) {
    return h->count == h->size;
}
bool pushHeap(heap *h,node *n) {
    if(fullHeap(h)) return false;
    (h->count)++;
    h->data[h->count] = n;
    int i = h->count;
    while(i > 1 && h->data[i]->freq < h->data[F(i)]->freq) {
        swap(h->data[i],h->data[F(i)]);
        i = F(i);
    }
    return true;
}
bool popHeap(heap *h) {
    if(h->count == 0) return false;
    h->data[1] = h->data[h->count];
    (h->count)--;
    int i = 1;
    int ind;
    while(LS(i) <= h->count) {
        ind = i;
        if(h->data[LS(i)]->freq < h->data[ind]->freq) ind = LS(i);
        if(RS(i) <= h->count && h->data[RS(i)]->freq < h->data[ind]->freq) ind = RS(i);
        if(ind == i) break;
        swap(h->data[ind],h->data[i]);
        i = ind;
    }
    return true;
}
void clearHeap(heap *h) {
    if(h == nullptr) return;
    delete[] h->__data;
    delete h;
}
node *getNewNode(char key,int freq) {
    node *p = new node;
    p->c = key;
    p->freq = freq;
    p->l = p->r = nullptr;
    return p;
} 
void clear(node *root) {
    if(root == nullptr) return;
    clear(root->l);
    clear(root->r);
    delete root;
    return;
}
unordered_map<char,int> r;
void getRandomData() {
    char c;
    int is;
    for(int i = 0;i < 26;i++) {
        c = 'a' + i;
        is = rand() % 100000;
        r[c] = is;
    }
}
node *buildHaffmanTree(node **arr,int n) {
    heap *h = getNewHeap(n);
    for(int i = 0;i < n;i++) {
        pushHeap(h,arr[i]);
    }
    for(int i = 1;i < n;i++) {
        node *node1 = top(h);
        popHeap(h);
        node *node2 = top(h);
        popHeap(h);
        node *node3 = getNewNode('\0',node1->freq + node2->freq);
        node3->l = node1;
        node3->r = node2;
        pushHeap(h,node3);
    }
    node *ret = top(h);
    clearHeap(h);
    return ret;
}
void extractHaffmanCode(node *root,char *buff,int i) {
    buff[i] = 0;
    if(root->l == nullptr && root->r == nullptr) {
        printf("%c : %s\n",root->c,buff);
        return;
    }
    buff[i] = '0';
    extractHaffmanCode(root->l,buff,i + 1);
    buff[i] = '1';
    extractHaffmanCode(root->r,buff,i + 1);
};
int main() {
    int n = 26;
    node **node_arr = new node*[n];
    getRandomData();
    for(int i = 0;i < n;i++) {
        node_arr[i] = getNewNode('a' + i,r['a' + i]);
    }
    node *root = buildHaffmanTree(node_arr,n);
    char buff[1000];
    extractHaffmanCode(root,buff,0);
    clear(root);
    return 0;
}