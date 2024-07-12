#include <bits/stdc++.h>
using namespace std;
struct X {
    int a, b, c;
} a[100005];
int main() {
    int n, maxa = 0, maxb = 0, maxc = 0;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d%d%d", &a[i].a, &a[i].b, &a[i].c);
        maxa = max(maxa, a[i].a);
        maxb = max(maxb, a[i].b);
        maxc = max(maxc, a[i].c);
    }
    int flag = 1;
    for (int i = 1; i <= n; i++) {
        if (maxa == a[i].a && maxb == a[i].b && maxc == a[i].c) {
            printf("%d ", i);
            flag = 0;
        }
    }
    if (flag) printf("-1\n");
    return 0;
}