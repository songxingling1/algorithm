#include <bits/stdc++.h>
using namespace std;
int ans[2000];
int main() {
    string a, b = "10001";
    cin >> a;
    reverse(a.begin(), a.end());
    for (int i = 0; i < a.size(); i++) {
        for (int j = 0; j < 5; j++) {
            ans[i + j] += (a[i] - '0') * (b[j] - '0');
        }
    }
    int cnt = a.size() + 20;
    for (int i = 0; i <= cnt; i++) {
        if (ans[i] > 1) {
            ans[i + 1] += ans[i] / 2;
            ans[i] %= 2;
        }
    }
    while (cnt > 0 && ans[cnt] == 0) cnt--;
    for (int i = cnt; i >= 0; i--) {
        printf("%d", ans[i]);
    }
    puts("");
    return 0;
}