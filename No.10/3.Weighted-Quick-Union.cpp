#include <bits/stdc++.h>
#define MAX_N 10000
using namespace std;
int gFa[MAX_N + 5];
int gSize[MAX_N + 5];
void init (int n) {
    for (int i = 0; i <= n; i++) {
        gFa[i] = i;
        gSize[i] = 1;
    }
}
int find (int x) {          // NOLINT
    if (gFa[x] == x)
        return x;
    return find (gFa[x]);
}
int merge (int a, int b) {
    int aa = find (a), bb = find (b);
    if (aa == bb)
        return 1;
    if (gSize[aa] < gSize[bb]) {
        gFa[aa] = bb;
        gSize[bb] += gSize[aa];
    } else {
        gFa[bb] = aa;
        gSize[aa] += gSize[bb];
    }
    return 0;
}
void output (int n) {
    int ret = 0;
    for (int i = 0; i <= n; i++)
        ret += printf ("%3d", i);
    puts ("");
    for (int i = 0; i < ret; i++)
        printf ("-");
    puts ("");
    for (int i = 0; i <= n; i++) {
        printf ("%3d", gFa[i]);
    }
    puts ("");
    for (int i = 0; i <= n; i++) {
        printf ("%3d", gSize[i]);
    }
    puts ("");
}
int main () {
    int n, a, b;
    cin >> n;
    init (n);
    while (cin >> a >> b) {
        printf ("merge %d with %d\n", a, b);
        merge (a, b);
        output (n);
    }
    return 0;
}
