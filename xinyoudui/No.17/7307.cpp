#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    priority_queue<int> que;
    scanf("%d", &n);
    long long ans = 0;
    for (int i = 1, t; i <= n; i++) {
        scanf("%d", &t);
        que.push(-t);
        que.push(-t);
        ans += t + que.top();
        que.pop();
    }
    printf("%lld\n", ans);
    return 0;
}