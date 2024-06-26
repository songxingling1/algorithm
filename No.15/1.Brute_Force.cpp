#include <bits/stdc++.h>
#define TEST(namesp,s,t) {                                      \
    printf("%s(%s,%s) = %d\n",#namesp,s,t,namesp::solve(s,t));           \
}
using namespace std;
namespace Brute_Force {
    int solve(const char *s,const char *t) {
        for(int i = 0;s[i];i++) {
            int flag = 1;
            for(int j = 0;t[j];j++) {
                if(s[i + j] == t[j]) continue;
                flag = 0;
                break;
            }
            if(flag) {
                return i;
            }
        }
        return -1;
    }
}
int main() {
    char s[100],t[100];
    while(scanf("%s%s",s,t) != EOF) {
        TEST(Brute_Force,s,t);
    }
    return 0;
}