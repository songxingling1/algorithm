#include <bits/stdc++.h>
#define MAX_N 20000
using namespace std;
struct Node {
    int fail;
    int next[26];
    vector<int> ind;
}AC[MAX_N + 5];
int node_cnt = 1,root = 1;
char s[1000006],t[200][75];
int tcnt[200];
inline int getNewNode() {
    ++node_cnt;
    AC[node_cnt].fail = 0;
    for(int i = 0;i < 26;i++) AC[node_cnt].next[i] = 0;
    AC[node_cnt].ind.clear();
    return node_cnt;
}
void insert(const char *s,int k) {
    int p = root;
    for(int i = 0;s[i];i++) {
        int ind = s[i] - 'a';
        if(AC[p].next[ind] == 0) AC[p].next[ind] = getNewNode();
        p = AC[p].next[ind];
    }
    AC[p].ind.push_back(k);
}
void buildAC() {
    queue<int> que;
    que.push(root);
    while(!que.empty()) {
        int cur = que.front();
        if(AC[cur].fail != 0) {
            int p = AC[cur].fail;
            for(int i = 0,I = AC[p].ind.size();i < I;i++) {
                AC[cur].ind.push_back(AC[p].ind[i]);
            }
        }
        que.pop();
        for(int i = 0;i < 26;i++) {
            if(AC[cur].next[i] == 0) {
                if(AC[cur].fail == 0) AC[cur].next[i] = root;
                else AC[cur].next[i] = AC[AC[cur].fail].next[i];
                continue;
            }
            int p = AC[cur].fail;
            if(p == 0) p = root;
            else p = AC[AC[cur].fail].next[i];
            AC[AC[cur].next[i]].fail = p;
            que.push(AC[cur].next[i]);
        }
    }
}
void queryAC(const char *s) {
    int p = root;
    for(int i = 0;s[i];i++) {
        int ind = s[i] - 'a';
        p = AC[p].next[ind];
        for(int i = 0,I = AC[p].ind.size();i < I;i++) {
            tcnt[AC[p].ind[i]]++;
        }
    }
}
void init() {
    node_cnt = 0;
    root = getNewNode();
    memset(tcnt,0,sizeof(tcnt));
}
void solve(int n) {
    init();
    for(int i = 0;i < n;i++) {
        scanf("%s",t[i]);
        insert(t[i],i);
    }
    buildAC();
    scanf("%s",s);
    queryAC(s);
    int ans = 0;
    for(int i = 0;i < n;i++) {
        if(ans < tcnt[i]) ans = tcnt[i];
    }
    printf("%d\n",ans);
    for(int i = 0;i < n;i++) {
        if(tcnt[i] == ans) printf("%s\n",t[i]);
    }
}
int main() {
    int n;
    while(1) {
        scanf("%d",&n);
        if(n == 0) break;
        solve(n);
    }
    return 0;
}