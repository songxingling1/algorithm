#include <bits/stdc++.h>
using namespace std;
int arr[1500][1500];
void sets(int x1, int y1, int x2, int y2) {
    for (int i = x1; i <= x2; i++) {
        for (int j = y1; j <= y2; j++) {
            arr[i][j] = 1;
        }
    }
}
void solve(int x1, int y1, int x2, int y2) {
    if (x1 >= x2 && y1 >= y2) return;
    const int mid = (x2 - x1 + 1) / 2 - 1;
    sets(x1, y1, x1 + mid, y1 + mid);
    solve(x1, y1 + mid + 1, x1 + mid, y1 + 2 * mid + 1);
    solve(x1 + mid + 1, y1, x1 + 2 * mid + 1, y1 + mid);
    solve(x1 + mid + 1, y1 + mid + 1, x1 + 2 * mid + 1, y1 + 2 * mid + 1);
}
int main() {
    int n;
    scanf("%d", &n);
    int len = 1 << n;
    solve(1, 1, len, len);
    for (int i = 1; i <= len; i++) {
        for (int j = 1; j <= len; j++) {
            printf("%d ", 1 - arr[i][j]);
        }
        puts("");
    }
    return 0;
}