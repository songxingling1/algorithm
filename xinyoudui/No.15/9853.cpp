#include <bits/stdc++.h>
using namespace std;
char s[1000];
int nxt[1000], pre[1000], vis[1000];
int main() {
    int n;
    cin >> (s + 1) >> n;
    int len = strlen(s + 1) - 1;
    nxt[0] = 1;
    pre[len + 1] = len;
    for (int i = 1; i <= len; i++) {
        nxt[i] = i + 1;
        pre[i] = i - 1;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = nxt[0]; s[j] != '\0'; j = nxt[j]) {
            if (s[nxt[j]] < s[j]) {
                vis[j] = 1;
                nxt[pre[j]] = nxt[j];
                pre[nxt[j]] = pre[j];
                len--;
                break;
            }
        }
        while (len > 1 && s[nxt[0]] == '0') {
            len--;
            nxt[0] = nxt[nxt[0]];
            pre[nxt[0]] = 0;
        }
    }
    int p = nxt[0];
    while (s[p] != '\0') {
        printf("%c", s[p]);
        p = nxt[p];
    }
    puts("");
    return 0;
}