#include <bits/stdc++.h>
using namespace std;
string arr[1005];
string jia(string a, string b) {
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
string cheng(string a, int b) {
    vector<int> ans(a.size() + 100);
    reverse(a.begin(), a.end());
    for (int i = 0; i < a.size(); i++) {
        ans[i] = (a[i] - '0') * b;
    }
    for (int i = 0; i < ans.size(); i++) {
        if (ans[i] > 10) {
            ans[i + 1] += ans[i] / 10;
            ans[i] %= 10;
        }
    }
    while (ans.size() > 1 && ans.back() == 0) ans.pop_back();
    string s;
    for (int i = ans.size() - 1; i >= 0; i--) {
        s = char(ans[i] + '0') + s;
    }
    reverse(s.begin(), s.end());
    return s;
}
int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }
    string ans = "0";
    for (int i = 1; i <= n; i++) {
        ans = jia(ans, cheng(arr[i], (n - 1) * (n - 2) / 2));
    }
    cout << ans << endl;
    return 0;
}