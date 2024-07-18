#include <bits/stdc++.h>
using namespace std;
string dp[1005];
string add(string a, string b) {
    int len = a.size(), blen = b.size();
    vector<int> ans(max(len, blen) + 5);
    for (int i = 0; i < len; i++) {
        ans[i] = a[len - 1 - i] - '0';
    }
    for (int i = 0; i < blen; i++) {
        ans[i] += b[blen - 1 - i] - '0';
    }
    for (int i = 0; i < ans.size(); i++) {
        if (ans[i] >= 10) {
            ans[i + 1] += ans[i] / 10;
            ans[i] %= 10;
        }
    }
    while (ans.size() > 1 && ans.back() == 0) {
        ans.pop_back();
    }
    string s;
    for (int i = ans.size() - 1; i >= 0; i--) {
        s += ans[i] + '0';
    }
    return s;
}
int main() {
    int n;
    scanf("%d", &n);
    dp[1] = "1";
    dp[2] = "2";
    for (int i = 3; i <= n; i++) {
        dp[i] = add(dp[i - 1], dp[i - 2]);
    }
    cout << dp[n] << endl;
    return 0;
}