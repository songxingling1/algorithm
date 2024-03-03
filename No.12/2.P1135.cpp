#include <bits/stdc++.h>
#define MAX_N 200
using namespace std;
int k[MAX_N + 5];
int anser[MAX_N + 5] = { 0 };
int n, a, b;
void search (int sta, int step) {
    if (anser[sta] <= step)
        return;
    anser[sta] = step;
    if (sta - k[sta] >= 1) {
        search (sta - k[sta], step + 1);
    }
    if (sta + k[sta] <= n) {
        search (sta + k[sta], step + 1);
    }
}
int main () {
    scanf ("%d%d%d", &n, &a, &b);
    for (int i = 1; i <= n; i++)
        scanf ("%d", &k[i]);
    for (int i = 1; i <= n; i++)
        anser[i] = n + 1;
    search (a, 0);
    printf ("%d\n", anser[b] == n + 1 ? -1 : anser[b]);
    return 0;
}
