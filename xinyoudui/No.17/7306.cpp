#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    priority_queue<int, vector<int>, greater<int>> que;
    scanf("%d", &n);
    for (int i = 1, t; i <= n; i++) {
        scanf("%d", &t);
        que.push(t);
    }
    int a, b, ans = 0;
    while (que.size() > 1) {
        a = que.top();
        que.pop();
        b = que.top();
        que.pop();
        que.push(a + b);
        ans += a + b;
    }
    printf("%d\n", ans);
    return 0;
}