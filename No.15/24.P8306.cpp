#include <bits/stdc++.h>
using namespace std;
int ch[3000005][128];
int flag[3000005];
int prefix[3000005];
char s[3000005];
int cnt = 1,root = 1;
int getNewNode() {
    cnt++;
    for(int i = 0;i < 128;i++) ch[cnt][i] = 0;
    flag[cnt] = 0;
    prefix[cnt] = 0;
    return cnt;
}
void insert(const char *s) {
    int p = root;
    for(int i = 0;s[i];i++) {
        int ind = s[i] - '0';
        if(ch[p][ind] == 0) ch[p][ind] = getNewNode();
        prefix[p]++;
        p = ch[p][ind];
    }
    prefix[p]++;
    flag[p] = 1;
}
int query(const char *s) {
    int p = root;
    for(int i = 0;s[i];i++) {
        int ind = s[i] - '0';
        if(ch[p][ind] == 0) return 0;
        p = ch[p][ind];
    }
    return prefix[p];
}
void solve() {
    cnt = 0;
    root = getNewNode();
    int n,q;
    scanf("%d%d",&n,&q);
    for(int i = 0;i < n;i++) {
        scanf("%s",s);
        insert(s);
    }
    for(int i = 0;i < q;i++) {
        scanf("%s",s);
        printf("%d\n",query(s));
    }
}
int main() {
    int t;
    scanf("%d",&t);
    while (t--) {
        solve();
    }
    return 0;
}