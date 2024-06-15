#include <bits/stdc++.h>
using namespace std;
int ch[1000005][26];
int flag[1000005];
int fail[1000005];
char s[1000005];
int ch_cnt = 0;
void insert(int root,const char *s) {
    int p = root;
    for(int i = 0;s[i];i++) {
        int ind = s[i] - 'a';
        if(ch[p][ind] == 0) ch[p][ind] = ++ch_cnt;
        p = ch[p][ind];
    }
    flag[p]++;
}
void buildAc(int root) {
    queue<int> q;
    q.push(root);
    fail[root] = 0;
    while(!q.empty()) {
        int cur = q.front(),p;
        q.pop();
        for(int i = 0;i < 26;i++) {
            if(ch[cur][i] == 0) {
                if(cur == root) ch[cur][i] = root;
                else ch[cur][i] = ch[fail[cur]][i];
                continue;
            }
            p = fail[cur];
            if(p == 0) p = root;
            else p = ch[p][i];
            fail[ch[cur][i]] = p;
            q.push(ch[cur][i]);
        }
    }
}
int queryAc(int root,const char *s) {
    int p = root,ans = 0;
    for(int i = 0;s[i];i++) {
        int ind = s[i] - 'a';
        p = ch[p][ind];
        ans += flag[p];
        flag[p] = 0;
    }
    return ans;
}
int main() {
    int n,root = ++ch_cnt;
    scanf("%d",&n);
    for(int i = 0;i < n;i++) {
        scanf("%s",s);
        insert(root,s);
    }
    buildAc(root);
    scanf("%s",s);
    printf("%d\n",queryAc(root,s));
    return 0;
}