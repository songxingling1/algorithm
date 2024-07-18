#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
string jia(string a, string b) {
    int as = a.size(), bs = b.size();
    vector<int> ans(max(as, bs) + 10, 0);
    for (int i = 0; i < as; i++) {
        ans[i] = a[as - 1 - i] - '0';
    }
    for (int i = 0; i < bs; i++) {
        ans[i] += b[bs - 1 - i] - '0';
    }
    for (int i = 0; i < ans.size(); i++) {
        if (ans[i] >= 10) {
            ans[i + 1] += ans[i] / 10;
            ans[i] %= 10;
        }
    }
    while (ans.size() > 1 && ans.back() == 0) ans.pop_back();
    string s;
    for (int i = ans.size() - 1; i >= 0; i--) {
        s += char(ans[i] + '0');
    }
    return s;
}
string chu(string a, int b) {
    int x = 0, flag = 0;
    string ans;
    for (int i = 0; i < a.size(); i++) {
        x = x * 10 + (a[i] - '0');
        if (x < b) {
            if (flag) ans += '0';
            continue;
        }
        ans += x / b + '0';
        x %= b;
        flag = 1;
    }
    return ans;
}
int main() {
    int n;
    cin >> n;
    string s, sum = "0";
    for (int i = 1; i <= n; i++) {
        cin >> s;
        sum = jia(sum, s);
    }
    sum = chu(sum, n);
    cout << sum << endl;
    return 0;
}