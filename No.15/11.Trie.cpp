#include <bits/stdc++.h>
using namespace std;
#define MAX_N 10000
#define BASE 26
int rt[MAX_N + 5] = {0};
int ch[MAX_N * 30][BASE] = {};
int val[MAX_N * 30] = {0};
int ch_cnt = 0;
void insert(int o,int lst,const char *s) {
    for(int i = 0;s[i];i++) {
        int ind = (int)s[i] - 'a';
        ch[o][ind] = ++ch_cnt;
        for(int j = 0;j < BASE;j++) {
            if(ch[o][j]) continue;
            ch[o][j] = ch[lst][j];
        }
        o = ch[o][ind];
        lst = ch[lst][ind];
        val[o] = val[lst];
    }
    val[o] += 1;
}
int find_once(int a,const char *s) {
    int p = rt[a];
    for(int i = 0;s[i];i++) {
        p = ch[p][(int)s[i] - 'a'];
    }
    return val[p];
}
int query(int a,int b,const char *s) {
    int x1 = find_once(b,s);
    int x2 = find_once(a - 1,s);
    return x1 - x2;
}
int main() {
    int n;
    char s[100];
    scanf("%d",&n);
    for(int i = 1;i <= n;i++) {
        scanf("%s",s);
        rt[i] = ++ch_cnt;
        insert(rt[i],rt[i - 1],s);
    }
    int a,b;
    while(scanf("%d%d%s",&a,&b,s) != EOF) {
        printf("from %d to %d, find %s : %d\n",
               a,b,s,query(a,b,s));
    }
    return 0;
}