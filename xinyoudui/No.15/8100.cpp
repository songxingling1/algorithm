#include <bits/stdc++.h>
using namespace std;
int a[1005], ind[1005];
int main() {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", a + i);
        ind[i] = i;
    }
    sort(ind + 1, ind + 1 + n, [](int i, int j) -> bool {
        if (a[i] != a[j]) return a[i] < a[j];
        return i < j;
    });
    long long sum = 0;
    for (int i = 1; i <= n; i++) {
        sum += a[ind[n + 1 - i]] * (i - 1);
    }
    for (int i = 1; i <= n; i++) {
        printf("%d ", ind[i]);
    }
    puts("");
    printf("%.2f", sum * 1.0 / n);
    return 0;
}