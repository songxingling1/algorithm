#include <bits/stdc++.h>
using namespace std;
int r[15];
int ans[15];
int n, k;
void print() {
    for (int i = 1; i <= n; i++) {
        printf("%d ", ans[i]);
    }
    puts("");
}
void dfs(int ind, int sum) {
    if (ind == n + 1) {
        if (sum % k == 0) {
            print();
        }
        return;
    }
    for (int i = 1; i <= r[ind]; i++) {
        ans[ind] = i;
        dfs(ind + 1, sum + i);
    }
}
int main() {
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; i++) {
        scanf("%d", r + i);
    }
    dfs(1, 0);
    return 0;
}