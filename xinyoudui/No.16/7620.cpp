#include <bits/stdc++.h>
using namespace std;
int a[2000];
int vis[30];
int k[30];
int n;
void dfs(int x, int sum, int last) {
    a[sum] = 1;
    if (x == 0) {
        return;
    }
    for (int i = last; i <= n; i++) {
        if (vis[i]) continue;
        vis[i] = 1;
        dfs(x - 1, sum + k[i], i + 1);
        vis[i] = 0;
    }
}
int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", k + i);
    }
    dfs(n, 0, 1);
    int ans = 0;
    for (int i = 1; i <= 1000; i++) {
        if (a[i]) ans++;
    }
    printf("%d\n", ans);
    return 0;
}