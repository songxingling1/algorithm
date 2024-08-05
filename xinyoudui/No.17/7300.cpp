#include <bits/stdc++.h>
using namespace std;
int main() {
    priority_queue<int> que;
    int op, x, n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &op);
        if (op == 1) {
            scanf("%d", &x);
            que.push(x);
        } else {
            if (que.empty()) {
                printf("Empty.\n");
                continue;
            } else {
                printf("%d\n", que.top());
            }
            que.pop();
        }
    }
    return 0;
}