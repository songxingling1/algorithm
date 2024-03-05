#include <bits/stdc++.h>
#define MAX_N 200
using namespace std;
int x[MAX_N + 5], ans[MAX_N + 5];
int n, a, b;
void search (int flo, int step) {
    if (ans[flo] <= step)
        return;
    ans[flo] = step;
    if (flo + x[flo] <= n)
        search (flo + x[flo], step + 1);
    if (flo - x[flo] >= 1)
        search (flo - x[flo], step + 1);
}
int main () {
    scanf ("%d%d%d", &n, &a, &b);
    for (int i = 1; i <= n; i++)
        scanf ("%d", &x[i]);
    for (int i = 1; i <= n; i++)
        ans[i] = n + 1;
    search (a, 0);
    printf ("%d\n", ans[b] == n + 1 ? -1 : ans[b]);
    return 0;
}
