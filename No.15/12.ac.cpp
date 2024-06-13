#include <bits/stdc++.h>
#define MAX_N 100000
#define BASE 26
using namespace std;
int ch[MAX_N * 30][BASE] = {0};
int fail[MAX_N * 30] = {0};
int flag[MAX_N * 30] = {0};
const char *strs[MAX_N * 30] = {0};
int ch_cnt = 0;
void insert(int root,const char *s) {
    int p = root;
    for(int i = 0;s[i];i++) {
        int ind = s[i] - 'a';
        if(ch[p][ind] == 0) ch[p][ind] = ++ch_cnt;
        p = ch[p][ind];
    }
    strs[p] = strdup(s);
    flag[p] = 1;
}
void buildAc(int root) {
    queue<int> q;
    for(int i = 0;i < BASE;i++) {
        if(ch[root][i] == 0) continue;
        fail[ch[root][i]] = root;
        q.push(ch[root][i]);
    }
    while(!q.empty()) {
        int cur = q.front(),p;
        q.pop();
        for(int i = 0;i < BASE;i++) {
            if(ch[cur][i] == 0) continue;
            p = fail[cur];
            while(p != 0 && ch[p][i] == 0) p = fail[p];
            if(p == 0) p = root;
            else p = ch[p][i];
            fail[ch[cur][i]] = p;
            q.push(ch[cur][i]);
        }
    }
}
void query_ac(int root,const char *s) {
    int p = root,q;
    for(int i = 0;s[i];i++) {
        int ind = s[i] - 'a';
        while(p != 0 && ch[p][ind] == 0) p = fail[p];
        if(p == 0) p = root;
        else p = ch[p][ind];
        q = p;
        while(q) {
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
    query_ac(root,s);
    return 0;
}