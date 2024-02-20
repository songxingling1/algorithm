#include <bits/stdc++.h>
#define MAX_N 10000
using namespace std;
int gFa[MAX_N + 5];
void init(int n) {
    for (int i = 0; i <= n; i++) {
        gFa[i] = i;
    }
}
int find(int x) { // NOLINT
    if (gFa[x] == x)
        return x;
    return find(gFa[x]);
}
int merge(int a, int b) {
    int aa = find(a), bb = find(b);
    if (aa == bb)
        return 1;
    gFa[aa] = bb;
    return 0;
}
void output(int n) {
    int ret = 0;
    for (int i = 0; i <= n; i++)
        ret += printf("%3d", i);
    puts("");
    for (int i = 0; i < ret; i++)
        printf("-");
    puts("");
    for (int i = 0; i <= n; i++) {
        printf("%3d", gFa[i]);
    }
    puts("");
}
int main() {
    int n, a, b;
    cin >> n;
    init(n);
    while (cin >> a >> b) {
        printf("merge %d with %d\n", a, b);
        merge(a, b);
        output(n);
    }
    return 0;
}
