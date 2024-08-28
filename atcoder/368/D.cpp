#include <bits/stdc++.h>
using namespace std;
vector<int> edge[200005];
int tag[200005];
int ans = 0;
int dfs(int x, int fa) {
    int flag = tag[x];
    for (int i : edge[x]) {
        if (i == fa) continue;
        flag |= dfs(i, x);
    }
    ans += flag;
    return flag;
}
int main() {
    int n, k;
    scanf("%d%d", &n, &k);
    for (int i = 1, a, b; i <= n - 1; i++) {
        scanf("%d%d", &a, &b);
        edge[a].push_back(b);
        edge[b].push_back(a);
    }
    int root;
    for (int i = 1; i <= k; i++) {
        scanf("%d", &root);
        tag[root] = 1;
    }
    dfs(root, 0);
    printf("%d\n", ans);
    return 0;
}