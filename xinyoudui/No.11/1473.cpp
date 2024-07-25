#include <bits/stdc++.h>
using namespace std;
pair<int, int> arr[1005];
void getKB(double &k, double &b, pair<int, int> x, pair<int, int> y) {
    k = (x.second - y.second) * 1.0 / (x.first - y.first);
    b = y.second - k * y.first;
}
int main() {
    int n;
    scanf("%d", &n);
    for (int i = 1, a, b; i <= n; i++) {
        scanf("%d%d", &a, &b);
        arr[i] = make_pair(a, b);
    }
    double k, b;
    int cnt, ans = 0;
    for (int i = 1; i < n; i++) {
        for (int j = i; j <= n; j++) {
            cnt = 0;
            getKB(k, b, arr[i], arr[j]);
            for (int i = 1; i <= n; i++) {
                if (fabs(k * arr[i].first + b - arr[i].second) <= 0.000001) {
                    cnt++;
                }
            }
            ans = max(ans, cnt);
        }
    }
    printf("%d\n", ans);
    return 0;
}