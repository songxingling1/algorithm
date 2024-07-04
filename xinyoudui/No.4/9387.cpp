#include <bits/stdc++.h>
using namespace std;
int main() {
    int m, n;
    scanf("%d%d", &m, &n);
    for (int x = 1, y; x < m; x++) {
        y = m - x;
        if (x * y == n) {
            printf("yes\n");
            return 0;
        }
    }
    printf("no\n");
    return 0;
}