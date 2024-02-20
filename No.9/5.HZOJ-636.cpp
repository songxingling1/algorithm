#include <bits/stdc++.h>
#include <functional>
#include <queue>
#define MAX_N 100000
using namespace std;
vector<int> gEdge[MAX_N + 5][2];
int gNums[MAX_N + 5];
int gAns[MAX_N + 5] = { 0 };
int main () {
    int n, m;
    scanf ("%d%d", &n, &m);
    for (int i = 1, x, y; i <= m; i++) {
        scanf ("%d%d", &x, &y);
        gEdge[x][0].push_back (y);
        gEdge[y][1].push_back (x);
        gNums[y]++;
    }
    vector<int> tmp;
    priority_queue<int, vector<int>, greater<int>>          // NOLINT
        q;
    for (int i = 1; i <= n; i++) {
        if (gEdge[i][1].empty ()) {
            q.emplace (i);
            gAns[i] = 1;
        }
    }
    while (!q.empty ()) {
        int cur = q.top ();
        q.pop ();
        tmp.emplace_back (cur);
        for (int i : gEdge[cur][0]) {
            gNums[i]--;
            if (gNums[i] == 0)
                q.emplace (i);
        }
    }
    for (int i : tmp) {
        for (int j : gEdge[i][1]) {
            gAns[i] = max (gAns[i], gAns[j] + 1);
        }
    }
    for (int i = 1; i <= n; i++) {
        printf ("%d\n", gAns[i]);
    }
    return 0;
}