#include <bits/stdc++.h>
using namespace std;
const int dx[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
const int dy[8] = {0, 1, 1, 1, 0, -1, -1, -1};
int s[10005][10005];
int maxa = 0, maxb = 0;
int getAns(int x, int y) {
    int ans = 0, sum;
    int i, j;
    for (int k = 0; k < 8; k++) {
        sum = 0;
        i = x;
        j = y;
        while (i <= maxa && i >= 1 && j <= maxb && j >= 1) {
            if (s[i][j]) sum++;
            i += dx[k];
            j += dy[k];
        }
        ans = max(ans, sum);
    }
    return ans;
}
int main() {
    int n;
    scanf("%d", &n);
    for (int i = 1, a, b; i <= n; i++) {
        scanf("%d%d", &a, &b);
        s[a][b] = 1;
        maxa = max(maxa, a);
        maxb = max(maxb, b);
    }
    int ans = 0;
    for (int i = 1; i <= maxa; i++) {
        for (int j = 1; j <= maxb; j++) {
            ans = max(ans, getAns(i, j));
        }
    }
    printf("%d\n", ans);
    return 0;
}