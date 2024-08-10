#include <bits/stdc++.h>
using namespace std;
struct food {
    int a, b;
} f[200005];
int main() {
    int n;
    long long x, y;
    scanf("%d%lld%lld", &n, &x, &y);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &f[i].a);
    }
    for (int i = 1; i <= n; i++) {
        scanf("%d", &f[i].b);
    }
    sort(f + 1,
         f + 1 + n,
         [&](const food &i, const food &j) -> bool {
             if (x > y) {
                 if (i.b != j.b) return i.b > j.b;
                 return i.a > j.a;
             } else {
                 if (i.a != j.a) return i.a > j.a;
                 return i.b > j.b;
             }
         });
    long long cnt1 = 0, cnt2 = 0;
    int cnt = 0;
    while (cnt < n && cnt1 <= x && cnt2 <= y) {
        cnt++;
        cnt1 += f[cnt].a;
        cnt2 += f[cnt].b;
    }
    printf("%d\n", cnt);
    return 0;
}