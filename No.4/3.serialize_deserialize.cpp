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
node *getRandomBinaryTree(int n) {
    node *root = nullptr;
    for(int i = 0;i < n;i++) {
        root = insert(root,rand() % 100);
    }
    return root;
}
void clear(node *root) {
    if(root == nullptr) return;
    clear(root->l);
    clear(root->r);
    delete root;
    return;
}
char buf[1000];
int len = 0;
void __serialize(node *root) {
    if(root == nullptr) return;
    len += snprintf(buf + len,100,"%d",root->key);
    if(root->l == nullptr && root->r == nullptr) return;
    len += snprintf(buf + len,100,"(");
    __serialize(root->l);
    if(root->r != nullptr) {len += snprintf(buf + len,100,",");__serialize(root->r);}
    len += snprintf(buf + len,100,")");
    return;
}
void serialize(node *root) {
    memset(buf,0,sizeof(buf));
    len = 0;
    __serialize(root);
    return;
}
void print(node *root) {
    printf("%d(%d, %d)\n",root->key,root->l == nullptr ? -1 : root->l->key,root->r == nullptr ? -1 : root->r->key);
}
void output(node *root) {
    if(root == nullptr) return;
    print(root);
    output(root->l);
    output(root->r);
}
node *deserialize() {
    stack<node*> sta;
    bool flag = false;
    int scode = 0,num = 0;
    node *tmp = nullptr,*p,*root = nullptr;
    for(int i = 0;i < len;i++) {
        switch(scode) { //0 -> 关键字 -> 1        0 -> ( -> 2        0 -> , -> 3        0 -> ) -> 4
            case 0:
                if(isdigit(buf[i])) scode = 1;
                else if(buf[i] == '(') scode = 2;
                else if(buf[i] == ')') scode = 4;
                else scode = 3;
                i--;
                break;
            case 1:
                num = 0;
                while(isdigit(buf[i])) {
                    num = num * 10 + (buf[i] - '0');
                    i++;
                }
                tmp = getNewNode(num);
                if(!sta.empty() && flag == 0) {
                    p = sta.top();
                    p->l = tmp;
                    sta.pop();
                    sta.push(p);
                } else if(!sta.empty() && flag == 1) {
                    p = sta.top();
                    p->r = tmp;
                    sta.pop();
                    sta.push(p);
                } else {
                    sta.push(p);
                }
                i--;
                scode = 0;
                break;
            case 2:
                sta.push(tmp);
                flag = 0;
                scode = 0;
                break;
            case 3: flag = 1;scode = 0;break;
            case 4:
                root = sta.top();
                sta.pop();
                scode = 0;
                break;
        }
    }
    return root;
}
int main() {
    srand(time(0));
    node *root = getRandomBinaryTree(10);
    serialize(root);
    output(root);
    printf("Buff[] : ");
    puts(buf);
    node *new_node = deserialize();
    output(new_node);
    return 0;
}