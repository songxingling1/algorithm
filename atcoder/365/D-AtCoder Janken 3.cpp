#include <bits/stdc++.h>
using namespace std;
int dp[3], dp2[3];
int main() {
    int n;
    string s;
    cin >> n >> s;
    map<char, int> tie{{'R', 0}, {'P', 1}, {'S', 2}};
    map<int, int> win{{0, 1}, {1, 2}, {2, 0}};
    for (int i = 0; i < n; i++) {
        dp2[0] = -0x3f3f3f3f;
        dp2[1] = -0x3f3f3f3f;
        dp2[2] = -0x3f3f3f3f;
        int pid = tie[s[i]];
        int id = win[pid];
        for (int j = 0; j < 3; j++) {
            if (j != id) {
                dp2[id] = max(dp2[id], dp[j] + 1);
            }
            if (j != pid) {
                dp2[pid] = max(dp2[pid], dp[j]);
            }
        }
        dp[0] = dp2[0];
        dp[1] = dp2[1];
        dp[2] = dp2[2];
    }
    printf("%d\n", max(dp[0], max(dp[1], dp[2])));
    return 0;
}