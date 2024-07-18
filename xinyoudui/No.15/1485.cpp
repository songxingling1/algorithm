#include <bits/stdc++.h>
using namespace std;
int a[30005];
int main() {
    int w, n;
    scanf("%d%d", &w, &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", a + i);
    }
    sort(a + 1, a + 1 + n);
    int i = 1, j = n;
    int cnt = 0;
    while (i <= j) {
        if (a[i] + a[j] <= w) {
            i++;
            j--;
        } else {
            j--;
        }
        cnt++;
    }
    printf("%d\n", cnt);
    return 0;
}