#include <bits/stdc++.h>
using namespace std;
struct node {
    int key;
    node *l;
    node *r;
};
node *getNewNode(int key) {
    node *p = new node;
    p->key = key;
    p->l = p->r = nullptr;
    return p;
}
node *insert(node *root,int key) {
    if(root == nullptr) return getNewNode(key);
    if(rand() % 2) root->l = insert(root->l,key);
    else root->r = insert(root->r,key);
    return root;
}
void clear(node *root) {
    if(root == nullptr) return;
    clear(root->l);
    clear(root->r);
    delete root;
    return;
}
node *que[15];
int head,tail;
void bfs(node *root) {
    head = tail = 0;
    que[tail++] = root;
    while(head < tail) {
        node *n = que[head];
        printf("\nnode:%d\n",n->key);
        if(n->l != nullptr) {
            que[tail++] = n->l;
            printf("\t%d->%d (left) \n",n->key,n->l->key);
        }
        if(n->r != nullptr) {
            que[tail++] = n->r;
            printf("\t%d->%d (right) \n",n->key,n->r->key);
        }
        head++;
    }
}
int tot = 0;
void dfs(node *root) {
    if(root == nullptr) return;
    int start,end;
    tot++;
    start = tot;
    if(root->l != nullptr) dfs(root->l);
    if(root->r != nullptr) dfs(root->r);
    tot++;
    end = tot;
    printf("%d : [%d, %d]\n",root->key,start,end);
}


int main() {
    srand(time(0));
    node *root = nullptr;
    for(int i = 0;i < 10;i++) {
        root = insert(root,rand() % 100);
    }
    bfs(root);
    dfs(root);
    clear(root);
    return 0;
}