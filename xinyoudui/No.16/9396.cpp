#include <bits/stdc++.h>
using namespace std;
int ans[30];
int n;
void print(int cnt) {
    if (cnt == 1) return;
    printf("%d=%d", n, ans[1]);
    for (int i = 2; i <= cnt; i++) {
        printf("+%d", ans[i]);
    }
    puts("");
}
void dfs(int s, int last, int cnt) {
    if (s == 0) {
        print(cnt);
    }
    for (int i = last; i <= s; i++) {
        ans[cnt + 1] = i;
        dfs(s - i, i, cnt + 1);
    }
}
int main() {
    cin >> n;
    dfs(n, 1, 0);
    return 0;
}