#include <bits/stdc++.h>
using namespace std;
int main() {
    string s;
    cin >> s;
    string ans;
    for (int i = 0; i < s.size() - 1; i++) {
        ans += s[i] + s[i + 1];
    }
    ans += s[s.size() - 1] + s[0];
    cout << ans << endl;
    return 0;
}