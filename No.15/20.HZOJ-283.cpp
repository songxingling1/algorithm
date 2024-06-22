#include <bits/stdc++.h>
#define MAX_N 100000
using namespace std;
int ch[MAX_N + 5][10];
int flag[MAX_N + 5];
char s[MAX_N + 5];
int cnt = 1,root = 1;
void insert(const char *s) {
    int p = root;
    for(int i = 0;s[i];i++) {
        int ind = s[i] - '0';
        if(ch[p][ind] == 0) ch[p][ind] = ++cnt;
        p = ch[p][ind];
    }
    flag[p] = 1;
}
int solve() {
    queue<int> que;
    que.push(root);
    while(!que.empty()) {
        int c = que.front(),f = 0;
        que.pop();
        for(int i = 0;i <= 9;i++) {
            if(ch[c][i] == 0) continue;
            f = 1;
            que.push(ch[c][i]);
        }
        if(flag[c] && f) {
            return 0;
        }
    }
    return 1;
}
int main() {
    int n;
    scanf("%d",&n);
    for(int i = 0;i < n;i++) {
        scanf("%s",s);
        insert(s);
    }
    if(solve()) {
        printf("YES\n");
    } else {
        printf("NO\n");
    }
    return 0;
}