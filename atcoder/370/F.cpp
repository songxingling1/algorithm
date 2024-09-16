#include <bits/stdc++.h>
using namespace std;
int a[400010];
int n, k;
int N;
int check(int x) {
    vector<array<int, 25>> up(N + 2);
    up[N + 1][0] = N + 1;
    queue<int> window;
    int r = 1, sum = 0;
    for (int i = 1; i <= N; i++) {
        while (r <= N && sum < x) {
            window.push(a[r]);
            sum += a[r];
            r++;
        }
        if (sum < x) up[i][0] = N + 1;
        else up[i][0] = r;
        sum -= window.front();
        window.pop();
    }
    for (int i = 1; i <= 20; i++) {
        for (int j = 1; j < N + 2; j++) {
            up[j][i] = up[up[j][i - 1]][i - 1];
        }
    }
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        int pos = i;
        for (int j = 0; j <= 20; j++) {
            if ((k >> j) & 1) {
                pos = up[pos][j];
            }
        }
        if (pos <= i + n) cnt++;
    }
    return cnt;
}
int main() {
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; i++) {
        scanf("%d", a + i);
        a[i + n] = a[i];
    }
    N = 2 * n;
    int l = 1, r = 2e9 + 8;
    while (l + 1 < r) {
        int mid = l + (r - l) / 2;
        if (check(mid)) l = mid;
        else r = mid;
    }
    int cnt = check(l);
    printf("%d %d\n", l, n - cnt);
    return 0;
}