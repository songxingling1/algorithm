#include <bits/stdc++.h>
using namespace std;
int main () {
    int n, m;
    scanf ("%d%d", &n, &m);
    vector<int> arr (n + 1), sum (n + 1, 0);
    for (int i = 1; i <= n; i++) {
        scanf ("%d", &arr[i]);
        sum[i] = sum[i - 1] + arr[i];
    }
    deque<int> q;
    int ans = 0;
    q.push_back (0);
    for (int i = 1; i <= n; i++) {
        ans = max (ans, sum[i] - sum[q.front ()]);
        while (!q.empty () && sum[q.back ()] >= sum[i]) {
            q.pop_back ();
        }
        q.push_back (i);
        if (i - q.front () == m)
            q.pop_front ();
    }
    printf ("%d\n", ans);
    return 0;
}
