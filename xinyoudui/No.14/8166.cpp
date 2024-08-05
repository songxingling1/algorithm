#include <bits/stdc++.h>
using namespace std;
int dp[20][10];
int main() {
    int a, b;
    scanf("%d%d", &a, &b);
    a++;
    b++;
    dp[0][1] = 1;
    for (int i = 1; i <= a; i++) {
        for (int j = 1; j <= b; j++) {
            dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
        }
    }
    printf("%d\n", dp[a][b]);
    return 0;
}