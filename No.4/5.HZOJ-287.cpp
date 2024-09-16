#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    scanf("%d", &n);
    priority_queue<int, vector<int>, greater<>> que;
    for (int i = 1, k; i <= n; i++) {
        scanf("%d", &k);
        que.push(k);
    }
    int i1, i2, ans = 0;
    while (que.size() > 1) {
        i1 = que.top();
        que.pop();
        i2 = que.top();
        que.pop();
        ans += i1 + i2;
        que.push(i1 + i2);
    }
    printf("%d\n", ans);
    return 0;
}