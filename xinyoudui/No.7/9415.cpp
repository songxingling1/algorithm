#include <bits/stdc++.h>
using namespace std;
int main() {
    string s;
    string ans;
    cin >> s;
    int cnt = 1, num = s[0] - '0';
    for (int i = 1; i < s.size(); i++) {
        if (s[i] - '0' != num) {
            ans += to_string(cnt) + to_string(num);
            cnt = 1;
            num = s[i] - '0';
            continue;
        }
        cnt++;
    }
    ans += to_string(cnt) + to_string(num);
    cout << ans << endl;
    return 0;
}