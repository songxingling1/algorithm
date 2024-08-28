#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 5;
int x[MAXN], d[MAXN];
int a[MAXN], b[MAXN], s[MAXN], t[MAXN];
struct train {
    int st, id, time;
    train(int a, int b, int c)
    : st(a)
    , id(b)
    , time(c) {}
    train()
    : st(0)
    , id(0)
    , time(0) {}
};
bool cmp(const train &i, const train &j) {
    if (i.time != j.time) {
        return i.time < j.time;
    }
    if (i.st != j.st) {
        return i.st > j.st;
    }
    return i.id < j.id;
}
int main() {
    int n, m;
    scanf("%d%d%d", &n, &m, x + 1);
    vector<train> q;
    for (int i = 1; i <= m; i++) {
        scanf("%d%d%d%d", a + i, b + i, s + i, t + i);
        q.emplace_back(0, i, s[i]);
        q.emplace_back(1, i, t[i]);
    }
    sort(q.begin(), q.end(), cmp);
    for (train &i : q) {
        if (i.st) {
            d[b[i.id]] = max(d[b[i.id]], t[i.id] + x[i.id]);
        } else {
            x[i.id] = max(x[i.id], d[a[i.id]] - s[i.id]);
        }
    }
    for (int i = 2; i <= m; i++) {
        printf("%d ", x[i]);
    }
    puts("");
    return 0;
}