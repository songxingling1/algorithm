#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    scanf("%d", &n);
    priority_queue<int> que;
    for (int i = 1, a; i <= n; i++) {
        scanf("%d", &a);
        que.push(a);
    }
    int a, b, cnt = 0;
    while (n > 1) {
        a = que.top();
        que.pop();
        b = que.top();
        que.pop();
        if (a - 1 <= 0) n--;
        if (b - 1 <= 0) n--;
        que.push(a - 1);
        que.push(b - 1);
        cnt++;
    }
    printf("%d\n", cnt);
    return 0;
}