#include <bits/stdc++.h>
#define TEST(namesp,s,t) {                                      \
    printf("%s(%s,%s) = %d\n",#namesp,s,t,namesp::solve(s,t));           \
}
using namespace std;
namespace Shift_or {
    int solve(const char *s,const char *t) {
        int code[256] = {0},n = 0;
        for(;t[n];n++) {
            code[(int)t[n]] |= (1 << n);
        }
        for(int i = 0;i < 256;i++) {
            code[i] = ~code[i];
        }
        int p = 0;
        for(int i = 0;s[i];i++) {
            p = (p << 1) | code[(int)s[i]];
            if((p & (1 << (n - 1))) == 0) return i - n + 1;
        }
        return -1;
    }
}

int main() {
    char s[100],t[100];
    while(scanf("%s%s",s,t) != EOF) {
        TEST(Shift_or,s,t);
    }
    return 0;
}