#include <bits/stdc++.h>
#define MAX_N 100000
using namespace std;
int ch[MAX_N * 40][2];
int cnt = 1,root = 1;
void insert(int x) {
    int p = root;
    for(int i = 30;i >= 0;i--) {
        int ind = !!(x & (1 << i));
        if(ch[p][ind] == 0) ch[p][ind] = ++cnt;
        p = ch[p][ind];
    }
}
int solve(int x) {
    int p = root,ans = 0;
    for(int i = 30;i >= 0;i--) {
        int ind = !!(x & (1 << i));
        if(ch[p][1 - ind] != 0) {
            ans += 1 << i;
            p = ch[p][1 - ind];
        } else {
            p = ch[p][ind];
        }
    }
    return ans;
}
int main() {
    int n,ans = 0,tmp;
    scanf("%d",&n);
    for(int i = 0,a;i < n;i++) {
        scanf("%d",&a);
        insert(a);
        tmp = solve(a);
        ans = max(ans,tmp);
    }
    printf("%d\n",ans);
    return 0;
}