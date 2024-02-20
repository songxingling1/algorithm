#include <bits/stdc++.h>
#include <cstdio>
#include <functional>
using namespace std;
struct Node {
    int mNum = 0;
    vector<int> mEdge;
} gNode[2010];
int main () {
    int n, m;
    scanf ("%d%d", &n, &m);
    priority_queue<int, vector<int>, greater<int>>          // NOLINT
        q;
    for (int i = 1, tmp1, tmp2; i <= m; i++) {
        scanf ("%d%d", &tmp1, &tmp2);
        gNode[tmp1].mEdge.emplace_back (tmp2);
        (gNode[tmp2].mNum)++;
    }
    for (int i = 1; i <= n; i++) {
        if (gNode[i].mNum == 0)
            q.emplace (i);
    }
    vector<int> ans;
    while (!q.empty ()) {
        int cur = q.top ();
        q.pop ();
        ans.emplace_back (cur);
        for (int i : gNode[cur].mEdge) {
            gNode[i].mNum--;
            if (gNode[i].mNum == 0)
                q.emplace (i);
        }
    }
    printf ("%d", ans[0]);
    for (int i = 1; i < ans.size (); i++)
        printf (" %d", ans[i]);
    puts ("");
    return 0;
}