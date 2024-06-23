#include <bits/stdc++.h>
#define MAX_N 2000
using namespace std;
int ch[MAX_N + 5][26];
int flag[MAX_N + 5];
int cnt = 1,root = 1;
int dp[200005];
void insert(string &s) {
    int p = root;
    int len = s.size();
    for(int i = 0;i < len;i++) {
        int ind = s[i] - 'A';
        if(ch[p][ind] == 0) ch[p][ind] = ++cnt;
        p = ch[p][ind];
    }
    flag[p] = 1;
}
int main() {
    string tmp,s;
    while(cin >> tmp) {
        if(tmp == ".") break;
        insert(tmp);
    }
    while(cin >> tmp) {
        s += tmp;
    }
    dp[0] = 1;
    int len = s.size() - 1,res = 0;
    for(int i = 0;i <= len;i++) {
        if(!dp[i]) continue;
        int c = i,p = root;
        while(c <= len && ch[p][s[c] - 'A'] != 0) {
            p = ch[p][s[c] - 'A'];
            c++;
            if(flag[p] == 1) {
                dp[c] = 1;
                res = max(res,c);
            }
        }
    }
    printf("%d\n",res);
    return 0;
}