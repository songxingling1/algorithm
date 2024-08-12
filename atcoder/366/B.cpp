#include <bits/stdc++.h>
using namespace std;
string s[105];
char c[105][105];
int si[105];
int main() {
    int n,m = 0;
    cin >> n;
    for(int i = 1;i <= n;i++) {
        cin >> s[i];
        m = max((int)s[i].size(),m);
    }
    for(int i = 1;i <= m;i++) {
        for(int j = 1;j <= n;j++) {
            if(i > s[j].size()) {
                c[i][n - j + 1] = '*';
                continue;
            }
            c[i][n - j + 1] = s[j][i - 1];
            si[i] = max(si[i],n - j + 1);
        }
    }
    for (int i = 1; i <= m; i++) {
        for(int j = 1;j <= si[i];j++) {
            printf("%c",c[i][j]);
        }
        puts("");
    }
    return 0;
}