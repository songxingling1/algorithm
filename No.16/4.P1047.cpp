#include <bits/stdc++.h>
using namespace std;
int x[10005];
void del(int l, int r) {
    x[l + 1]--;
    x[r + 2]++;
}
int solve(int n) {
    int cnt = 0, ans = 0;
    for (int i = 1; i <= n + 1; i++) {
        cnt += x[i];
        if (cnt == 1) ans++;
    }
    return ans;
}
int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    x[1] = 1;
    for (int i = 1, u, v; i <= m; i++) {
        scanf("%d%d", &u, &v);
        del(u, v);
    }
    printf("%d\n", solve(n));
    return 0;
}