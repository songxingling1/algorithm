#include <bits/stdc++.h>
using namespace std;
int arr[20][20];
int dp[20][20];
int main() {
    int a, b, n;
    scanf("%d%d%d", &a, &b, &n);
    for (int i = 1, x, y; i <= n; i++) {
        scanf("%d%d", &x, &y);
        arr[x][y] = 1;
    }
    dp[0][1] = 1;
    for (int i = 1; i <= a; i++) {
        for (int j = 1; j <= b; j++) {
            if (arr[i][j]) continue;
            if (!arr[i - 1][j]) dp[i][j] += dp[i - 1][j];
            if (!arr[i][j - 1]) dp[i][j] += dp[i][j - 1];
        }
    }
    printf("%d\n", dp[a][b]);
    return 0;
}