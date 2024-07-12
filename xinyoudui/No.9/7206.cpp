#include <bits/stdc++.h>
using namespace std;
struct Class {
    int m;
    int tot;
    int s;
} arr[100005];
int main() {
    int n,tot = 0;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &arr[i].m);
        for (int j = 1,t; j <= arr[i].m; j++) {
            scanf("%d", &t);
            arr[i].tot += t;
        }
        arr[i].s = arr[i].tot / arr[i].m;
        tot += arr[i].s;
    }
    for (int i = 1; i <= n; i++) {
        if (arr[i].s < tot / n) {
            printf("%d ",i);
        }
    }
    return 0;
}