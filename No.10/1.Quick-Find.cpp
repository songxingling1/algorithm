#include <bits/stdc++.h>
#define MAX_N 10000
using namespace std;
int gColor[MAX_N + 5];
#ifdef DEBUG
#endif
void init (int n) {
    for (int i = 0; i <= n; i++)
        gColor[i] = i;
}

inline int find (int a) {
    return gColor[a];
}

int merge (int a, int b, int n) {
    int aa = find (a), bb = find (b);
    if (aa == bb)
        return 1;
    for (int i = 0; i <= n; i++) {
        if (find (i) == aa) {
            gColor[i] = bb;
        }
    }
    return 0;
}
void output (int n) {
    int ret = 0;
    for (int i = 0; i < n; i++)
        ret += printf ("%3d", i);
    puts ("");
    for (int i = 0; i < ret; i++)
        printf ("-");
    puts ("");
    for (int i = 0; i < n; i++) {
        printf ("%3d", gColor[i]);
    }
    puts ("");
}
int main () {
    int n, x, y;
    cin >> n;
    init (n);
    while (cin >> x >> y) {
        printf ("merge %d wth %d", x, y);
        merge (x, y, n);
        output (n);
    }
    return 0;
}
