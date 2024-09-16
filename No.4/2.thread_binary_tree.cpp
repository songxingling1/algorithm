#include <bits/stdc++.h>
using namespace std;
struct node {
    int key;
    bool ltag, rtag;  //true:线索 false:边
    node *l, *r;
};
node *getNewNode(int key) {
    node *n = new node;
    n->key = key;
    n->ltag = n->rtag = false;
    n->l = nullptr;
    n->r = nullptr;
    return n;
}
node *insert(node *root, int key) {
    if (root == nullptr) return getNewNode(key);
    if (rand() % 2) root->l = insert(root->l, key);
    else root->r = insert(root->r, key);
    return root;
}
void clear(node *root) {
    if (root == nullptr) return;
    if (!root->ltag) clear(root->l);
    if (!root->rtag) clear(root->r);
    delete root;
    return;
}
void preOrder(node *root) {
    if (root == nullptr) return;
    printf("%d ", root->key);
    if (!root->ltag) preOrder(root->l);
    if (!root->rtag) preOrder(root->r);
}
void inOrder(node *root) {
    if (root == nullptr) return;
    if (!root->ltag) inOrder(root->l);
    printf("%d ", root->key);
    if (!root->rtag) inOrder(root->r);
}
node *preNode = nullptr, *inOrderRoot = nullptr;
void __buildInOrderThread(node *root) {
    if (root == nullptr) return;
    if (!root->ltag) __buildInOrderThread(root->l);
    if (inOrderRoot == nullptr && root->l == nullptr)
        inOrderRoot = root;
    if (root->l == nullptr)
        root->l = preNode, root->ltag = true;
    if (preNode != nullptr && preNode->r == nullptr)
        preNode->r = root, preNode->rtag = true;
    preNode = root;
    if (!root->rtag) __buildInOrderThread(root->r);
}
void buildInOrderThread(node *root) {
    __buildInOrderThread(root);
    preNode->r = nullptr;
    preNode->rtag = true;
}
void postOrder(node *root) {
    if (root == nullptr) return;
    if (!root->ltag) postOrder(root->l);
    if (!root->rtag) postOrder(root->r);
    printf("%d ", root->key);
}
node *getNext(node *root) {
    if (root->rtag) return root->r;
    root = root->r;
    while (!root->ltag && root->l != nullptr) {
        root = root->l;
    }
    return root;
}
int main() {
    srand(time(0));
    node *root = nullptr;
    for (int i = 0; i < 10; i++) {
        root = insert(root, rand() % 100);
    }
    buildInOrderThread(root);
    preOrder(root);
    printf("\n");
    inOrder(root);
    printf("\n");
    postOrder(root);
    printf("\n");
    node *n = inOrderRoot;
    while (n != nullptr) {
        printf("%d ", n->key);
        n = getNext(n);
    }
    puts("");
    clear(root);
    return 0;
}