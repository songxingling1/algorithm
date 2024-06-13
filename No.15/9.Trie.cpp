#include <bits/stdc++.h>
using namespace std;
class Trie {
private:
    class Node {
    public:
        int flag;
        Node *next[26];
        Node():flag(0) {
            for(int i = 0;i < 26;i++) next[i] = nullptr;
        }
        ~Node() {
            for(int i = 0;i < 26;i++) {
                delete next[i];
            }
        }
        Node(const Node &n) {
            flag = n.flag;
            for(int i = 0;i < 26;i++) {
                if(n.next[i] == nullptr) next[i] = nullptr;
                else next[i] = new Node(*n.next[i]);
            }
        }
    };
    Node *root;
    void outputT(Node *r,int n,char *buff) {
        if(r->flag) {
            printf("find : %s\n",buff);
        }
        for(int i = 0;i < 26;i++){
            if(r->next[i] != nullptr) {
                buff[n] = i + 'a';
                outputT(r->next[i],n + 1,buff);
                buff[n] = '\0';
            }
        }
    }
public:
    Trie() {
        root = new Node();
    }
    Trie(const Trie &t) {
        root = new Node(*t.root);
    }
    ~Trie() {
        delete root;
    }
    void insert(const char *s) {
        Node *p = root;
        for(int i = 0;s[i];i++) {
            if(p->next[(int)s[i] - 'a'] == nullptr) p->next[(int)s[i] - 'a'] = new Node;
            p = p->next[(int)s[i] - 'a'];
        }
        p->flag = 1;
    }
    int find(const char *s) {
        Node *p = root;
        for(int i = 0;s[i];i++) {
            if(p->next[(int)s[i] - 'a'] == nullptr) return 0;
            p = p->next[(int)s[i] - 'a'];
        }
        return p->flag;
    }
    void output() {
        char s[100];
        outputT(root,0,s);
    }
};
int main() {
    int op;
    char s[100];
    Trie t;
    while(1) {
        scanf("%d",&op);
        if(op == 3) break;
        scanf("%s",s);
        if(op == 1) {
            printf("insert %s to Trie.\n",s);
            t.insert(s);
        } else {
            printf("find %s from Trie : %d\n",s,t.find(s));
        }
    }
    t.output();
    return 0;
}