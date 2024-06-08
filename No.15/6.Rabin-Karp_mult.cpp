#include <bits/stdc++.h>
#define TEST(namesp,s,t,n) { \
    namesp::solve(s,t,n);    \
}
using namespace std;
namespace Rabin_Karp {
#define MOD 9973
#define BASE 131
    int hash_func(string s) {
        int h = 0;
        int slen = s.size();
        for(int i = slen - 1,kbase = 1;i >= 0;i--) {
            h = (h + (int)s[i] * kbase) % MOD;
            kbase = kbase * BASE % MOD;
        }
        return h;
    }
    void solve(string s,vector<string> &t,int n) {
        unordered_map<int,vector<int>> thash;
        for(int i = 0;i < n;i++) thash[hash_func(t[i])].push_back(i);
        int nbase = 1,tlen = 0;
        for(;t[0][tlen];tlen++) nbase = nbase * BASE % MOD;
        for(int i = 0,h = 0;s[i];i++) {
            h = h * BASE + s[i];
            if(i >= tlen) h = (h - s[i - tlen] * nbase % MOD + MOD) % MOD;
            if(i + 1 < tlen) continue;
            if(thash.find(h) == thash.end()) continue;
            for(int j = 0;j < (int)thash[h].size();j++) {
                if(strncmp(s.c_str() + i - tlen + 1,t[thash[h][j]].c_str(),tlen) == 0) {
                    printf("pos %d : %s\n",i - tlen + 1,t[thash[h][j]].c_str());
                }
            }
        }
    }
#undef MOD
#undef BASE
};
int main() {
    int n;
    string s;
    vector<string> t(100);
    cin >> n;
    for(int i = 0;i < n;i++) cin >> t[i];
    while(cin >> s) {
        TEST(Rabin_Karp,s,t,n);
    }
    return 0;
}