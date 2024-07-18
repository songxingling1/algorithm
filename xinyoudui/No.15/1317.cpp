#include <bits/stdc++.h>
using namespace std;
struct s {
    int t, w;
} a[105];
int main() {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i].t);
    }
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i].w);
    }
    sort(a + 1, a + 1 + n, [](const s &i, const s &j) -> bool {
        if (i.t != j.t) return i.t > j.t;
        else return i.w > j.w;
    });
    int time = a[1].t, score = 0, i = 1;
    priority_queue<int, vector<int>, less<int>> q;
    while (time) {
        while (a[i].t == time) q.push(a[i++].w);
        if (!q.empty()) {
            score += q.top();
            q.pop();
        }
        time--;
    }
    printf("%d\n", score);
    return 0;
}