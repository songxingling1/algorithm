#include <bits/stdc++.h>
#define MAX_N 240
using namespace std;
char str[MAX_N + 5];
int nxt[MAX_N + 5];
int pre[MAX_N + 5];
int cnt,len;
void del() {
    int p = nxt[0];
    while(true) {
        if(str[p] <= str[nxt[p]]) {
            p = nxt[p];
            continue;
        }
        nxt[pre[p]] = nxt[p];
        pre[nxt[p]] = pre[p];
        len--;
        break;
    }
    while(len > 1 && str[nxt[0]] == '0') {
        nxt[0] = nxt[nxt[0]];
        pre[nxt[0]] = 0;
    }
}
int main() {
    scanf("%s",str + 1);
    len = strlen(str + 1);
    scanf("%d",&cnt);
    for(int i = 0;i <= len;i++) {
        nxt[i] = i + 1;
        pre[i + 1] = i;
    }
    for(int i = 1;i <= cnt;i++) {
        del();
    }
    for(int p = nxt[0];str[p] != '\0';p = nxt[p]) {
        printf("%c",str[p]);
    }
    puts("");
    return 0;
}