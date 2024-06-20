#include <bits/stdc++.h>
#define MAX_N 1000000
using namespace std;
int ch[MAX_N + 5][26];
int flag[MAX_N + 5];
char s[MAX_N + 5];
int node_cnt = 1,root = 1;
void insert(const char *s) {
    int p = root;
    for(int i = 0;s[i];i++) {
        int ind = s[i] - 'a';
        if(ch[p][ind] == 0) ch[p][ind] = ++node_cnt;
        p = ch[p][ind];
    }
    flag[p]++;
}
int solve(const char *s) {
    int p = root,ans = 0;
    for(int i = 0;s[i];i++) {
        int ind = s[i] - 'a';
        if(ch[p][ind] == 0) break;
        p = ch[p][ind];
        if(flag[p]) ans += flag[p];
    }
    return ans;
}
int main() {
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i = 0;i < n;i++) {
        scanf("%s",s);
        insert(s);
    }
    for(int i = 0;i < m;i++) {
        scanf("%s",s);
        printf("%d\n",solve(s));
    }
    return 0;
}