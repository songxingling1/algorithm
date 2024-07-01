#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 2e7 + 10;
typedef long long ll;
ll nxt[MAX_N],ext[MAX_N];
void solve1(string &s) {
    int len = s.size();
    int l = 1,r = 0;
    nxt[0] = len;
    while(1 + r < len && s[r] == s[1 + r]) r++;
    nxt[1] = r;
    for(int i = 2;i < len;i++) {
        r = l + nxt[l] - 1;
        if(i + nxt[i - l] <= r) {
            nxt[i] = nxt[i - l];
        } else {
            int j = max(0,r - i + 1);
            while(i + j < len && s[j] == s[i + j]) j++;
            nxt[i] = j;
            l = i;
        }
    }
}
void solve2(string &a,string &b) {
    int len1 = a.size(),len2 = b.size();
    int l = 0,r = 0;
    while(r < len1 && r < len2 && a[r] == b[r]) r++;
    ext[0] = r;
    for(int i = 1;i < len1;i++) {
        r = l + ext[l] - 1;
        if(i + nxt[i - l] <= r) {
            ext[i] = nxt[i - l];
        } else {
            int j = max(0,r - i + 1);
            while(i + j < len1 && j < len2 && a[i + j] == b[j]) j++;
            ext[i] = j;
            l = i;
        }
    }
}
int main() {
    string a,b;
    ll ans;
    cin >> a >> b;
    solve1(b);
    ans = 0;
    for(int i = 0;i < b.size();i++) {
        ans = ans ^ ((i + 1) * (nxt[i] + 1));
    }
    cout << ans << endl;
    solve2(a,b);
    ans = 0;
    for(int i = 0;i < a.size();i++) {
        ans = ans ^ ((i + 1) * (ext[i] + 1));
    }
    cout << ans << endl;
    return 0;
}