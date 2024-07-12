#include <bits/stdc++.h>
using namespace std;
struct change {
    int u, v;
    int ans[1005];
} a[1005];
int arr[1005];
int c[1005];
int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%d", arr + i);
    }
    for (int i = 1; i <= n; i++) {
        a[1].ans[i] = arr[i];
    }
    for (int i = 1; i <= m; i++) {
        scanf("%d%d", &a[i].u, &a[i].v);
        a[i].ans[a[i].u] = a[i].v;
        for (int j = 1; j <= n; j++) {
            a[i + 1].ans[j] = a[i].ans[j];
        }
    }
    for (int i = 1,t; i <= m; i++) {
        scanf("%d", &t);
        for (int j = 1; j <= n; j++) {
            printf("%d ",a[t].ans[j]);
        }
        puts("");
    }
    return 0;
}