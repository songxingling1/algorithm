#include <bits/stdc++.h>
#define MAX_N 100000
#define BASE 26
using namespace std;
int nxt[MAX_N * 30][BASE];
int flag[MAX_N * 30];
int fail[MAX_N * 30];
const char *strs[MAX_N * 30];
int ch_cnt = 0;
void insert(int root,const char *s) {
    int p = root;
    for(int i = 0;s[i];i++) {
        int ind = s[i] - 'a';
        if(nxt[p][ind] == 0) nxt[p][ind] = ++ch_cnt;
        p = nxt[p][ind];
    }
    strs[p] = strdup(s);
    flag[p] = 1;
}
void buildAc(int root) {
    queue<int> q;
    q.push(root);
    while(!q.empty()) {
        int t = q.front();
        q.pop();
        for(int i = 0;i < BASE;i++) {
            if(nxt[t][i] == 0) {
                if(t == root) nxt[t][i] = root;
                else nxt[t][i]= nxt[fail[t]][i];
                continue;
            }
            int p = fail[t];
            if(p == 0) p = root;
            else p = nxt[p][i];
            fail[nxt[t][i]] = p;
            q.push(nxt[t][i]);
        }
    }
}
void queryAc(int root,const char *s) {
    int p = root,q;
    for(int i = 0;s[i];i++) {
        int ind = s[i] - 'a';
        p = nxt[p][ind];
        q = p;
        while(q != 0) {
            if(flag[q]) {
                int len = strlen(strs[q]);
                printf("find [%d,%d] = %s\n",i - len + 1,i,strs[q]);
            }
            q = fail[q];
        }
    }
}
int main() {
    int n;
    int root = ++ch_cnt;
    char s[100];
    scanf("%d",&n);
    for(int i = 0;i < n;i++) {
        scanf("%s",s);
        insert(root,s);
    }
    buildAc(root);
    scanf("%s",s);
    queryAc(root,s);
    return 0;
}