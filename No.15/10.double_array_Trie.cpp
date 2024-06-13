#include <bits/stdc++.h>
#define MAX_N 100000
#define BASE 26
using namespace std;
class Trie {
public:
    class Node {
    public:
        int flag;
        Node *next[BASE];
        Node():flag(0) {
            for(int i = 0;i < BASE;i++) next[i] = nullptr;
        }
        ~Node() {
            for(int i = 0;i < BASE;i++) {
                delete next[i];
            }
        }
        Node(const Node &n) {
            flag = n.flag;
            for(int i = 0;i < BASE;i++) {
                if(n.next[i] == nullptr) next[i] = nullptr;
                else next[i] = new Node(*n.next[i]);
            }
        }
    };
    Node *root;
private:
    void outputT(Node *r,int n,char *buff) {
        if(r->flag) {
            printf("find : %s\n",buff);
        }
        for(int i = 0;i < BASE;i++){
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
    Node **getNext() const {
        return root->next;
    }
};
class DATrie {
private:
    class DANode {
    public:
        int base,check;
    };
    DANode trie[MAX_N + 5];
    int daTrieRoot = 1;
    int getBase(const Trie::Node &t,int ind) {
        int base = 2;
        do {
            int flag = 1;
            for(int i = 0;i < BASE;i++) {
                if(t.next[i] == nullptr) continue;
                if(trie[base + i].check == 0) continue;
                flag = 0;
                break;
            }
            if(flag) break;
            base++;
        } while(1);
        return base;
    }
    void convert(const Trie::Node &t,int ind) {
        trie[ind].base = getBase(t,ind);
        for(int i = 0;i < BASE;i++) {
            if(t.next[i] == nullptr) continue;
            trie[trie[ind].base + i].check = (t.next[i]->flag ? -ind : ind);
        }
        for(int i = 0;i < BASE;i++) {
            if(t.next[i] == nullptr) continue;
            convert(*t.next[i],trie[ind].base + i);
        }
    }
public:
    DATrie(const Trie &t,int ind) {
        convert(*t.root,ind);
    }
    int find(const char *s) {
        int p = daTrieRoot;
        for(int i = 0;s[i];i++) {
            int ind = trie[p].base + (int)s[i] - 'a';
            if(abs(trie[ind].check) != p) return 0;
            p = ind;
        }
        return trie[p].check < 0;
    }
};
int main() {
    int n;
    char s[100];
    Trie t;
    scanf("%d",&n);
    for(int i = 0;i < n;i++) {
        scanf("%s",s);
        t.insert(s);
    }
    DATrie trie(t,1);
    while(scanf("%s",s) != EOF) {
        printf("find %s frome double array trie : %d\n",s,trie.find(s));
    }
    return 0;
}