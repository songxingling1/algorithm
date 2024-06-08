#include <bits/stdc++.h>
#define TEST(namesp,s,t) {                                      \
    printf("%s(%s,%s) = %d\n",#namesp,s,t,namesp::solve(s,t));           \
}
using namespace std;
namespace Rabin_Karp {
#define MOD 9973
#define BASE 131
    int hash_func(const char *s) {
        int h = 0;
        int slen = strlen(s);
        for(int i = slen - 1,kbase = 1;i >= 0;i--) {
            h = (h + (int)s[i] * kbase) % MOD;
            kbase = kbase * BASE % MOD;
        }
        return h;
    }
    int solve(const char *s,const char *t) {
        int thash = hash_func(t);
        int nbase = 1,tlen = 0;
        for(;t[tlen];tlen++) nbase = nbase * BASE % MOD;
        for(int i = 0,h = 0;s[i];i++) {
            h = h * BASE + s[i];
            if(i >= tlen) h = (h - s[i - tlen] * nbase % MOD + MOD) % MOD;
            if(i + 1 < tlen) continue;
            if(h != thash) continue;
            if(strncmp(s + i - tlen + 1,t,tlen) == 0) {
                return i - tlen + 1;
            }
        }
        return -1;
    }
#undef MOD
#undef BASE
};
int main() {
    char s[100],t[100];
    while(scanf("%s%s",s,t) != EOF) {
        TEST(Rabin_Karp,s,t);
    }
    return 0;
}