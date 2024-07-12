#include <bits/stdc++.h>
using namespace std;
int main() {
    string s, ans;
    int t, tmp;
    cin >> s >> t;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] >= 'a' && s[i] <= 'z') {
            tmp = (s[i] - 'a' + t) % 26;
            ans += tmp + 'a';
        } else {
            tmp = (s[i] - 'A' + t) % 26;
            ans += tmp + 'A';
        }
    }
    cout << ans << endl;
    return 0;
}