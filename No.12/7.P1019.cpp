#include <bits/stdc++.h>
#define MAX_N 20
using namespace std;
int n;
int vis[MAX_N + 5];
string str[MAX_N];
int ans;
int d[MAX_N + 5][MAX_N + 5];
int getLength(string a, string b) {
    int flag;
    for (int i = a.size() - 1; i >= 1; i--) {
        flag = false;
        for (int j = 0; j + i < a.size(); j++) {
            if (a[i + j] == b[j])
                continue;
            flag = true;
            break;
        }
        if (!flag)
            return a.size() - i;
    }
    return 0;
}
void dfs(int top, int sum) {
    if (sum > ans)
        ans = sum;
    for (int i = 1; i <= n; i++) {
        if (!vis[i] || d[top][i] == 0)
            continue;
        vis[i]--;
        dfs(i, sum + str[i].size() - d[top][i]);
        vis[i]++;
    }
}
int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        cin >> str[i];
        vis[i] = 2;
    }
    cin >> str[0];
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            d[i][j] = getLength(str[i], str[j]);
        }
    }
    for (int i = 1; i <= n; i++) {
        if (str[0][0] == str[i][0]) {
            vis[i]--;
            dfs(i, str[i].size());
            vis[i]++;
        }
    }
    printf("%d\n", ans);
    return 0;
}
