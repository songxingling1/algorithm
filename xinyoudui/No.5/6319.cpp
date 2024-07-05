#include <bits/stdc++.h>
#define MAX_N 10000
using namespace std;
int a[MAX_N + 5];
int main() {
    int n, k;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", a + i);
    }
    scanf("%d", &k);
    for (int i = 1; i <= n; i++) {
        if (k == a[i]) {
            printf("%d\n", i - 1);
            return 0;
        }
    }
    printf("-1\n");
    return 0;
}