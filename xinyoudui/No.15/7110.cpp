#include <bits/stdc++.h>
using namespace std;
int a[1000000];
int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    int sum = 0, cnt = 0;
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        if (sum + a[i] <= m) {
            sum += a[i];
        } else {
            cnt++;
            sum = a[i];
        }
    }
    cnt++;
    printf("%d\n", cnt);
    return 0;
}