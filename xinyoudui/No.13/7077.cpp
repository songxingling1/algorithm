#include <bits/stdc++.h>
using namespace std;
char s[300];
string solve(int l, int r) {
    char m = s[l];
    for (int i = l + 1; i <= r; i++) {
        if (s[i] != m) {
            int mid = (r - l + 1) / 2 - 1;
            return "C" + solve(l, l + mid) + solve(l + mid + 1, r);
        }
    }
    if (m == '0') return "A";
    return "B";
}
int main() {
    scanf("%s", s);
    cout << solve(0, strlen(s) - 1) << endl;
    return 0;
}