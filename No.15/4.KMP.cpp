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
namespace Sunday {
    int solve(const char *s,const char *t) {
        int n = strlen(t),len[256] = {0},nn = strlen(s);
        for(int i = 0;i < 256;i++) len[i] = n + 1;
        for(int i = 0;i < n;i++) len[static_cast<int>(t[i])] = n - i;
        for(int i = 0;i + n <= nn;i += len[static_cast<int>(s[i + n])]) {
            int flag = 1;
            for(int j = 0;t[j];j++) {
                if(s[i + j] == t[j]) continue;
                flag = 0;
                break;
            }
            if(flag) return i;
        }
        return -1;
    }
}
namespace Boyer_Moore {
    int *getDelta1(const char *t) {
        int *delta1 = new int[256];
        for(int i = 0;i < 256;i++) delta1[i] = -1;
        for(int i = 0;t[i];i++){
            delta1[static_cast<int>(t[i])] = i;
        }
        return delta1;
    }
    int *getSuffixes(const char *t) {
        int tlen = strlen(t);
        int *suff = new int[tlen];
        suff[tlen - 1] = tlen;
        for(int i = 0;i < tlen - 1;i++) {
            int j = 0;
            while(j <= i && t[tlen - j - 1] == t[i - j]) ++j;
            suff[i] = j;
        }
        return suff;
    }
    int *getDelta2(const char *t) {
        int *suff = getSuffixes(t);
        int tlen = strlen(t),lastInd = tlen - 1;
        int *delta2 = new int[tlen];
        for(int i = 0;t[i];i++) delta2[i] = tlen;
        for(int i = 0;i < tlen;i++) {
            if(suff[i] != i + 1) continue;
            for(int j = 0;j <= lastInd - suff[i];j++) {
                delta2[j] = lastInd - i;
            }
        }
        for(int i = 0;i < lastInd;i++) {
            delta2[lastInd - suff[i]] = lastInd - i;
        }
        return delta2;
    }
    int solve(const char *s,const char *t) {
        int *delta1 = getDelta1(t);
        int *delta2 = getDelta2(t);
        int slen = strlen(s),tlen = strlen(t);
        for(int j = 0;j + tlen <= slen;) {
            int i = tlen - 1;
            while(i >= 0 && t[i] == s[j + i]) i--;
            if(i == -1) return j;
            j += max(i - delta1[static_cast<int>(s[j + i])],delta2[i]);
        }
        return -1;
    }
}
namespace KMP {
    int *getNext(const char *t) {
        int tlen = strlen(t);
        int *next = new int[tlen];
        next[0] = -1;
        for(int i = 1;i < tlen;i++) {
            int j = next[i - 1];
            while(1) {
                if(t[i] == t[j + 1]) {
                    next[i] = j + 1;
                    break;
                }
                if(j == -1) {
                    next[i] = -1;
                    break;
                }
                j = next[j];
            }
        }
        return next;
    }
    int solve(const char *s,const char *t) {
        int *next = getNext(t);
        int tlen = strlen(t);
        int j = -1;
        for(int i = 0;s[i];i++) {
            while(j != -1 && s[i] != t[j + 1]) j = next[j];
            if(s[i] == t[j + 1]) j++;
            if(t[j + 1] == '\0') return i - tlen + 1;
        }
        return -1;
    }
}
int main() {
    char s[100],t[100];
    while(scanf("%s%s",s,t) != EOF) {
        TEST(Brute_Force,s,t);
        TEST(Sunday,s,t);
        TEST(Boyer_Moore,s,t);
        TEST(KMP,s,t);
    }
    return 0;
}