#include <bits/stdc++.h>
using namespace std;
struct node {
    char c;
    int freq;
    node *l;
    node *r;
};
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
    for(int i = 1;i < n;i++) {
        int ind = 0;
        for(int j = 0;j <= n - i;j++) {
            if(arr[ind]->freq > arr[j]->freq) ind = j;
        }
        swap(arr[ind],arr[n - i]);
        ind = 0;
        for(int j = 0;j <= n - i - 1;j++) {
            if(arr[ind]->freq > arr[j]->freq) ind = j;
        }
        swap(arr[ind],arr[n - i - 1]);
        node *nn = getNewNode('\0',arr[n - i]->freq + arr[n - i - 1]->freq);
        nn->l = arr[n - i - 1];
        nn->r = arr[n - i];
        arr[n - i - 1] = nn; 
    }
    return arr[0];
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