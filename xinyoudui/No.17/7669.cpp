#include <bits/stdc++.h>
using namespace std;
int vis[200005];
struct block {
    int weight, id;
    block(int a, int b)
    : weight(a)
    , id(b) {}
    block()
    : weight(0)
    , id(0) {}
};
struct cmp {
    bool operator()(const block &i, const block &j) {
        return i.weight < j.weight;
    }
};
priority_queue<block, vector<block>, cmp> que;
stack<block> sta;
int main() {
    int n;
    scanf("%d", &n);
    int op, x;
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        scanf("%d", &op);
        if (op == 0) {
            scanf("%d", &x);
            sta.emplace(x, cnt);
            que.emplace(x, cnt++);
        } else if (op == 1) {
            if (sta.empty()) continue;
            vis[sta.top().id] = 1;
            sta.pop();
        } else {
            if (sta.empty()) {
                printf("0\n");
                continue;
            }
            while (vis[que.top().id]) que.pop();
            printf("%d\n", que.top().weight);
        }
    }
    return 0;
}