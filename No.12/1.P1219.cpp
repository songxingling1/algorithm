#include <bits/stdc++.h>
#define MAKER(n) ((1 << (n + 1)) - 2)
using namespace std;
int culomn = 0, l = 0, r = 0, n, total = 0;
int ans[18], mark[1 << 18];
void print () {
    total++;
    if (total > 3)
        return;
    for (int i = 1; i <= n; i++)
        printf ("%d ", ans[i]);
    puts ("");
}
void search (int step) {
    for (int i = culomn; i; i -= (i & (-i))) {
        int ind = mark[i & -i];
        if ((l & (1 << (ind + step - 1)))
            && (r & (1 << (step - ind + n)))) {
            culomn ^= i & -i;
            l ^= 1 << (ind + step - 1);
            r ^= 1 << (step - ind + n);
            ans[step] = ind;
            if (step == n)
                print ();
            else
                search (step + 1);
            culomn ^= i & -i;
            l ^= 1 << (ind + step - 1);
            r ^= 1 << (step - ind + n);
        }
    }
}
int main () {
    scanf ("%d", &n);
    culomn = MAKER (n);
    l = MAKER (2 * n - 1);
    r = MAKER (2 * n - 1);
    for (int i = 1; i <= n; i++)
        mark[1 << i] = i;
    search (1);
    printf ("%d\n", total);
    return 0;
}
