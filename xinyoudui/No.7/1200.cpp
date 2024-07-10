#include <bits/stdc++.h>
using namespace std;
int cnt[26];
string s;
int main() {
    while (cin >> s) {
        for (int i = 0; i < s.size(); i++) {
            cnt[s[i] - 'a']++;
        }
    }
    for (int i = 0; i < 26; i++) {
        if (cnt[i] == 0) continue;
        printf("%c:%d\n",'a' + i,cnt[i]);
    }
    return 0;
}